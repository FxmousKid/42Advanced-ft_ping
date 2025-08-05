#include <netinet/in.h>
#include <sys/socket.h>
#include "ft_ping.h"

bool	inet_setup(struct s_ping *data)
{
	data->socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (!data->socket) {
		
		return false;
	}
	return true;
}
