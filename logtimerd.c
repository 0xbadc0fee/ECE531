/*************************
 * _               _
 *| |             | |
 *| |__   __ _  __| |
 *| '_ \ / _` |/ _` |
 *| |_) | (_| | (_| |
 *|_.__/ \__,_|\__,_|
 *      _____  __
 *     |  _  |/ _|
 *  ___| |/' | |_ ___  ___
 * / __|  /| |  _/ _ \/ _ \
 *| (__\ |_/ / ||  __/  __/
 * \___|\___/|_| \___|\___|
 *
 ************************/

/*
 *Simple daemon to write to syslog once per sec.
 -[x] set up signal handling function (_signal_handler)
 -[ ] set up task function (_do_work)
 -[ ] set up main to test pid status...
 -[ ] set up main to receive signals from sig handler
 -[ ] set up main to run task (_do_work) if no earlier errors
 -[ ] log errors if the above fails.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/signal.h>
#include <sys/stat.h>
#include <syslog.h>


#define true 1

enum error_type{OK=0, ERR_CHDIR, ERR_DISABLE_PRINT, ERR_FORK, ERR_NO_LOG_FILE, ERR_SAVE_VAR, ERR_SETSID, ERR_TIME, ERR_USLEEP, ERR_WTF};

#define DAEMON_NAME "logtimerd"
#define ERROR_FORMAT "Recieved errno: %s"
#define ERROR_TIME_FORMAT "Recieved time errno %s"
#define ERROR_USLEEP_FORMAT "Recieved usleep errno %s"
#define LOG_FILE_NAME "/var/log/messages"

//FUNCTION _signal_handler
/*
  -[ ] set up case switch for inputs SIGHUP (user disconnect) & SIGTERM (defaul terminate)
  -[ ] write desired log messages to log file
  -[ ] anticipate unexpected signal & post message if captured
  -[ ] close log, assuming already opened via MAIN
 */
static void _signal_handler(const int signal)
{
  switch(signal)
    {
    case SIGHUP:
      break;
    case SIGTERM:
      syslog(LOG_INFO, "msg SIGTERM, exit");
      closelog();
      exit(OK);
      break;
    default:
      syslog(LOG_INFO, "unhandled signal");
    }
}

//FUNCTION _do_work
/*
 -[ ] initialize time
 -[ ] setup constant running loop (infinte)
 -[ ] setup check for time elapsed = max
 -[ ] do actions 'while' max time has not yet elapsed
 -[ ] check if return time is valid
 -[ ] save current time to previous time
 -[ ] log current time
 */
static void _do_work(void)
{
  time_t sec, prev_sec;
  sec = time(NULL);
  prev_sec = sec;

  syslog(LOG_INFO, "Time since Epoch = %ld\n\n", sec);

for(int i=0; true; i++)
  {
    if(usleep(999000) !=0){
      syslog(LOG_ERR, ERROR_USLEEP_FORMAT, strerror(errno));
      exit(ERR_USLEEP);
    }

    sec = time (NULL);

    if((sec < prev_sec) || (sec > prev_sec+1)){
      syslog(LOG_ERR, ERROR_TIME_FORMAT, strerror(errno));
      exit(ERR_TIME);
    }

    while(sec < (prev_sec+1)){
      if(usleep(1000) != 0){
        syslog(LOG_ERR, ERROR_USLEEP_FORMAT, strerror(errno));
        exit(ERR_USLEEP);
      }

      sec = time(NULL);
      if((sec < prev_sec) || (sec > prev_sec+1)){
        syslog(LOG_ERR, ERROR_TIME_FORMAT, strerror(errno));
        exit(ERR_TIME);
      }

    }
    prev_sec = sec;
    if(prev_sec != sec){
      syslog(LOG_ERR, ERROR_FORMAT, strerror(errno));
      exit(ERR_SAVE_VAR);
    }

    syslog(LOG_INFO, "Time = %ld\n", sec);
  }

}

//MAIN setup
/*
 -[x] Open log file (136)
 -[x] write initial msg to log file (137)
 - TEST PID:
   -[x] fork to new child process (138)
   -[x] confirm fork success (141)
   -[x] call pid, if still parent, exit (146)
   -[x] if not parent, start new session (150)
 -[x] disable print (155)
 -[x] set permissions [umask] (160)
 -[ ] set directory [chdir]
 -[ ] test if log file exists
 -[ ] pipe sysem signals to internal signal handler (_signal_handler)
 -[ ] do intended tasks / objectives (_do_work)
 -[ ] (close log file, already done in signal handler...)
 */
int main(void)
{
  openlog(DAEMON_NAME, LOG_PID | LOG_NDELAY | LOG_NOWAIT, LOG_DAEMON);
  syslog(LOG_INFO, "Starting logtimerd\n\n");

  pid_t pid=fork();

  if(pid<0){
    syslog(LOG_ERR, ERROR_FORMAT, strerror(errno));
    return ERR_FORK;
  }

  if(pid>0){
    return OK;
  }

  if(setsid() < -1){
    syslog(LOG_ERR, ERROR_FORMAT, strerror(errno));
    return ERR_SETSID;
  }

  if((close(STDIN_FILENO) !=0) || (close(STDOUT_FILENO) !=0) || (close(STDERR_FILENO) != 0)){
    syslog(LOG_ERR, ERROR_FORMAT, strerror(errno));
    return ERR_DISABLE_PRINT;
  }

  umask(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

  if(chdir("/")<0){
    syslog(LOG_ERR, ERROR_FORMAT, strerror(errno));
    return ERR_CHDIR;
  }

  if(access(LOG_FILE_NAME, F_OK) != 0){
    syslog(LOG_ERR, ERROR_FORMAT, strerror(errno));
    return ERR_NO_LOG_FILE;
  }

  signal(SIGTERM, _signal_handler);
  signal(SIGHUP, _signal_handler);

  _do_work();

  return ERR_WTF; //main crashed

}
