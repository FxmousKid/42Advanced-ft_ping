/**
 * @file parse_hosts_utils.c
 * @brief utilities for parsing hosts
 * @ingroup parsing
 *
 * @author Iyan Nazarian
 * @date 2025-08-17
 * @version v0.1.0-6-g4412147
 *
 * @details
 *  contains some utilities for parsing hosts (cli args)
 */

#include "ft_ping.h"
#include <stdlib.h>

struct s_hosts	*get_hosts(void)
{
	static struct s_hosts *hosts = NULL;

	if (!hosts)
		hosts = calloc(1, sizeof(struct s_hosts));

	if (!hosts) {
		log_event(LOG_ERROR, get_logfile(), 1, EROR_HOST_ALLOC_FAILED);
		fatal_strerror(EROR_HOST_ALLOC_FAILED);
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
