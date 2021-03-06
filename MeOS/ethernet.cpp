#include "ethernet.h"
#include "print_utility.h"
#include "SerialDebugger.h"
#include "i217.h"
#include "ip.h"
#include "arp.h"

extern e1000* nic_dev;

void ether_send(eth_header header)
{
	//e1000_sendPacket();
}

void eth_print_mac(uint8* mac)
{
	for (uint8 i = 0; i < 6; i++)
		printf("%h ", mac[i]);
}

void eth_serial_print_mac(uint8* mac)
{
	for (uint8 i = 0; i < 6; i++)
		serial_printf("%h ", mac[i]);
}

void eth_print(eth_header* header)
{
	printfln("----------------------------------");
	printf("destination mac: ");
	eth_print_mac(header->dest_mac);
	printfln("");

	printf("source mac: ");
	eth_print_mac(header->src_mac);
	printfln("");

	printfln("eth type: %x", header->eth_type);
	printfln("----------------------------------");
}

void eth_serial_print(eth_header* header)
{
	serial_printf("----------------------------------\n");
	serial_printf("destination mac: ");
	eth_serial_print_mac(header->dest_mac);
	serial_printf("\n");

	serial_printf("source mac: ");
	eth_serial_print_mac(header->src_mac);
	serial_printf("\n");

	serial_printf("eth type: %x\n", header->eth_type);
	serial_printf("----------------------------------\n");
}

bool eth_cmp_mac(uint8* mac1, uint8* mac2)
{
	for (uint8 i = 0; i < 6; i++)
		if (mac1[i] != mac2[i])
			return false;

	return true;
}

eth_header* eth_create(sock_buf* buffer, uint8* dest_mac, uint8* src_mac, uint16 eth_type)
{
	eth_header* eth = (eth_header*)buffer->data;

	memcpy(eth->dest_mac, dest_mac, 6);
	memcpy(eth->src_mac, src_mac, 6);

	eth->eth_type = htons(eth_type);
	if(buffer)
	sock_buf_push(buffer, sizeof(eth_header));

	return eth;
}

void eth_send(sock_buf* buffer)
{
	eth_header* eth = (eth_header*)buffer->head;

	if (eth->eth_type == ETH_TYPE_ARP)
		eth_print(eth);

	uint32 packet_size = sock_buf_get_header_len(buffer);
	e1000_send(nic_dev, eth, packet_size /*+ max(0, 60 - packet_size)*/);
}

void eth_recv(sock_buf* buffer)
{
	eth_header* eth = (eth_header*)buffer->data;

	// check if this packet's destination is our pc
	if (eth_cmp_mac(eth->dest_mac, nic_dev->mac) == false && eth_cmp_mac(eth->dest_mac, mac_broadcast) == false)
		return;

	//printf("received ethernet packet. Type is: %h\n", ntohs(eth->eth_type));

	memcpy(buffer->dst_addrs[0].addr, eth->dest_mac, 6);
	memcpy(buffer->src_addrs[0].addr, eth->src_mac, 6);

	uint16 eth_type = ntohs(eth->eth_type);

	sock_buf_push(buffer, sizeof(eth_header));

	/*net_protocol* proto = net_layer_get_proto(NETWORK_LAYER, eth_type);
	if (proto == 0)
	{
		DEBUG("ETHER PROTO NULL");
		return;
	}
	if (proto->ops.recv(buffer) != ERROR_OK)
		printfln("error occured!");*/

	if (eth_type == 0x0806)
		arp_recv(buffer);
}
