/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:55:48 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/05 21:55:39 by inazaria         ###   ########.fr       */
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

struct s_hosts {
	char			host[255];
	struct in_addr		ip;
	struct s_hosts		*next;
};

struct s_ping {
	int			socket; // socket fd
	int			count_max; // CLI option -c [count_max]
	bool			is_verbose; // CLI option -v presence or not
	short			exit_code;
	const char		*progname; // for error msgs
	struct s_hosts		*hosts;
};

struct s_icmp_packet {
	int8_t		type;
	int8_t		code;
	int16_t		checksum;
	int16_t		identifier;
	int16_t		seq_number;
};

// Parsing
void		parse_cli(int argc, char *argv[], struct s_ping *data);
bool		parse_hosts(struct s_ping *data, char *argv[]);
struct s_hosts	*get_hosts(void);
void		hosts_free();


// Utils
bool	has_host(struct s_ping *data);

void	print_help(const char *progname);
void	print_info(struct s_ping *data);

void	fatal(const char *msg);
void	fatal_strerror(const char *msg);

FILE	*get_logfile(void);
void	log_error_strerror(const char *msg, FILE *log);
void	log_fatal(const char *msg, FILE *log);
void	log_close(void);
void	log_error(const char *msg, FILE *log);


#endif
