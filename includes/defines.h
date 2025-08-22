#ifndef DEFINES_H
# define DEFINES_H

# include <stdio.h> // IWYU pragma: keep
# include "ANSI-colors.h"

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

// logging
# define LOGFILE_NAME	"logfile.txt"
# define LOG_SUCC	3
# define LOG_EVENT	2
# define LOG_WARN	1
# define LOG_ERROR	0

	

# define VERSION "\
ft_ping 1.0\n\
No Copyright (C) 2025 inazaria.\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n\n\
Written by Iyan Nazarian.\n\
"

// Networking
# define ICMP_HEADER_LEN 8 

# define ICMP_TYPE_ECHO_REQUEST	8
# define ICMP_TYPE_ECHO_REPLY	0

# define ICMP_CODE_ECHO_REQUEST 0
# define ICMP_CODE_ECHO_REPLY   0

# define IPV4_REGEX "[:number:]{3}"

# define PACKET_PAYLOAD "TEST"
# define PACKET_PAYLOAD_SIZE sizeof(PACKET_PAYLOAD)



#endif
