/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:57:10 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/04 20:13:48 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H

#include <stdio.h> // IWYU pragma: keep
#include "ANSI-colors.h"

# ifndef LIBFT_PATH
#  define LIBFT_PATH "../libft/includes/libft.h"
# endif

// Errors 
# define EXIT_SUCCESS	0
# define EXIT_NO_RPL	1
# define EXIT_OTHER	2
# define EXIT_BAD_ARGS	64

# define FUNC_SUCCESS 1
# define FUNC_FAILURE 0

# define ARG_MISSING(name)		fprintf(stderr, "%s: missing host operator.\n", (name));
# define OPT_SHORT_INV(name,opt) 	fprintf(stderr, "%s: invalid option -- '%s'\n", (name), (opt));
# define OPT_LONG_INV(name,opt)		fprintf(stderr, "%s: unrecognized option -- '%s'\n", (name), (opt));
# define MORE_INFO_MSG(name)		fprintf(stderr, "Try '%s --help' for more information.\n", (name));

# define LOGFILE_NAME	"logfile.txt"
// # define LOGFILE_NAME	""

	

# define VERSION "\
ft_ping 1.0\n\
No Copyright (C) 2025 inazaria.\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n\n\
Written by Iyan Nazarian.\n\
"

// Networking

# define ICMP_TYPE_ECHO_REQUEST	8
# define ICMP_TYPE_ECHO_REPLY	0

# define ICMP_CODE_ECHO_REQUEST 0
# define ICMP_CODE_ECHO_REPLY 0

# define IPV4_REGEX "[:number:]{3}"

#endif
