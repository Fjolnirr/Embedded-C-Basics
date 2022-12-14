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

void delay(uint32_t);

int main(void)
{
	//Address pointer definitions
	uint32_t *pPDClkCtrlReg = (uint32_t *)0x40023830;
	uint32_t *pPDModeReg = (uint32_t *)0x40020C00;
	uint32_t *pPDOutReg = (uint32_t *)0x40020C14;

	//1. Enable AHB1ENR clock for GPIOD peripheral
	*pPDClkCtrlReg |= (1 << 3); // Enable clock for PD

	//2. Set GPIOD MODE to output for PD12
	*pPDModeReg &= ~(0xC0000000 >> 6); //clearing
	*pPDModeReg |= (0x80000000 >> 7); //setting

   /* Loop forever */
	for(;;){
		//3. Write GPIOD Output register HIGH for PD12
		*pPDOutReg |= (1 << 12); //HIGH to PD12 led4
		delay(300000);
		//4. Write GPIOD Output register LOW for PD12
		*pPDOutReg &= ~(1 << 12); //LOW to PD12 led4
		delay(300000);
	}
}

void delay(uint32_t time){
	for( ; time > 0; time--);
}
