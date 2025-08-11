#include "ft_ping.h"
#include <stdlib.h>

struct s_hosts	*get_hosts(void)
{
	static struct s_hosts *hosts = NULL;

	if (!hosts)
		hosts = calloc(1, sizeof(struct s_hosts));

	if (!hosts) {
		log_strerror("Failed to create hosts", get_logfile());
		fatal_strerror("Failed to create hosts");
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
