/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hosts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:47:25 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/05 21:07:33 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include <regex.h>
#include <getopt.h>

bool parse_hosts(struct s_ping *data, char *argv[])
{
	regex_t	regex;
	if (regcomp(&regex, IPV4_REGEX, REG_EXTENDED)) {
		log_error("Failed to create regex", get_logfile());
		return false;
	}

	data->host = argv[optind];
	return true;
}
