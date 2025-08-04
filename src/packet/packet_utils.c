/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:44:05 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/04 14:00:39 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

struct s_icmp_packet make_packet(struct s_ping *data)
{
	(void)data;

	static int seq_number = 0;

	struct s_icmp_packet packet = {
		.type = ICMP_TYPE_ECHO_REQUEST,
		.code = ICMP_CODE_ECHO_REQUEST,
		.seq_number = seq_number++,
		.identifier = 0,
		.checksum = 0,
	};

	return packet;
}
