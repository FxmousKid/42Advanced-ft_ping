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
#include <string.h>
#include <stdlib.h>

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
	char		*host_name = argv[optind];
	int		tmp = optind;
	
	while ((host_name = argv[tmp++])) {
		if ((hosts->name = calloc(1, strlen(host_name) + 1))) {
			strcpy(hosts->name, host_name); 
		} else {
			log_event(LOG_ERROR, get_logfile(), 0, 
				EROR_HOST_NAME_ALLOC_FAILED, host_name);
			return false;
		}
		/** @brief remember now that argv is sorted :
		*   prog name - option 1 - ... - option n - arg 1 - ... - arg n - '\0'
		*   and optind is the index of the last option, so tmp - optind - 1 is
		*   the 0-indexed positions of the arguments
		*   . */
		hosts->host_idx = tmp - optind - 1;
		
		// if there are hosts left to parse, then allocate, else do nothing
		if (argv[tmp])
			hosts->next = calloc(1, sizeof(struct s_hosts));
		if (argv[tmp] && !hosts->next) {
			log_event(LOG_ERROR, get_logfile(), 1, EROR_HOST_ALLOC_FAILED);
			return (false);
		}
		hosts = hosts->next;
	}	
	return true;
}
