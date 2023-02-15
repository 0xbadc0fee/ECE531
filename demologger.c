#include <stdio.h>
#include <stdlib.h> /*for exit function*/
#include <unistd.h> /*for get user id*/

/*for debugging only, remove user id before deploy*/
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

void logger(char *msg, char *src, int line);

int main(){

/*	printf("File: %s\n", __FILE__);
	printf("Date: %s\n", __DATE__);
	printf("Time: %s\n", __TIME__);
	printf("Line: %d\n", __LINE__);
	printf("ANSI: %d\n", __STDC__);
*/
	int curruid;
	curruid=getuid();
//	char user[1000] = {0};
	logger("task 1 done", __FILE__, __LINE__);
//	snprintf(user, "%i\n", curruid);
	printf("getuid user id: %i\n", curruid);

	struct stat statbuf;
	struct passwd *pwd;

	if ((pwd = getpwuid(statbuf.st_uid)) != NULL){
		printf("PWD user %-8.8s\n", pwd->pw_name);
		logger(("pwd usr: %-8.8s\n", pwd->pw_name),__FILE__, __LINE__); 
	}
		else{
		printf("Status User %-8d\n", statbuf.st_uid);
	}
	return 0;

}

void logger(char *msg, char *src, int line)
{
	/*Create pointer to typedef struct of FILE type*/
	FILE *file;
        
	/*Open a file named log.txt in append mode*/
	file = fopen("log.txt", "a");

	/*If unable to open file, exit w/ status (1) */
	if (file == NULL)
	{
		printf("Error opening log file");
		exit(1);
	}

	/*Write desired message(s) to log file*/
	fprintf(file, "%s:%d:%s\n", src, line, msg);

	/*Close access to file*/
	fclose(file);
}
