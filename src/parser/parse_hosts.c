#include "ft_ping.h"
#include <regex.h>
#include <getopt.h>
#include <stdlib.h>

bool	parse_hosts(struct s_ping *data, char *argv[])
{
	(void) argv;
	(void) data;

	regex_t	ip_regex;
	if (regcomp(&ip_regex, IPV4_REGEX, REG_EXTENDED)) {
		log_error("Failed to create regex", get_logfile());
		return false;
	}
	/* doing stuff with regex */
	regfree(&ip_regex);



	// struct s_hosts *hosts;
	// if (!(hosts = calloc(sizeof(struct s_hosts), 1)))
		
	return true;
}
