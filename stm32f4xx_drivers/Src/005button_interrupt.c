/*
 * 005button_interrupt.c
 *
 *  Created on: Feb 11, 2025
 *      Author: Rambo
 */

#include <string.h>
#include "stm32f4xx.h"
#include "stm32f407xx_gpio_driver.h"

#define HIGH         1
#define LOW          0
// Với rising trigger, trạng thái nút nhấn được định nghĩa là khi tín hiệu chuyển từ LOW sang HIGH
#define BTN_PRESSED  HIGH

// Hàm delay khoảng 200ms (với hệ thống clock 16MHz)
void delay(void)
{
    for(uint32_t i = 0; i < (500000 ); i++);
}
uint8_t s;
int main(void)
{
    GPIO_Handle_t GpioLed, GPIOBtn;

    // Khởi tạo biến cấu trúc về 0 để tránh giá trị rác
    memset(&GpioLed, 0, sizeof(GpioLed));
    memset(&GPIOBtn, 0, sizeof(GPIOBtn));

    /*------------------------- Cấu hình LED -------------------------*/
    GpioLed.pGPIOx = GPIOD;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber       = GPIO_PIN_NO_12;
    GpioLed.GPIO_PinConfig.GPIO_PinMode         = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed        = GPIO_SPEED_LOW;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType       = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl  = GPIO_NO_PUPD;

    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLed);

    /*------------------------ Cấu hình Button làm ngắt ------------------------*/
    GPIOBtn.pGPIOx = GPIOD;
    GPIOBtn.GPIO_PinConfig.GPIO_PinNumber       = GPIO_PIN_NO_5;
    GPIOBtn.GPIO_PinConfig.GPIO_PinMode         = GPIO_MODE_IT_FT;
    GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed        = GPIO_SPEED_FAST;
    GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl  = GPIO_PIN_PU;

    GPIO_PeriClockControl(GPIOD, ENABLE);

    GPIO_Init(&GPIOBtn);


    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, RESET);

    /*------------------------ Cấu hình NVIC cho ngắt ------------------------*/

    GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, NVIC_IRQ_PRI15);
    GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);

    while(1);

    return 0;
}

/*------------------------ Interrupt Service Routine ------------------------*/
// ISR xử lý ngắt EXTI cho các chân từ 5 đến 9, trong đó PD5 thuộc nhóm này.
void EXTI9_5_IRQHandler(void)
{
    // Xóa cờ pending của ngắt EXTI liên quan đến PD5
    GPIO_IRQHandling(GPIO_PIN_NO_5);
    // Toggle LED nối với PD12
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
//    delay();  // (Có thể thêm delay để debounce nút nhấn)
}
