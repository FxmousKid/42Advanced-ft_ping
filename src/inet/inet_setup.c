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

// #include <netinet/in.h>
// #include <sys/socket.h>
#include "ft_ping.h"

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
	atexit(close_socket_icmp);
	log_event(LOG_SUCC, get_logfile(), 0, "Successfully created socket = %d", data->socket);

	if (!set_socket_options(data)) {
		log_event(LOG_ERROR, 0, get_logfile(), "Failed to set socket options");
		fatal_error("Failed to set socket options");
	}

	return true;
}
