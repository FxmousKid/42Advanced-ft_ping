/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:55:48 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/05 13:34:59 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h> // IWYU pragma: keep
// # include <stdlib.h> // IWYU pragma: keep
# include <stdbool.h>
// # include <sys/socket.h>
# include <netinet/in.h>
# include "ANSI-colors.h"
# include "defines.h" // IWYU pragma: keep

struct s_ping {
	const char		*progname;
	bool			is_verbose;
	short			exit_code;
	char			*host;
	int			socket;
	struct sockaddr_in	ip;
	int			count_max;

};

struct s_icmp_packet {
	int8_t		type;
	int8_t		code;
	int16_t		checksum;
	int16_t		identifier;
	int16_t		seq_number;
};

void	parse_cli(int argc, char *argv[], struct s_ping *data);

// Utils
void	print_help(const char *progname);
void	print_info(struct s_ping *data);
void	fatal(const char *msg);
void	fatal_strerror(const char *msg);
void	log_error(const char *msg, FILE *log);

FILE	*get_logfile(void);
void	close_logfile(void);


#endif
