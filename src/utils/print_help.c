/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:05:38 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/02 17:52:25 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void print_help(const char *progname) {
	printf("\
Usage: %s [OPTION...] HOST ...\n\
Send ICMP ECHO_REQUEST packets to network hosts.\n\n\
\
 -?, --help			give this help list\n\
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
