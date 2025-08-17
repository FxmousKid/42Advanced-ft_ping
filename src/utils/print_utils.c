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

size_t strlen(const char *str);

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
	printf("%s%-*s%s%d\n", YEL, pad_width, "Interval:", WHT, data->interval);

	printf("%s=============================%s\n", YEL, WHT);
	fflush(stdout);
}

void print_hosts_info(struct s_hosts *hosts)
{
    const int pad_width = 15;
    int max_host_len = 0;

    // First pass: find longest host name
    struct s_hosts *tmp = hosts;
    while (tmp) {
        int len = strlen(tmp->host);
        if (len > max_host_len) max_host_len = len;
        tmp = tmp->next;
    }

    // Width for the "========== host =========="
    int total_width = max_host_len + 14;

    while (hosts) {
        // First line: aligned =
        int left_eq = (total_width - (int)strlen(hosts->host)) / 2;
        int right_eq = total_width - left_eq - (int)strlen(hosts->host);
        printf("%s%.*s %s%s%s %.*s%s\n", 
               YEL, left_eq, "==============================", 
               BLU, hosts->host, YEL, 
               right_eq, "==============================", WHT);

        // Align the labels like in print_info
        printf("%s%-*s%s%d\n", YEL, pad_width, "sent:", WHT, hosts->stats.sent);
        printf("%s%-*s%s%d\n", YEL, pad_width, "received:", WHT, hosts->stats.received);
        printf("%s%-*s%s%d\n", YEL, pad_width, "lost:", WHT, hosts->stats.lost);
        printf("%s%-*s%s%.2f ms\n", YEL, pad_width, "avg_time:", WHT, hosts->stats.avg_time);
        printf("%s%-*s%s%.2f ms\n", YEL, pad_width, "min_time:", WHT, hosts->stats.min_time);
        printf("%s%-*s%s%.2f ms\n", YEL, pad_width, "max_time:", WHT, hosts->stats.max_time);
        printf("%s%-*s%s%.2f ms\n", YEL, pad_width, "stddev_time:", WHT, hosts->stats.stddev_time);
        printf("%s%-*s%s%zu\n", YEL, pad_width, "host idx:", WHT, hosts->host_idx);

        // Last line: same width as top
        printf("%s%.*s%s\n", YEL, total_width + 2, "==============================", WHT);
        printf("\n");

        hosts = hosts->next;
    }
}
