/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inet_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:25:34 by inazaria          #+#    #+#             */
/*   Updated: 2025/08/04 16:15:22 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netinet/in.h>
#include <sys/socket.h>
#include "ft_ping.h"

bool	inet_setup(struct s_ping *data)
{
	data->socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (!data->socket) {
		
		return false;
	}
	return true;
}
