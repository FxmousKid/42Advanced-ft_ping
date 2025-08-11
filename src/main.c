
/**
 * @file main.c
 * @brief main() file
 * @ingroup 
 *
 * @author Iyan Nazarian
 * @date 2025-08-09
 * @version d637caf
 *
 * @details
 *  this file contains the main function
 */

#include "ft_ping.h"
#include <stdlib.h>
#include <unistd.h>


/**
 * @brief the main ping function, handles everything
 *
 * @param data the main context structure
 */
static void ft_ping(struct s_ping *data)
{
	inet_setup(data);
}

/** @brief GLIBC var that contains the executable name. */
extern const char *__progname;

/**
 * @brief main function of the project
 *
 * @param argc the number of arguments
 * @param argv the contents of each passed CLI args (options, args, ..)
 * @return
 *  @retval 0 on success
 *  @retval 1 Runtime error (DNS, invalid host)
 *  @retval 2 Usage error (bad flags, no args)
 */
int main(int argc, char *argv[])
{
	struct s_ping	data = {.progname = __progname ? __progname : argv[0]};
	
	if (argc < 2) {
		ARG_MISSING(data.progname)
		MORE_INFO_MSG(argv[0])
		exit(EXIT_BAD_ARGS);
	}

	get_logfile(); // Creating logfile -- exits on failure
	atexit(log_close);

	data.hosts = get_hosts(); // allocating 1st host -- exits on failure
	atexit(hosts_free);
	
	parse_cli(argc, argv, &data);
	ft_ping(&data);
	return data.exit_code;
}
