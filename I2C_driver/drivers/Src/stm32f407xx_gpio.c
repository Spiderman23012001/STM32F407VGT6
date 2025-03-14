/*
 * stm32f407xx_gpio.c
 *
 *  Created on: Feb 12, 2025
 *      Author: Rambo
 */

#include "stm32f407xx_gpio.h"

/*
 * Peripheral clock setup
 */

/**
 * @brief  Controls the clock for the GPIO peripheral.
 * @param  pGPIOx: Base address of GPIO (e.g., GPIOA).
 * @param  EnOrDi: ENABLE (1) to turn on, DISABLE (0) to turn off.
 * @retval None.
 * @note   This function must be called before configuring the GPIO registers.
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi)
{
    if(EnOrDi == ENABLE)
    {
    	if(pGPIOx == GPIOA)
    	{
    		GPIOA_PCLK_EN();
    	}else if(pGPIOx == GPIOB)
    	{
    		GPIOB_PCLK_EN();
    	}else if(pGPIOx == GPIOC)
    	{
    		GPIOC_PCLK_EN();
    	}else if(pGPIOx == GPIOD)
    	{
    		GPIOD_PCLK_EN();
    	}else if(pGPIOx == GPIOE)
    	{
    		GPIOE_PCLK_EN();
    	}else if(pGPIOx == GPIOF)
    	{
    		GPIOF_PCLK_EN();
    	}else if(pGPIOx == GPIOG)
    	{
    		GPIOG_PCLK_EN();
    	}else if(pGPIOx == GPIOH)
    	{
    		GPIOH_PCLK_EN();
    	}else if(pGPIOx == GPIOI)
    	{
    		GPIOI_PCLK_EN();
    	}


    }else
    {
        if(pGPIOx == GPIOA)
        {
            GPIOA_PCLK_DI();
        }else if(pGPIOx == GPIOB)
        {
            GPIOB_PCLK_DI();
        }else if(pGPIOx == GPIOC)
        {
            GPIOC_PCLK_DI();
        }else if(pGPIOx == GPIOD)
        {
            GPIOD_PCLK_DI();
        }else if(pGPIOx == GPIOE)
        {
            GPIOE_PCLK_DI();
        }else if(pGPIOx == GPIOF)
        {
            GPIOF_PCLK_DI();
        }else if(pGPIOx == GPIOG)
        {
            GPIOG_PCLK_DI();
        }else if(pGPIOx == GPIOH)
        {
            GPIOH_PCLK_DI();
        }else if(pGPIOx == GPIOI)
        {
            GPIOI_PCLK_DI();
        }

    }
}


/*
 * Init and De-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;

	// enable the peripheral clock
	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);


    //1. config the mode of gpio pin
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
    	// the non interrupt
    	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    	pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    	pGPIOHandle->pGPIOx->MODER |= temp;
    }else
    {
    	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
    	{
    		//1. config the FTSR
    		EXTI->FTSR	|= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    		// Clear the responding RTSR bit
    		EXTI->RTSR	&= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    	}else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
    	{
    		//1. config the RTSR
			EXTI->RTSR	|= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			// Clear the responding RTSR bit
			EXTI->FTSR	&= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    	}else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
    	{
    		//1. config the RTSR and FTSR
			EXTI->RTSR	|= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->FTSR	|= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    	}

    	//2. config the gpio port selection in SYSCFG_EXTICR
    	uint8_t tem1,tem2;
    	tem1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
    	tem2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
    	uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
    	SYSCFG_PCLK_EN();
    	SYSCFG->EXTICR[tem1] = (portcode << (4*tem2));
    	//3. enable the exti interrupt delivery using IMR
    	EXTI->IMR	|=	(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    }
    temp = 0;

    //2. config the speed
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinMode);
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;
    temp = 0;

    //3. config the pupd settings
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinMode);
    pGPIOHandle->pGPIOx->PUPDR |= temp;
    temp = 0;

    //4. config the optype
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (1*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinMode);
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;

    //5. config the alt functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFUN)
	{
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4* temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_AltFunMode << ( 4 * temp2 ));
	}
}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
    if(pGPIOx == GPIOA)
    {
        GPIOA_REG_RESET();
    }
    else if(pGPIOx == GPIOB)
    {
        GPIOB_REG_RESET();
    }
    else if(pGPIOx == GPIOC)
    {
        GPIOC_REG_RESET();
    }
    else if(pGPIOx == GPIOD)
    {
        GPIOD_REG_RESET();
    }
    else if(pGPIOx == GPIOE)
    {
        GPIOE_REG_RESET();
    }
    else if(pGPIOx == GPIOF)
    {
        GPIOF_REG_RESET();
    }
    else if(pGPIOx == GPIOG)
    {
        GPIOG_REG_RESET();
    }
    else if(pGPIOx == GPIOH)
    {
        GPIOH_REG_RESET();
    }
}


/*
 * Data Read and Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (pGPIOx->IDR >> PinNumber) & 0x00000001;
	return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

/*
 *  IRQ config and ISR Handling
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
	{
		if(IRQNumber <= 31) /*0 -> 31*/
		{
			//	program ISER0 register
            *NVIC_ISER0 |= (1 << IRQNumber );
		}else if(IRQNumber > 31 && IRQNumber < 64) /*32 -> 63*/
		{
			//	program ISER1 register
            *NVIC_ISER1 |= (1 << (IRQNumber % 32));
		}else if(IRQNumber >= 64 && IRQNumber < 96)	/*64 -> 95*/
		{
			//	program ISER2 register
            *NVIC_ISER2 |= (1 << (IRQNumber % 64));
		}

	}else
	{
		if(IRQNumber <= 31) /*0 -> 31*/
		{
			//	program ISER0 register
            *NVIC_ICER0 |= (1 << IRQNumber );
		}else if(IRQNumber > 31 && IRQNumber < 64) /*32 -> 63*/
		{
			//	program ISER1 register
            *NVIC_ICER1 |= (1 << (IRQNumber % 32));
		}else if(IRQNumber >= 64 && IRQNumber < 96)	/*64 -> 95*/
		{
			//	program ISER2 register
            *NVIC_ICER2 |= (1 << (IRQNumber % 64));
		}
	}
}
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section = IRQNumber % 4;
	uint8_t shift_amount = (8*iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASE_ADDR + iprx) |= (IRQPriority << shift_amount);
}

void GPIO_IRQHandling(uint8_t PinNumber)
{
    /* Clear the PR register corresponding to pin number */
    if(EXTI->PR & (1 << PinNumber))
    {
        /* Clear pin */
        EXTI->PR |= (1 << PinNumber);
    }
}

