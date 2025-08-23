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

/** @brief getpid() function for checksum. */
int	getpid();
/** @brief to copy payload into packet. */
void	*memcpy(void *, const void *, unsigned long);

/**
 * @brief interal function to calculate the checksum
 *
 * @param data 
 * @param len 
 * @return 
 */
static uint16_t inet_checksum_calc(void *data, size_t len)
{
	uint32_t sum = 0;

	const uint8_t *pack = (const uint8_t *)data;
	while (len > 1) {
		sum += (uint16_t)((pack[0] << 8) | pack[1]);
		pack += 2;
		len -= 2;
	}

	if (len == 1)
		sum += (pack[0] << 8);

	while (sum >> 16)
		sum = (sum & 0xffffu) + (sum >> 16);

	return (uint16_t)~sum;
}

/**
 * @brief calculates and sets the checksum field of the given packet
 *
 * @details Calculates the checksum the following way, based on RFC 792 :
 *	- iterating through the whole packet, while one's complement 
 *	summing every 2-byte pair.
 *	- if one byte left, use it as left padding to form a 2-byte word.
 *	and one's complement add it too.
 *	- we stored the sum in a 32 bit int to detect possible carry, and
 *	while it there is carry, we add it over the right side of the 
 *	sum (16 bit side).
 *	- return the one's complement of the whole sum.
 *
 * @param pack the packet to calculate the checksum of
 * @return 
 */
void	checksum(struct s_icmp_packet *pack)
{
	size_t pack_len = ICMP_HEADER_LEN + PACKET_PAYLOAD_SIZE;
	uint16_t csum = inet_checksum_calc(pack, pack_len);
	pack->checksum = csum;
}


/**
 * @brief returns a (correct) constructed ICMP packet based on arguments
 *
 * @param data 
 * @param is_req if true then return correct ECHO_REQUEST packet, else 
 * returns a ECHO_REPLY icmp packet
 *
 * @return a struct s_icmp_packet
 */
struct s_icmp_packet make_packet(struct s_ping *data, bool is_req)
{
	(void)data;
	static int seq_number = 0;

	struct s_icmp_packet packet = {
		.type = is_req ? ICMP_TYPE_ECHO_REQUEST : ICMP_TYPE_ECHO_REPLY,
		.code = is_req ? ICMP_CODE_ECHO_REQUEST : ICMP_CODE_ECHO_REPLY,
		.checksum = 0,
		.identifier = (uint16_t)getpid(),
		.seq_number = seq_number++,
	};
	memcpy(packet.payload, PACKET_PAYLOAD, PACKET_PAYLOAD_SIZE);
	checksum(&packet);

	return packet;
}
