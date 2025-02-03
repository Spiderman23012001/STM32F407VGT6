/*
 * Button.c
 *
 *  Created on: Jan 26, 2025
 *      Author: Rambo
 */

#include "Button.h"

//-----------------var buttton ---------------
uint8_t btn_current = 1;
uint8_t btn_last = 1;
uint8_t btn_filter = 1;
uint8_t debouncing;
uint32_t time_deboune;
uint8_t time_start_press;
uint8_t is_press_timeout;

void hello_v1(uint32_t time_delay)
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	HAL_Delay(time_delay);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_Delay(time_delay);
}
