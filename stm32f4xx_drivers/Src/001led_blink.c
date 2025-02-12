/*
 * main.c
 *
 *  Created on: Feb 9, 2025
 *      Author: Rambo
 */

#include "stm32f4xx.h"
#include "stm32f407xx_gpio_driver.h"
//#include<stdint.h>
//#include <stdio.h>

//#define RCC_ADD				0x40023800UL
//#define RCC_AHB1ENR			(RCC_ADD + 0x30UL)
//#define RCC_CFGR			(RCC_ADD + 0x08UL)
//#define GPIOD_BASEADDR		0x40020C00UL
//#define GPIOD_MODE			(GPIOD_BASEADDR + 0x00)
//#define GPIOD_SPEED			(GPIOD_BASEADDR + 0x08)
//#define GPIOD_OTYPE			(GPIOD_BASEADDR + 0x04)
//#define GPIOD_PUPD			(GPIOD_BASEADDR + 0x0C)
//#define GPIOD_ODR			(GPIOD_BASEADDR + 0x14)
//#define __vo				volatile

void delay(void)
{
    for(uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
    GPIO_Handle_t GpioLed, ButtonLed;

    GpioLed.pGPIOx = GPIOD;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLed);

    while(1)
    {
        GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
        delay();
    }

    return 0;
}
