#include "ft_ping.h"

void print_help(const char *progname) {
	printf("\
Usage: %s [OPTION...] HOST ...\n\
Send ICMP ECHO_REQUEST packets to network hosts.\n\
\n\
Options valid for all request types:\n\
\n\
 -c, --count=NUMBER	stop after sending NUMBER packets\n\
\n\
 -?, --help		give this help list\n\
 -V, --version		print version information\n\
\n\
Mandatory or optional arguments to long options are also mandatory or optional\n\
for any corresponding short options.\n\
\n\
Options marked with (root only) are available only to superuser.\n\
\n\
Report bugs on https://www.github.com/FxmousKid/42Advanced-ft_ping\n\
\
", progname);
}

void print_info(struct s_ping *data)
{

	const int pad_width = 10;
	struct s_hosts *hosts = data->hosts;

	printf("%s=========== STATS ===========%s\n", YEL, WHT);

	// "%-*s" will left-align text in a field of width 'pad_width'
	printf("%s%-*s%s%s\n", YEL, pad_width, "Program:", WHT, data->progname);

	printf("%s%-*s%s", YEL, pad_width, "Hosts:", WHT);
	while (hosts) {
		printf("%s%s", hosts->host, hosts->next ? ", " : "");
		hosts = hosts->next;
	}
	printf("\n");

	printf("%s%-*s%s%d\n", YEL, pad_width, "Socket:", WHT, data->socket);
	printf("%s%-*s%s%s\n", YEL, pad_width, "Verbose:", WHT,
		data->is_verbose ? "enabled" : "disabled");
	printf("%s%-*s%s%d\n", YEL, pad_width, "Count:", WHT, data->count_max);

	printf("%s=============================%s\n", YEL, WHT);
	fflush(stdout);
}
