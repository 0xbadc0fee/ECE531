## ECE531 / Daemon

-------------------------------------------------------------------------------
  * [ ] Requires (2) files: log_timed binary & S80sampled startup script
  * [ ] Test first on x86, but will output to syslog, doesn't write to /var/log/messages
  * [x] S80sampled must have DAEMON_NAME set to correct binary
  * [ ] when x86 test passes; recompile for ARM, see ARM makefile
  * [ ] move ARM compiled version of binary to QEMU host (scp -P 2222 sgc@localhost:~/)
  * [ ] from ~/ copy binary (log_timed) to /usr/sbin/
  * [ ] check persmissions and executable bit, use 'ls -lah' to compare to others, should be same, may need to chown and chgrp
  * [ ] move S80sampled from x86 to QEMU ARM host (scp -P 2222 sgc@localhost:~/)
  * [ ] from ~/ copy startup script (S80sampled) to /etc/init.d/ 
  * [ ] check permission of startup script and ensure matching 
  * [ ] manually test run ./S80sampled {start|stop|restart}, should write to /var/log/messages 
  * [ ] if test OK, logout of QEMU, reboot, and log back in; confirm startup message in /var/log/messages
