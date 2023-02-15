int main(void) {
	openlog(DAEMON_NAME, LOG-PID | LOG_NDELAY | LOG_NOWAIT, LOG_DAEMON);
	syslog(LOG_INFO, "starting sampled");

	pid_t pid = fork();

	if (pid < 0) {
