/**
 * @file parse_hosts.c
 * @brief parses hosts given in argv
 * @ingroup parsing
 *
 * @author Iyan Nazarian
 * @date 2025-08-17
 * @version v0.1.0-6-g4412147
 *
 * @details
 *  contains the parse_hosts() function to parse the host(s) given
 *  via argv
 */

#include "ft_ping.h"
#include <regex.h>
#include <getopt.h>
#include LIBFT_PATH

bool	parse_hosts(struct s_ping *data, char *argv[])
{
	(void) argv;
	(void) data;

	// regex_t	ip_regex;
	// if (regcomp(&ip_regex, IPV4_REGEX, REG_EXTENDED)) {
	// 	log_error("Failed to create regex", get_logfile());
	// 	return false;
	// }
	// /* doing stuff with regex */
	// regfree(&ip_regex);

	struct s_hosts	*hosts = get_hosts();
	char		*host = argv[optind];
	int		tmp = optind;
	
	while ((host = argv[tmp++])) {
		if (ft_strlen(host) <= HOST_NAME_MAX) {
			strcpy(hosts->host, host); 
		} else {
			log_error("Host name is too long", get_logfile());
			return false;
		}
		hosts->host_idx = tmp - optind - 1;
		
		// if hosts are left, to allocate, else do nothing
		if (argv[tmp])
			hosts->next = calloc(1, sizeof(struct s_hosts));
		if (argv[tmp] && !hosts->next) {
			log_strerror("Failed to allocate hosts", get_logfile());
			return (false);
		}
		hosts = hosts->next;
	}
		
	return true;
}
