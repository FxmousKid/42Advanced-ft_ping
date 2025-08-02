/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:55:48 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/02 13:06:53 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h> // IWYU pragma: keep
# include <stdlib.h> // IWYU pragma: keep
# include <stdbool.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <getopt.h>
# include <string.h> // IWYU pragma: keep
# include "../libft/includes/libft.h" // IWYU pragma: keep

# include "ANSI-colors.h"

# define EXIT_SUCCESS	0
# define EXIT_NO_RPL	1
# define EXIT_OTHER		2
# define EXIT_BAD_ARGS	64

# define FUNC_SUCCESS 1
# define FUNC_FAILURE 0

# define ARG_CNT_BAD	RED "[FATAL] Bad Argument count\n" WHT
# define ARG_INVALID	RED "[FATAL] Invalid arguments\n" WHT

# define ARG_MISSING(name)			fprintf(stderr, "%s: missing host operator.\n", (name))
# define OPT_SHORT_INV(name,opt) 	fprintf(stderr, "%s: invalid option -- '%s'\n", (name), (opt))
# define OPT_LONG_INV(name,opt)		fprintf(stderr, "%s: unrecognized option -- '%s'\n", (name), (opt))
# define MORE_INFO_MSG(name)		fprintf(stderr, "Try '%s --help' for more information.\n", (name))

# define VERSION "\
ft_ping 1.0\n\
No Copyright (C) 2025 inazaria.\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n\n\
Written by Iyan Nazarian.\n\
"

struct s_ping {
	const char	*progname;
	bool		is_verbose;
	short		exit_code;
	char		*host;
};

bool	parse_cli(int argc, char *argv[], struct s_ping *data);
void	print_help(const char *progname);

#endif
