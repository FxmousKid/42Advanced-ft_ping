/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:21:34 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/02 01:34:17 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void print_help(const char *progname) {
	printf("\
Usage: %s [OPTION...] HOST ...\n\
Send ICMP ECHO_REQUEST packets to network hosts.\n\n", progname\
	);
}

// static void
// opt_handle_unknown(const char *progname, const char *invalid_opt)
// {
// 	if (!strncmp(invalid_opt, "--", 2)) {
// 		write(1, "aaa", 3);
// 		OPT_LONG_INV(progname_argv, invalid_opt);
// 		MORE_INFO_MSG(progname);
// 	} else {
// 		printf("awd");
// 		OPT_SHORT_INV(progname_argv, invalid_opt);
// 		MORE_INFO_MSG(progname);
// 	}
// }

static bool
opts_handle(char *argv[], struct s_ping *data, int opt)
{
	(void) argv;

	switch (opt) {
	case '?':
		if (ft_strncmp(argv[optind - 1], "-?", 2)) {
			data->exit_code = EXIT_BAD_ARGS;
			MORE_INFO_MSG(data->progname);
			return (false);
		}
		[[fallthrough]]; // fallthrough
	case 'h':
		print_help(data->progname);
		return (false);
	case 'V':
		printf(VERSION);
		return (false);	
	}
	
	return (true);
}

/* Parsing should not allocate anything, since it can exit
 * */

bool
parse_cli(int argc, char *argv[], struct s_ping *data)
{
	if (!argv || !*argv)
		return (FUNC_FAILURE);

	int		opt;
	char	*shortopts = "+hvV?";
	int		longopt_idx = 0;
	struct option longtopts[] = {
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'V'},
		{NULL, 0, NULL, 0}
	};

	while ((opt = getopt_long(argc, argv, shortopts, longtopts, &longopt_idx)) != -1) {
		if (!opts_handle(argv, data, opt))
			exit(data->exit_code);
	}

	return (FUNC_SUCCESS);
}
