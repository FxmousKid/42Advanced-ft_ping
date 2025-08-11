#include "ft_ping.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

_Noreturn
void	fatal(void)
{
	exit(EXIT_OTHER);
}

_Noreturn 
void	fatal_error(const char *msg)
{
	fprintf(stderr, "%s[FATAL] %s%s\n", RED, msg, WHT);
	fatal();
}

_Noreturn
void	fatal_strerror(const char *msg)
{
	fprintf(stderr, "%s[FATAL] %s: %s%s\n", RED, msg, strerror(errno), WHT);
	fatal();
}
