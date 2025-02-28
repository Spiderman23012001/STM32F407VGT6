/*
 * stm32f407xx_rcc_driver.h
 *
 *  Created on: Feb 26, 2025
 *      Author: Rambo
 */

#ifndef INC_STM32F407XX_RCC_DRIVER_H_
#define INC_STM32F407XX_RCC_DRIVER_H_

#include "stm32f407xx.h"
#include "stm32f407xx_gpio.h"

uint32_t RCC_getPLLclock(void);
uint32_t rcc_getpclk1(void);
uint32_t rcc_getpclk2(void);

#endif /* INC_STM32F407XX_RCC_DRIVER_H_ */
