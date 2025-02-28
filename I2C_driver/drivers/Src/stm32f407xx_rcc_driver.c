/*
 * stm32f407xx_rcc_driver.c
 *
 *  Created on: Feb 26, 2025
 *      Author: Rambo
 */

#include "stm32f407xx_rcc_driver.h"


uint32_t RCC_getPLLclock(void)
{
	return 0;
}


uint16_t AHB_PreScaler[8] = {2,4,8,16,64,128,256,512};
uint16_t APB1_PreScaler[4] = {2,4,8,16};
uint32_t rcc_getpclk1(void)
{
	uint32_t pclk1, Systemclk;
	uint8_t clksrc, temp, ahbp, apb1p;
	clksrc = (RCC->CFGR >> 2) & 0x3;

	// Source
	if(clksrc == 0)
	{
		Systemclk = 16000000;
	}else if(clksrc == 1)
	{
		Systemclk = 8000000;
	}else if(clksrc == 2)
	{
		Systemclk = RCC_getPLLclock();
	}

	// AHB Prescaler
	temp = ((RCC->CFGR >> 4)&0xF);

	if(temp < 8)
	{
		ahbp = 1;
	}else
	{
		ahbp = AHB_PreScaler[temp - 8];
	}

	// APB1 Prescaler

	temp = ((RCC->CFGR >> 10)&0x7);
	if(temp < 2)
	{
		apb1p = 1;
	}else
	{
		apb1p = APB1_PreScaler[temp - 2];
	}
	pclk1 = ((Systemclk / ahbp) / apb1p);

	return pclk1;

}

uint32_t rcc_getpclk2(void)
{
	uint32_t pclk2, systemclk;
	uint8_t clksrc, temp, ahbp, apb2p;

	clksrc = ((RCC->CFGR) >> 2) & 0x3;

	if(clksrc == 0)
	{
		systemclk = 16000000;
	}else
	{
		systemclk = 8000000;
	}

	temp = ((RCC->CFGR >> 4)& 0xF);
	if(temp < 8)
	{
		ahbp = 1;
	}else
	{
		ahbp = AHB_PreScaler[temp - 8];
	}

	temp = ((RCC->CFGR >> 13)&0x7);
	if(temp < 2)
	{
		apb2p = 1;
	}else
	{
		apb2p = APB1_PreScaler[temp - 8];
	}

	pclk2 = (systemclk/ahbp)/apb2p;

	return pclk2;
}
