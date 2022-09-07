/*
 * main.c
 *
 *  Created on: 10 Apr 2022
 *      Author: yusuf
 */


#include<stdio.h>
#include<stdint.h>

typedef struct{
	uint32_t crc		:2;
	uint32_t status		:1;
	uint32_t payload	:12;
	uint32_t bat		:3;
	uint32_t sensor		:3;
	uint32_t longAddr	:8;
	uint32_t shortAddr	:2;
	uint32_t addrMode	:1;
}packet_t;

//function defs
void waitKey(void);
void displayPacketElements(packet_t *);

int main(){
	uint32_t val;
	packet_t my_packet;

	printf("Enter the 32-bit package value : ");
	if(scanf("%X", &val) == 0){
		printf("Invalid entry !\n");
	}

	// extract the data from incoming package
	my_packet.crc 	 	= (val & 0x3);
	my_packet.status 	= ((val >> 2) & 0x1);
	my_packet.payload 	= ((val & (0xFFF << 3)) >> 3);
	my_packet.bat 		= ((val >> 15) & 0x7);
	my_packet.sensor	= ((val >> 18) & 0x7);
	my_packet.longAddr  = ((val >> 21) & 0xFF);
	my_packet.shortAddr = ((val >> 29) & 0x3);
	my_packet.addrMode  = ((val >> 31) & 0x1);

	displayPacketElements(&my_packet);
	printf("Size of the Packet Structure is %I64u\n", sizeof(my_packet));

	waitKey();
	return 0;
}

void waitKey(void){
	//Exit Section with wait KEY
	printf("\nPress 'Enter' key to EXIT..");
	while(getchar() != '\n'){};
	getchar();
}

void displayPacketElements(packet_t *pData){
	printf("crc 	  : 0x%X\n", pData->crc);
	printf("status    : 0x%X\n", pData->status);
	printf("payload   : 0x%X\n", pData->payload);
	printf("bat	  : 0x%X\n", pData->bat);
	printf("sensor    : 0x%X\n", pData->sensor);
	printf("longAddr  : 0x%X\n", pData->longAddr);
	printf("shortAddr : 0x%X\n", pData->shortAddr);
	printf("AddrMode  : 0x%X\n", pData->addrMode);
}


