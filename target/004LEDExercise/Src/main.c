/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

int main(void)
{
	//Address pointer definitions
	uint32_t *pPDClkCtrlReg = (uint32_t *)0x40023830;
	uint32_t *pPDModeReg = (uint32_t *)0x40020C00;
	uint32_t *pPDOutReg = (uint32_t *)0x40020C14;

	/*
	//1. Enable AHB1ENR clock for GPIOD peripheral

//	uint32_t temp = *pDClkCtrlReg; 	//Read
//	temp |= 0x08; 					//Modify
//	*pPDClkCtrlReg = temp; 			//Set-Write

	*pPDClkCtrlReg |= 0x08; //All-in-One

	//2. Set GPIOD MODE to output for PD12
	*pPDModeReg &= ~0x03000000; // clearing 25th and 24th bits
	*pPDModeReg |= 0x01000000; //setting of 25th and 24th bits as 01

	//3. Write GPIOD Output register HIGH for PD12
	*pPDOutReg |= 0x00001000;
*/

	//Alternate versions of masking using shift operators
	//1. Enable AHB1ENR clock for GPIOD peripheral
	*pPDClkCtrlReg |= 1 << 3; // Enable clock for PD

	//2. Set GPIOD MODE to output for PD12
	*pPDModeReg &= ~(3 << 24); //clearing
	*pPDModeReg |= (1 << 24); //setting

	//3. Write GPIOD Output register HIGH for PD12
	*pPDOutReg |= 1 << 12; //HIGH to PD12 led4

    /* Loop forever */
	for(;;);
}
