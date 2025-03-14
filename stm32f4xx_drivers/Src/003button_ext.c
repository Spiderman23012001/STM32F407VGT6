/*
 * 003button_ext.c
 *
 *  Created on: Feb 11, 2025
 *      Author: Rambo
 */


#include "stm32f4xx.h"
#include "stm32f407xx_gpio_driver.h"

void delay()
{
	for(uint32_t i = 0;i<500000;i++);
}
uint8_t statusbtn;
uint8_t statusled;
int main(void)
{
	GPIO_Handle_t Gpioled, Gpiobtn;

	memset(&Gpioled, 0, sizeof(Gpioled));
	memset(&Gpiobtn, 0, sizeof(Gpiobtn));

	//led config
	Gpioled.pGPIOx = GPIOD;
	Gpioled.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	Gpioled.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpioled.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Gpioled.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpioled.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&Gpioled);

	//button config
	Gpiobtn.pGPIOx = GPIOD;
	Gpiobtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
	Gpiobtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	Gpiobtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Gpiobtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PD;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&Gpiobtn);

	while(1)
	{
		statusbtn = GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_6);
		statusled = GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_12);
		if(GPIO_ReadFromInputPin(GPIOD, GPIO_PIN_NO_6))
		{
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
			delay();
		}

	}


	return 0;
}
