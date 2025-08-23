#include "ft_ping.h"

void print_help(const char *progname) {
	printf("\
Usage: %s [OPTION...] HOST ...\n\
Send ICMP ECHO_REQUEST packets to network hosts.\n\
\n\
Options valid for all request types:\n\
\n\
 -c, --count=NUMBER	stop after sending NUMBER packets\n\
 -i, --interval=NUMBER	wait NUMBER seconds between sending each packet\n\
\n\
 -?, --help		give this help list\n\
 -V, --version		print version information\n\
 -d, --debug		print parsing debug information after parsing hosts, then exits\n\
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

void	print_info(FILE *file, struct s_ping *data)
{

	const int pad_width = 10;
	struct s_hosts *hosts = data->hosts;

	fprintf(file, "%s=========== STATS ===========%s\n", YEL, WHT);

	// "%-*s" will left-align text in a field of width 'pad_width'
	fprintf(file, "%s%-*s%s%s\n", YEL, pad_width, "Program:", WHT, data->progname);

	fprintf(file, "%s%-*s%s", YEL, pad_width, "Hosts:", WHT);
	while (hosts) {
		fprintf(file, "%s%s", hosts->name, hosts->next ? ", " : "");
		hosts = hosts->next;
	}
	fprintf(file, "\n");

	fprintf(file, "%s%-*s%s%d\n", YEL, pad_width, "Socket:", WHT, data->socket);
	fprintf(file, "%s%-*s%s%s\n", YEL, pad_width, "Verbose:", WHT,
		data->is_verbose ? "enabled" : "disabled");
	fprintf(file, "%s%-*s%s%d\n", YEL, pad_width, "Count:", WHT, data->count_max);
	fprintf(file, "%s%-*s%s%d\n", YEL, pad_width, "Interval:", WHT, (int)data->interval.tv_sec);

	fprintf(file, "%s=============================%s\n", YEL, WHT);
	fflush(file);
}

void print_hosts_info(FILE *file, struct s_hosts *hosts) {
    const int pad_width = 15;
    int max_host_len = 0;

    // First pass: find longest host name
    struct s_hosts *tmp = hosts;
    while (tmp) {
        int len = strlen(tmp->name);
        if (len > max_host_len) max_host_len = len;
        tmp = tmp->next;
    }

    // Width for the "========== host =========="
    int total_width = max_host_len + 14;

    while (hosts) {
        // First line: aligned =
        int left_eq = (total_width - (int)strlen(hosts->name)) / 2;
        int right_eq = total_width - left_eq - (int)strlen(hosts->name);
        fprintf(file, "%s%.*s %s%s%s %.*s%s\n", 
               YEL, left_eq, "==============================", 
               BLU, hosts->name, YEL, 
               right_eq, "==============================", WHT);

        // Align the labels like in print_info
        fprintf(file, "%s%-*s%s%d\n", YEL, pad_width, "sent:", WHT, hosts->stats.sent);
        fprintf(file, "%s%-*s%s%d\n", YEL, pad_width, "received:", WHT, hosts->stats.received);
        fprintf(file, "%s%-*s%s%d\n", YEL, pad_width, "lost:", WHT, hosts->stats.lost);
        fprintf(file, "%s%-*s%s%.2f ms\n", YEL, pad_width, "avg_time:", WHT, hosts->stats.avg_time);
        fprintf(file, "%s%-*s%s%.2f ms\n", YEL, pad_width, "min_time:", WHT, hosts->stats.min_time);
        fprintf(file, "%s%-*s%s%.2f ms\n", YEL, pad_width, "max_time:", WHT, hosts->stats.max_time);
        fprintf(file, "%s%-*s%s%.2f ms\n", YEL, pad_width, "stddev_time:", WHT, hosts->stats.stddev_time);
        fprintf(file, "%s%-*s%s%zu\n", YEL, pad_width, "host idx:", WHT, hosts->host_idx);

        // Last line: same width as top
        fprintf(file, "%s%.*s%s\n", YEL, total_width + 2, "==============================", WHT);
        fprintf(file, "\n");

        hosts = hosts->next;
    }
}
