#include "defines.h"
#include "ft_ping.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include LIBFT_PATH

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

	int count = 0;
	switch (opt) {

	case 'c':
		if (!optarg || (count = atoi(optarg)) <= 0) {
			log_error("-c expects a count >= 0", get_logfile());
			data->exit_code = EXIT_BAD_ARGS;
			MORE_INFO_MSG(data->progname)
			return false;
		}
		data->count_max = count;
		break;

	case '?':
		// to distinguish between '-?' option and 
		// getopt_long() returning '?' as a unknown opt
		if (ft_strncmp(argv[optind - 1], "-?", 2)) {
			data->exit_code = EXIT_BAD_ARGS;
			MORE_INFO_MSG(data->progname)
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


void parse_cli(int argc, char *argv[], struct s_ping *data)
{
	int	opt;
	char	*sopts = "vV?c:";
	int	lopts_idx = 0;

	struct option lopts[] = {
		{"help", no_argument, NULL, 'h'},
		{"count", required_argument, NULL, 'c'},
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

	// all non option arguments are considered hosts
	// and should there be all parsed
	if (!parse_hosts(data, argv))
		log_fatal("Failed to parse hosts", get_logfile());
}
