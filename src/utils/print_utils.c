/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:05:38 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/05 21:48:42 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_info(struct s_ping *data)
{
	printf("%s=========== STATS ===========%s\n", YEL, WHT);
	printf("%sProgram: %s%s\n", YEL, data->progname, WHT);
	// printf("%sHost:    %s%s\n", YEL, data->host ? data->host : "unknown", WHT);
	printf("%sSocket:  %s%d%s\n", YEL, WHT, data->socket, WHT);
	printf("%sVerbose: %s%s\n", YEL, data->is_verbose ? "enabled" : "disabled", WHT);
	printf("%scount:   %d%s\n", YEL, data->count_max, WHT);
	printf("%s=============================%s\n", YEL, WHT);
	fflush(stdout);
}
