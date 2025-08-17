/**
 * @file packet_utils.c
 * @brief utilities for packet (ICMP)
 * @ingroup
 *
 * @author Iyan Nazarian
 * @date 2025-08-17
 * @version v0.1.0-6-g4412147
 *
 * @details
 *  Contains functions related to packets (ICMP)
 */

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
