#include "ft_ping.h"
#include <regex.h>
#include <getopt.h>
#include <stdlib.h>

struct s_hosts	*get_hosts(void)
{
	static struct s_hosts *hosts = NULL;

	if (!hosts)
		hosts = calloc(1, sizeof(struct s_hosts));

	if (!hosts) {
		log_error_strerror("Failed to create hosts", get_logfile());
		exit(EXIT_OTHER);	
	}

	return hosts;
}

static void	hosts_free_aux(struct s_hosts *hosts)
{
	struct s_hosts *tmp;

	while (hosts) {
		tmp = hosts->next;
		free(hosts);
		hosts = tmp;
	}
}

void	hosts_free(void)
{
	hosts_free_aux(get_hosts());
}

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
