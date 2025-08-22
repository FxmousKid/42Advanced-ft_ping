/**
 * @file logfile.c
 * @brief utilities related to logging
 * @ingroup utils 
 *
 * @author Iyan Nazarian
 * @date 2025-08-11
 * @version v0.1.0-1-g927c91f
 *
 * @details
 *  All functions related to logging
 */

#include "ft_ping.h"
#include <errno.h>
#include <string.h>
#include <stdarg.h>

FILE	*get_logfile(void)
{
	static FILE *logfile = NULL;

	if (!logfile)
		logfile = fopen(LOGFILE_NAME, "w");

	if (!logfile) {
		fatal_strerror("Log file creation");
	}

	return logfile;
}

void	log_close(void) 
{
	fclose(get_logfile());
}

void	log_error(const char *msg, FILE *log)
{
	fprintf(log, "%s[FATAL] %s%s\n", RED, msg, WHT);
}

void	log_success(const char *msg, FILE *log)
{
	fprintf(log, "%s[SUCES] %s%s\n", GRN, msg, WHT);
}

// void	log_event(const char *msg, FILE *log)
// {
// 	fprintf(log, "%s[EVENT] %s%s\n", YEL, msg, WHT);
// }

void	log_strerror(const char *msg, FILE *log)
{
	fprintf(log, "%s[FATAL] %s: %s%s\n", RED, msg, strerror(errno), WHT);
}

_Noreturn
void	log_fatal(const char *msg, FILE *log)
{
	log_error(msg, log);
	fatal_error(msg);
}

void	log_event(int level, FILE *file, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	switch (level) {
	case LOG_SUCC:
		fprintf(file, "%s[SUCES] ", GRN);
		vfprintf(file, fmt, ap);
		fprintf(file, "%s", WHT);
		break;
	case LOG_EVENT:
		fprintf(file, "%s[EVENT] ", WHT);
		vfprintf(file, fmt, ap);
		fprintf(file, "%s", WHT);
		break;
	case LOG_WARN:
		fprintf(file, "%s[WARN ] ", YEL);
		vfprintf(file, fmt, ap);
		fprintf(file, "%s", WHT);
		break;
	case LOG_ERROR:
		fprintf(file, "%s[FATAL] ", RED);
		vfprintf(file, fmt, ap);
		if (errno)
			fprintf(file, ": %s%s", strerror(errno), WHT);
	}
	fprintf(file, "\n");
	fflush(file);
	va_end(ap);	
}
