/*
 * 002led_button.c
 *
 *  Created on: Feb 9, 2025
 *      Author: Rambo
 */

#include "stm32f4xx.h"
#include "stm32f407xx_gpio_driver.h"


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

    ButtonLed.pGPIOx = GPIOA;
    ButtonLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    ButtonLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    ButtonLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    ButtonLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&ButtonLed);

    while(1)
    {
    	if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))
    	{
    		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
    		delay();
    	}

    }

    return 0;
}
