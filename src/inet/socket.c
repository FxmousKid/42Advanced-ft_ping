/**
 * @file socket.c
 * @brief socket related files
 * @ingroup 
 *
 * @author Iyan Nazarian
 * @date 2025-08-17
 * @version v0.1.0-3-g410a714
 *
 * @details
 *  Contains socket related functions : get_socket(),...
 */

#include <netinet/in.h>
#include <sys/socket.h>
#include "ft_ping.h"

int	close(int fd);

/**
 * @brief creates the socket via socket(2) and returns it, if already created
 * returns same (static) value
 *
 * @details altough it returns a valid socket fd, closing that fd should be
 * done by atexit(3) upon calling exit(2)
 *
 * @return valid socket fd on success, exits on failure
 */
int	get_socket_icmp(void)
{
	static int sockfd = 0;

	if (!sockfd)
		sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

	if (sockfd < 0) {
		log_event(LOG_ERROR, get_logfile(), 1, "socket() failed, ret = %d", sockfd);
		fatal_error("Failed to create socket");
	}
	
	return sockfd;
}

void	close_socket_icmp(void)
{
	close(get_socket_icmp());
}
