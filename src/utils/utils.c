#include "ft_ping.h"

int write(int fd, char *buf, size_t len);

bool	has_host(struct s_ping *data)
{
	return (data->hosts != NULL);
}

void	print_debug(struct s_ping *data)
{
	write(1, "\n", 1);
	print_info(stdout, data);
	write(1, "\n", 1);
	print_hosts_info(stdout, data->hosts);
}
