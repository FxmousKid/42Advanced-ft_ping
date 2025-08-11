/**
 * @file inet_setup.c
 * @brief setup functions for internet comms, like socket, ...
 * @ingroup 
 *
 * @author Iyan Nazarian
 * @date 2025-08-10
 * @version v0.1.0-1-g927c91f
 *
 * @details
 *  Socket creation via the socket(2) syscall 
 */

#include <netinet/in.h>
#include <sys/socket.h>
#include "ft_ping.h"

int	close(int fd);
int	atexit(void (*f)(void));

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
		log_strerror("socket() failed", get_logfile());	
		fatal_error("socket() failed");
	}

	return sockfd;
}

void	close_socket_icmp(void)
{
	close(get_socket_icmp());
}

/**
 * @brief function for setting up internet communications
 *
 * @param data	ptr to main context structure
 *
 * @return
 *  @retval true upon success
 *  @retval false upon failure
 */
bool	inet_setup(struct s_ping *data)
{
	data->socket = get_socket_icmp();
	log_success("Socket created", get_logfile());
	atexit(close_socket_icmp);
	return true;
}
