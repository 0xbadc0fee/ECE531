## ECE531 / Daemon

-------------------------------------------------------------------------------
  * [x] Requires (2) files: log_timed binary & S80sampled startup script
  * [x] Test first on x86, but will output to syslog, doesn't write to /var/log/messages
  * [x] S80sampled must have DAEMON_NAME set to correct binary
  * [x] when x86 test passes; recompile for ARM, see ARM makefile
  * [x] move ARM compiled version of binary to QEMU host (scp -P 2222 sgc@localhost:~/)
  * [x] from ~/ copy binary (log_timed) to /usr/sbin/
  * [x] check persmissions and executable bit, use 'ls -lah' to compare to others, should be same, may need to chown and chgrp
  * [x] move S80sampled from x86 to QEMU ARM host (scp -P 2222 sgc@localhost:~/)
  * [x] from ~/ copy startup script (S80sampled) to /etc/init.d/ 
  * [x] check permission of startup script and ensure matching 
  * [x] manually test run ./S80sampled {start|stop|restart}, should write to /var/log/messages 
  * [x] if test OK, logout of QEMU, reboot, and log back in; confirm startup message in /var/log/messages
