/**
 * @file parser.c
 * @brief responsible for args and options parsing
 * @ingroup parsing
 *
 * @author Iyan Nazarian
 * @date 2025-08-17
 * @version v0.1.0-6-g4412147
 *
 * @details
 *  responsible for parsing options (short and long) along 
 *  arguments (hosts), order doesn't matter
 */

#include "defines.h"
#include "ft_ping.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include LIBFT_PATH



/**
 * @brief 
 *
 * @param data 
 * @param fmt 
 */
static 
void	opts_error(struct s_ping *data, const char *fmt, ...) 
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	vfprintf(get_logfile(), fmt, ap);
	va_end(ap);
	data->exit_code = EXIT_BAD_ARGS;
}

/**
 * @brief switch case that handles options passed by the user
 *
 * @param lopts structure containing long flags
 * @param lopts_idx index for the long flags
 * @param argv argv from main containing arguments and options (sorted by getopt)
 * @param data main context structure for the project
 * @param opt contains the parsed char by getopt_long()
 *
 * @details handles the options passed by the user via argv\n
 * 2 behaviors can be done after certain scenarios :
 *	- returning false : happens only after a "absolute" option
 *	was called : --version or --help, or if a argument to a
 *	option was invalid : -c 0 or -i 0. when checking the return
 *	of this function, the caller will then exit on false, with the
 *	exit code set by this function, but this function doesn't exit by
 *	itself
 *	- returning true : happens when everything went well and we can
 *	parse the next option
 *
 * @return
 *  @retval true if everything went well
 *  @retval false if you need to stop the execution (--help, --version, 
 *  invalid opt args, ...)
 */

static 
bool opts_handle(struct option *lopts, int lopts_idx, char *argv[],
	         struct s_ping *data, int opt)
{
	(void) lopts_idx;
	(void) lopts;

	int arg = 0;
	switch (opt) {

	case 'c':
		if (!optarg || (arg = atoi(optarg)) <= 0) {
			opts_error(data, "-c expects a count >= 0, got : %d\n", arg);
			return false;
		}
		data->count_max = arg;
		break;

	// Takes NUMBER and waits NUMBER seconds for each ping
	case 'i':
		if (!optarg || (arg = atoi(optarg)) < 0) {
			opts_error(data, "-i expects a number > 0, got : %d\n", arg);
			return false;
		}
		data->interval = arg;
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
	/** @brief contains the short options to parse
	* @details :
	*	-v : set verbose option
	*	-V : shows version then exits
	*	-? : shows help then exits
	*	-c : requires NUMBER arg to send NUMBER packets per host
	*	-i : require NUMBER arg to wait NUMBER seconds for each ping*/
	char	*sopts = "vV?c:i:";
	int	lopts_idx = 0;

	struct option lopts[] = {
		{"help", no_argument, NULL, 'h'},
		{"count", required_argument, NULL, 'c'},
		{"version", no_argument, NULL, 'V'},
		{"interval", required_argument, NULL, 'i'},
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
