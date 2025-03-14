/*
 * stm32f407xx_gpio.h
 *
 *  Created on: Feb 12, 2025
 *      Author: Rambo
 */

#ifndef INC_STM32F407XX_GPIO_H_
#define INC_STM32F407XX_GPIO_H_

#include "stm32f407xx.h"





/*
 * This is a Configuration structure for a GPIO Pin
 */
typedef struct
{
	uint8_t GPIO_PinNumber;						/*|< Possible values from @GPIO_PIN_NUMBERS >*/
	uint8_t GPIO_PinMode;						/*|< Possible values from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_AltFunMode;
}GPIO_PinConfig_t;

/*
 * This is a Handle structure for a GPIO Pin
 */
typedef struct
{
	GPIO_RegDef_t		*pGPIOx;
	GPIO_PinConfig_t	GPIO_PinConfig;
}GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBERS
 * GPIO Pin numbers
 */
#define GPIO_PIN_NO_0			0
#define GPIO_PIN_NO_1			1
#define GPIO_PIN_NO_2			2
#define GPIO_PIN_NO_3			3
#define GPIO_PIN_NO_4			4
#define GPIO_PIN_NO_5			5
#define GPIO_PIN_NO_6			6
#define GPIO_PIN_NO_7			7
#define GPIO_PIN_NO_8			8
#define GPIO_PIN_NO_9			9
#define GPIO_PIN_NO_10			10
#define GPIO_PIN_NO_11			11
#define GPIO_PIN_NO_12			12
#define GPIO_PIN_NO_13			13
#define GPIO_PIN_NO_14			14
#define GPIO_PIN_NO_15			15

/*
 * @GPIO_PIN_MODES
 * GPIO Pin possible modes
 */
#define GPIO_MODE_IN			0
#define GPIO_MODE_OUT			1
#define GPIO_MODE_ALTFUN		2
#define GPIO_MODE_ANALOG		3
#define GPIO_MODE_IT_FT			4
#define GPIO_MODE_IT_RT			5
#define GPIO_MODE_IT_RFT		6

/*
 * GPIO Pin possible output types
 */
#define GPIO_OP_TYPE_PP			0
#define GPIO_OP_TYPE_OD			1

/*
 * @GPIO_PIN_SPEED
 * GPIO Pin possible output speed
 */
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3

/*
 * GPIO Pin pull up AND pull down configuration macros
 */
#define GPIO_NO_PUPD			0
#define GPIO_PIN_PU				1
#define GPIO_PIN_PD				2

#define GPIO_BASEADDR_TO_CODE(x)		(	(x == GPIOA)?0:\
											(x == GPIOB)?1:\
											(x == GPIOC)?2:\
											(x == GPIOD)?3:\
											(x == GPIOE)?4:\
											(x == GPIOF)?5:\
											(x == GPIOG)?6:\
											(x == GPIOH)?7:0 )

/**************************************************************************************************************************
 * 								APIs supported by this driver
 * 					For more info about the APIs check the function definitions
 * ************************************************************************************************************************
 */

/*
 * Peripheral clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *GPIOx, uint8_t EnOrDi);   //EnOrDi: Enable or Disable


/*
 * Init and De-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data Read and Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 *  IRQ config and ISR Handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);




#endif /* INC_STM32F407XX_GPIO_H_ */
