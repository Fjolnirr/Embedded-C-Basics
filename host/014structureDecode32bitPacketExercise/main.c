/*
 * main.c
 *
 *  Created on: 10 Apr 2022
 *      Author: yusuf
 */


#include<stdio.h>
#include<stdint.h>

typedef struct{
	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t longAddr;
	uint8_t shortAddr;
	uint8_t addrMode;
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
	my_packet.crc 	 	= (uint8_t)  (val & 0x3);
	my_packet.status 	= (uint8_t)  ((val >> 2) & 0x1);
	my_packet.payload 	= (uint16_t)((val & (0xFFF << 3)) >> 3);
	my_packet.bat 		= (uint8_t) ((val >> 15) & 0x7);
	my_packet.sensor	= (uint8_t) ((val >> 18) & 0x7);
	my_packet.longAddr  = (uint8_t) ((val >> 21) & 0xFF);
	my_packet.shortAddr = (uint8_t) ((val >> 29) & 0x3);
	my_packet.addrMode  = (uint8_t) ((val >> 31) & 0x1);

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


