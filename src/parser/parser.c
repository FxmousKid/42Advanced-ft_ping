/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:21:34 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/02 18:26:44 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/* switch case gets called for each argument, so each case statement should
 * properly 'exit' the function (break, return, *no* exit)
 * doesn't exit.
 * */

static 
bool opts_handle(struct option *lopts, int lopts_idx, char *argv[],
	         struct s_ping *data, int opt)
{
	(void) lopts_idx;
	(void) lopts;

	switch (opt) {
	case '?':
		// to distinguish between '-?' option and 
		// getopt_long() returning '?' as a unknown opt
		if (ft_strncmp(argv[optind - 1], "-?", 2)) {
			data->exit_code = EXIT_BAD_ARGS;
			MORE_INFO_MSG(data->progname);
			return false;
		}
		__attribute__ ((fallthrough)); // fallthrough
	case 'h':
		print_help(data->progname);
		return false;
	case 'V':
		printf(VERSION);
		return false;	
	case 'v':
		data->is_verbose = true;
		break;
	}	
	return true;
}

/* Parsing should not allocate anything, since it can exit
 * */

bool
parse_cli(int argc, char *argv[], struct s_ping *data)
{
	if (!argv || !*argv)
		return FUNC_FAILURE;

	int	opt;
	char	*sopts = "+vV?";
	int	lopts_idx = 0;
	struct option lopts[] = {
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'V'},
		{NULL, 0, NULL, 0}
	};

	opt = getopt_long(argc, argv, sopts, lopts, &lopts_idx);
	while (opt != -1) {
		if (!opts_handle(lopts, lopts_idx, argv, data, opt))
			exit(data->exit_code);
		opt = getopt_long(argc, argv, sopts, lopts, &lopts_idx);
	}
	if (!argv[optind]) {
		ARG_MISSING(data->progname);
		MORE_INFO_MSG(argv[0]);
		exit(EXIT_BAD_ARGS);
	}

	// the first non option argument is the [HOST]
	// further arguments are ignored
	data->host = argv[optind];
	return FUNC_SUCCESS;
}
