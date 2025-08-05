#include "ft_ping.h"
#include <stdlib.h>
#include <unistd.h>

static void ft_ping(struct s_ping *data)
{
	write(1, "\n", 1);
	print_info(data);
}


// For proper error handling
extern const char *__progname;

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
