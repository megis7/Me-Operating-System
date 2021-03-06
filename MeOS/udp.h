#ifndef UDP_H_19092017
#define UDP_H_19092017

#include "types.h"
#include "net.h"
#include "sock_buf.h"
#include "net_protocol.h"

#pragma pack(push, 1)

struct udp_header
{
	uint16 src_port;			// udp source port (required if sender expects reply)
	uint16 dest_port;			// udp destination port
	uint16 len;					// total length of udp header and data
	uint16 csum;				// udp checksum over the ip header, udp header, udp data

	void* data[];				// upd data
};

#pragma pack(pop, 1)

uint16 udp_checksum(udp_header* header);

// creates a udp header and returns it
udp_header* udp_create(sock_buf* buffer, uint16 src_port, uint16 dest_port, uint16 data_len);

error_t udp_send(sock_buf* buffer);
error_t udp_recv(sock_buf* buffer);

error_t init_udp(uint32 layer);

#endif