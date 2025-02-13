/*
 * stm32f407xx.h
 *
 *  Created on: Feb 12, 2025
 *      Author: Rambo
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

/*
 *  Include standard lib
 */

#include<stdint.h>
#include <string.h>
#include <stdio.h>
#define __vo volatile


/*
*   Some generic macros
*/
#define ENABLE              1
#define DISABLE             0
#define SET                 ENABLE
#define RESET               DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET

/*
 *  Base address memories
 */

#define FLASH_BASEADDR			0x08000000U
#define SRAM1_BASEADDR			0x20000000U
#define SRAM2_BASEADDR			0x2001C000U
#define ROM_BASEADDR			0x1FFF0000U
#define SRAM_BASEADDR           SRAM1_BASEADDR


/*
 * **************************----Peripheral----*************************
 */

/*
 *  base peripheral register: AHBx, APBx
 */
#define PERIPH_BASE				0x40000000U
#define APB1_BASEADDR			0x40000000U
#define APB2_BASEADDR			0x40010000U
#define AHB1_BASEADDR			0x40020000U
#define AHB2_BASEADDR			0x50000000U

/*
 * Base address of peripherals which are hanging on APB1 bus
 */
#define TIM2_BASEADDR           APB1_BASEADDR
#define TIM3_BASEADDR           (APB1_BASEADDR + 0x0400U)
#define TIM4_BASEADDR           (APB1_BASEADDR + 0x0800U)
#define TIM5_BASEADDR           (APB1_BASEADDR + 0x0C00U)
#define TIM6_BASEADDR           (APB1_BASEADDR + 0x1000U)
#define TIM7_BASEADDR           (APB1_BASEADDR + 0x1400U)
#define TIM12_BASEADDR           (APB1_BASEADDR + 0x1800U)
#define TIM13_BASEADDR           (APB1_BASEADDR + 0x1C00U)
#define TIM14_BASEADDR           (APB1_BASEADDR + 0x2000U)
#define RTC_BKP_BASEADDR           (APB1_BASEADDR + 0x2800U)
#define WWDG_BASEADDR               (APB1_BASEADDR + 0x2C00U)
#define IWDG_BASEADDR               (APB1_BASEADDR + 0x3000U)
#define I2S2ext_BASEADDR               (APB1_BASEADDR + 0x3400U)
#define SPI2_I2S2_BASEADDR               (APB1_BASEADDR + 0x3800U)
#define SPI3_I2S3_BASEADDR               (APB1_BASEADDR + 0x3C00U)
#define I2S3ext_BASEADDR               (APB1_BASEADDR + 0x4000U)
#define USART2_BASEADDR               (APB1_BASEADDR + 0x4400U)
#define USART3_BASEADDR               (APB1_BASEADDR + 0x4800U)
#define UART4_BASEADDR               (APB1_BASEADDR + 0x4C00U)
#define UART5_BASEADDR               (APB1_BASEADDR + 0x5000U)
#define I2C1_BASEADDR               (APB1_BASEADDR + 0x5400U)
#define I2C2_BASEADDR               (APB1_BASEADDR + 0x5800U)
#define I2C3_BASEADDR               (APB1_BASEADDR + 0x5C00U)
#define CAN1_BASEADDR               (APB1_BASEADDR + 0x6400U)
#define CAN2_BASEADDR               (APB1_BASEADDR + 0x6800U)
#define PWR_BASEADDR               (APB1_BASEADDR + 0x7000U)
#define DAC_BASEADDR               (APB1_BASEADDR + 0x7400U)
#define UART7_BASEADDR               (APB1_BASEADDR + 0x7800U)
#define UART8_BASEADDR               (APB1_BASEADDR + 0x7C00U)


/*
 * Base address of peripherals which are hanging on APB2 bus
 */
#define TIM1_BASEADDR               (APB2_BASEADDR + 0x0000U)
#define TIM8_BASEADDR               (APB2_BASEADDR + 0x0400U)
#define USART1_BASEADDR               (APB2_BASEADDR + 0x1000U)
#define USART6_BASEADDR               (APB2_BASEADDR + 0x1400U)
#define ADC1_ADC2_ADC3_BASEADDR               (APB2_BASEADDR + 0x2000U)
#define SDIO_BASEADDR               (APB2_BASEADDR + 0x2C00U)
#define SPI1_BASEADDR               (APB2_BASEADDR + 0x3000U)
#define SPI4_BASEADDR               (APB2_BASEADDR + 0x3400U)
#define SYSCFG_BASEADDR               (APB2_BASEADDR + 0x3800U)
#define EXTI_BASEADDR               (APB2_BASEADDR + 0x3C00U)
#define TIM9_BASEADDR               (APB2_BASEADDR + 0x4000U)
#define TIM10_BASEADDR               (APB2_BASEADDR + 0x4400U)
#define TIM11_BASEADDR               (APB2_BASEADDR + 0x4800U)
#define SPI5_BASEADDR               (APB2_BASEADDR + 0x5000U)
#define SPI6_BASEADDR               (APB2_BASEADDR + 0x5400U)
#define SAI1_BASEADDR               (APB2_BASEADDR + 0x5800U)
#define LCD_TFT_BASEADDR               (APB2_BASEADDR + 0x6800U)

/*
 * Base address of peripherals which are hanging on AHB1 bus
 */
#define GPIOA_BASEADDR               (AHB1_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR               (AHB1_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR               (AHB1_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR               (AHB1_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR               (AHB1_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR               (AHB1_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR               (AHB1_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR               (AHB1_BASEADDR + 0x1C00U)
#define GPIOI_BASEADDR               (AHB1_BASEADDR + 0x2000U)
#define GPIOJ_BASEADDR               (AHB1_BASEADDR + 0x2400U)
#define GPIOk_BASEADDR               (AHB1_BASEADDR + 0x2800U)
#define CRC_BASEADDR               (AHB1_BASEADDR + 0x3000U)
#define RCC_BASEADDR               (AHB1_BASEADDR + 0x3800U)
#define FL_BASEADDR               (AHB1_BASEADDR + 0x3C00U)
#define BKPSRAM_BASEADDR               (AHB1_BASEADDR + 0x4000U)
#define DMA1_BASEADDR               (AHB1_BASEADDR + 0x6000U)
#define DMA2_BASEADDR               (AHB1_BASEADDR + 0x6400U)
#define ETHERNET_BASEADDR               (AHB1_BASEADDR + 0x8000U)
#define DMA2D_BASEADDR               (AHB1_BASEADDR + 0xB000U)
#define USB_OTG_HS1_BASEADDR               0x40040000U

/*
 * Base address of peripherals which are hanging on AHB2 bus
 */
#define USB_OTG_HS2_BASEADDR         AHB2_BASEADDR
#define DCMI_BASEADDR               (AHB2_BASEADDR + 0x50000U)
#define CRYP_BASEADDR               (AHB2_BASEADDR + 0x60000U)
#define HASH_BASEADDR               (AHB2_BASEADDR + 0x60400U)
#define RNG_BASEADDR               (AHB2_BASEADDR + 0x60800U)



 /*
  * ******************************----GPIO----****************************************
  */
/*
 * Peripheral register definition struct for GPIO
 */

typedef struct {
    __vo uint32_t MODER;     // Mode register: định nghĩa chế độ hoạt động của từng chân (Input, Output, AF, Analog)
    __vo uint32_t OTYPER;    // Output type register: định nghĩa kiểu xuất (Push-Pull hoặc Open-Drain)
    __vo uint32_t OSPEEDR;   // Output speed register: cấu hình tốc độ chuyển đổi tín hiệu (slew rate)
    __vo uint32_t PUPDR;     // Pull-up/Pull-down register: kích hoạt điện trở pull-up hoặc pull-down
    __vo uint32_t IDR;       // Input data register: đọc giá trị của các chân GPIO
    __vo uint32_t ODR;       // Output data register: ghi giá trị để điều khiển các chân GPIO
    __vo uint32_t BSRR;      // Bit set/reset register: dùng để thay đổi trạng thái chân
    __vo uint32_t LCKR;
    __vo uint32_t AFR[2];    // Alternate function registers: AFR[0] cho chân 0-7, AFR[1] cho chân 8-15
} GPIO_RegDef_t;

#define GPIOA           ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB           ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC           ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD           ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE           ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF           ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG           ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH           ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI           ((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define GPIOJ           ((GPIO_RegDef_t*)GPIOJ_BASEADDR)
#define GPIOK           ((GPIO_RegDef_t*)GPIOK_BASEADDR)




 /*
  * ******************************----NVIC----****************************************
  */
/*
 * ARM-Cortex Mx Processor NVIC ISERx Register Addresses
 */
#define NVIC_ISER0			((__vo uint32_t*)0xE000E100 )
#define NVIC_ISER1			((__vo uint32_t*)0xE000E104 )
#define NVIC_ISER2			((__vo uint32_t*)0xE000E108 )
#define NVIC_ISER3			((__vo uint32_t*)0xE000E10c )

/*
 * ARM-Cortex Mx Processor NVIC ICERx Register Addresses
 */
#define NVIC_ICER0			((__vo uint32_t*)0XE000E180 )
#define NVIC_ICER1			((__vo uint32_t*)0XE000E184 )
#define NVIC_ICER2			((__vo uint32_t*)0XE000E188 )
#define NVIC_ICER3			((__vo uint32_t*)0XE000E18c )

/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR   ( (__vo uint32_t*)0XE000E400 )
/*
 * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED  4

/*
 * IRQ(Interrupt Request) Numbers of STM32F407x MCU
 * NOTE: Update these macros with valid values according to your MCU
 */
#define IRQ_NO_WWDG                 0   /* Window Watchdog interrupt                                            */
#define IRQ_NO_PVD                  1   /* PVD through EXTI line detection interrupt                            */
#define IRQ_NO_TAMP_STAMP           2   /* Tamper and Time stamp interrupts through EXTI line                   */
#define IRQ_NO_RTC_WKUP             3   /* RTC Wakeup interrupt through EXTI line                               */
#define IRQ_NO_FLASH                4   /* Flash global interrupt                                               */
#define IRQ_NO_RCC                  5   /* RCC global interrupt                                                 */
#define IRQ_NO_EXTI0                6   /* EXTI Line0 interrupt                                                 */
#define IRQ_NO_EXTI1                7   /* EXTI Line1 interrupt                                                 */
#define IRQ_NO_EXTI2                8   /* EXTI Line2 interrupt                                                 */
#define IRQ_NO_EXTI3                9   /* EXTI Line3 interrupt                                                 */
#define IRQ_NO_EXTI4                10  /* EXTI Line4 interrupt                                                 */
#define IRQ_NO_DMA1_STREAM0         11  /* DMA1 Stream0 interrupt                                               */
#define IRQ_NO_DMA1_STREAM1         12  /* DMA1 Stream1 interrupt                                               */
#define IRQ_NO_DMA1_STREAM2         13  /* DMA1 Stream2 interrupt                                               */
#define IRQ_NO_DMA1_STREAM3         14  /* DMA1 Stream3 interrupt                                               */
#define IRQ_NO_DMA1_STREAM4         15  /* DMA1 Stream4 interrupt                                               */
#define IRQ_NO_DMA1_STREAM5         16  /* DMA1 Stream5 interrupt                                               */
#define IRQ_NO_DMA1_STREAM6         17  /* DMA1 Stream6 interrupt                                               */
#define IRQ_NO_ADC                  18  /* ADC1, ADC2 and ADC3 global interrupts                                */
#define IRQ_NO_CAN1_TX              19  /* CAN1 TX interrupts                                                   */
#define IRQ_NO_CAN1_RX0             20  /* CAN1 RX0 interrupts                                                  */
#define IRQ_NO_CAN1_RX1             21  /* CAN1 RX1 interrupts                                                  */
#define IRQ_NO_CAN1_SCE             22  /* CAN1 SCE interrupts                                                  */
#define IRQ_NO_EXTI9_5              23  /* EXTI Line[9:5] interrupts                                            */
#define	IRQ_NO_TIM1_BRK_TIM9        24  /* TIM1 Break interrupt and TIM9 global interrupt                       */
#define	IRQ_NO_TIM1_UP_TIM10        25  /* TIM1 Update interrupt and TIM10 global interrupt                     */
#define IRQ_NO_TIM1_TRG_COM_TIM11   26  /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt   */
#define IRQ_NO_TIM1_CC              27  /* TIM1 Capture Compare interrupt                                       */
#define IRQ_NO_TIM2                 28  /* TIM2 global interrupt                                                */
#define IRQ_NO_TIM3                 29  /* TIM3 global interrupt                                                */
#define IRQ_NO_TIM4                 30  /* TIM4 global interrupt                                                */
#define IRQ_NO_I2C1_EV              31  /* I2C1 event interrupt                                                 */
#define IRQ_NO_I2C1_ER              32  /* I2C1 error interrupt                                                 */
#define IRQ_NO_I2C2_EV              33  /* I2C2 event interrupt                                                 */
#define IRQ_NO_I2C2_ER              34  /* I2C2 error interrupt                                                 */
#define IRQ_NO_SPI1                 35  /* SPI1 global interrupt                                                */
#define IRQ_NO_SPI2                 36  /* SPI2 global interrupt                                                */
#define IRQ_NO_USART1               37  /* USART1 global interrupt                                              */
#define IRQ_NO_USART2               38  /* USART2 global interrupt                                              */
#define IRQ_NO_USART3               39  /* USART3 global interrupt                                              */
#define IRQ_NO_EXTI15_10            40  /* EXTI Line[15:10] interrupts                                          */
#define IRQ_NO_RTC_ALARM            41  /* RTC Alarms (A and B) through EXTI line interrupts                    */
#define IRQ_NO_OTG_FS_WKUP          42  /* USB On-The-Go FS Wakeup through EXTI line interrupt                  */
#define IRQ_NO_TIM8_BRK_TIM12       43  /* TIM8 Break interrupt and TIM12 global interrupt                      */
#define IRQ_NO_TIM8_UP_TIM13        44  /* TIM8 Update and TIM13 global interrupt                               */
#define IRQ_NO_TIM8_TRG_COM_TIM14   45  /* TIM8 Trigger and Commutation interrupts and TIM14 global interrupt   */
#define IRQ_NO_TIM8_CC              46  /* TIM8 Capture Compare interrupt                                       */
#define IRQ_NO_DMA1_STREAM7         47  /* DMA1 Stream7 global interrupt                                        */
#define IRQ_NO_FMC                  48  /* FMC global interrupt                                                 */
#define IRQ_NO_SDIO                 49  /* SDIO global interrupt                                                */
#define IRQ_NO_TIM5                 50  /* TIM5 global interrupt                                                */
#define IRQ_NO_SPI3                 51  /* SPI3 global interrupt                                                */
#define IRQ_NO_UART4                52  /* UART4 global interrupt                                               */
#define IRQ_NO_UART5                53  /* UART5 global interrupt                                               */
#define IRQ_NO_TIM6_DAC             54  /* TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts       */
#define IRQ_NO_TIM7                 55  /* TIM7 global interrupt                                                */
#define IRQ_NO_DMA2_STREAM0         56  /* DMA2 Stream0 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM1         57  /* DMA2 Stream1 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM2         58  /* DMA2 Stream2 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM3         59  /* DMA2 Stream3 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM4         60  /* DMA2 Stream4 global interrupt                                        */
#define IRQ_NO_CAN2_TX              63  /* CAN2 TX interrupts                                                   */
#define IRQ_NO_CAN2_RX0             64  /* CAN2 RX0 interrupts                                                  */
#define IRQ_NO_CAN2_RX1             65  /* CAN2 RX1 interrupts                                                  */
#define IRQ_NO_CAN2_SCE             66  /* CAN2 SCE interrupts                                                  */
#define IRQ_NO_CAN2_OTG             67  /* USB On The Go FS global interrupt                                    */
#define IRQ_NO_DMA2_STREAM5         68  /* DMA2 Stream5 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM6         69  /* DMA2 Stream6 global interrupt                                        */
#define IRQ_NO_DMA2_STREAM7         70  /* DMA2 Stream7 global interrupt                                        */
#define IRQ_NO_USART6               71  /* USART6 global interrupt                                              */
#define IRQ_NO_I2C3_EV              72  /* I2C3 event interrupt                                                 */
#define IRQ_NO_I2C3_ER              73  /* I2C3 error interrupt                                                 */
#define IRQ_NO_OTG_HS_EP1_OUT       74  /* USB On The Go HS End Point 1 Out global interrupt                    */
#define IRQ_NO_OTG_HS_EP1_IN        75  /* USB On The Go HS End Point 1 In global interrupt                     */
#define IRQ_NO_OTG_HS_WKUP          76  /* USB On The Go HS Wakeup through EXTI interrupt                       */
#define IRQ_NO_OTG_HS               77  /* USB On The Go HS global interrupt                                    */
#define IRQ_NO_DCMI                 78  /* DCMI global interrupt                                                */
#define IRQ_NO_FPU                  81  /* FPU global interrupt                                                 */
#define IRQ_NO_SPI4                 84  /* SPI4 global interrupt                                                */
#define IRQ_NO_SAI1                 87  /* SAI1 global interrupt                                                */
#define IRQ_NO_SAI2                 91  /* SAI2 global interrupt                                                */
#define IRQ_NO_QUADSPI              92  /* QuadSPI global interrupt                                             */
#define IRQ_NO_HDMI_CEC             93  /* HDMI-CEC global interrupt                                            */
#define IRQ_NO_SPDIF_RX             94  /* SPDIF-Rx global interrupt                                            */
#define IRQ_NO_FMPI2C1_EV           95  /* FMPI2C1 event interrupt                                              */
#define IRQ_NO_FMPI2C1_ER           96  /* FMPI2C1 error interrupt                                              */

/*
 * Macros for all possible priority levels
 */
#define NVIC_IRQ_PRI0       0
#define NVIC_IRQ_PRI1       1
#define NVIC_IRQ_PRI2       2
#define NVIC_IRQ_PRI3       3
#define NVIC_IRQ_PRI4       4
#define NVIC_IRQ_PRI5       5
#define NVIC_IRQ_PRI6       6
#define NVIC_IRQ_PRI7       7
#define NVIC_IRQ_PRI8       8
#define NVIC_IRQ_PRI9       9
#define NVIC_IRQ_PRI10      10
#define NVIC_IRQ_PRI11      11
#define NVIC_IRQ_PRI12      12
#define NVIC_IRQ_PRI13      13
#define NVIC_IRQ_PRI14      14
#define NVIC_IRQ_PRI15      15


 /*
  * ******************************----EXTI----****************************************
  */

/*
 * Peripheral register definition struct for EXTI
 */
typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;

}EXTI_RegDef_t;
#define EXTI            ((EXTI_RegDef_t*)EXTI_BASEADDR)

/*
 * Peripheral register definition struct for SYSCFG
 */
typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	uint32_t REVERSED[3];
	__vo uint32_t CMPCR;

}SYSCFG_RegDef_t;
#define SYSCFG          ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

 /*
  * ******************************----RCC----****************************************
  */
/*
 * Peripheral register definition struct for RCC
 */

typedef struct {
	__vo uint32_t   CR;
	__vo uint32_t   PLLCFGR;
	__vo uint32_t   CFGR;
	__vo uint32_t   CIR;
	__vo uint32_t   AHB1RSTR;
	__vo uint32_t   AHB2RSTR;
	__vo uint32_t   AHB3RSTR;
	uint32_t        RESERVED0;
	__vo uint32_t   APB1RSTR;
	__vo uint32_t   APB2RSTR;
	uint32_t        RESERVED1[2];
	__vo uint32_t   AHB1ENR;
	__vo uint32_t   AHB2ENR;
	__vo uint32_t   AHB3ENR;
	uint32_t        RESERVED2;
	__vo uint32_t   APB1ENR;
	__vo uint32_t   APB2ENR;
	uint32_t        RESERVED3[2];
	__vo uint32_t   AHB1LPENR;
	__vo uint32_t   AHB2LPENR;
	__vo uint32_t   AHB3LPENR;
	uint32_t        RESERVED4;
	__vo uint32_t   APB1LPENR;
	__vo uint32_t   APB2LPENR;
	uint32_t        RESERVED5[2];
	__vo uint32_t   BDCR;
	__vo uint32_t   CSR;
	uint32_t        RESERVED6[2];
	__vo uint32_t   SSCGR;
	__vo uint32_t   PLLI2SCFGR;

}RCC_RegDef_t;
#define RCC             ((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * Clock enable macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()        (RCC->AHB1ENR	|= (1<<0))
#define GPIOB_PCLK_EN()        (RCC->AHB1ENR	|= (1<<1))
#define GPIOC_PCLK_EN()        (RCC->AHB1ENR	|= (1<<2))
#define GPIOD_PCLK_EN()        (RCC->AHB1ENR	|= (1<<3))
#define GPIOE_PCLK_EN()        (RCC->AHB1ENR	|= (1<<4))
#define GPIOF_PCLK_EN()        (RCC->AHB1ENR	|= (1<<5))
#define GPIOG_PCLK_EN()        (RCC->AHB1ENR	|= (1<<6))
#define GPIOH_PCLK_EN()        (RCC->AHB1ENR	|= (1<<7))
#define GPIOI_PCLK_EN()        (RCC->AHB1ENR	|= (1<<8))

/*
 * Clock enable macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN()           (RCC->APB1ENR	|= (1<<21))
#define I2C2_PCLK_EN()           (RCC->APB1ENR	|= (1<<22))
#define I2C3_PCLK_EN()           (RCC->APB1ENR	|= (1<<23))

/*
 * Clock enable macros for SPIx peripherals
 */
#define SPI1_PCLK_EN()           (RCC->APB2ENR	|= (1<<12))
#define SPI2_PCLK_EN()           (RCC->APB1ENR	|= (1<<14))
#define SPI3_PCLK_EN()           (RCC->APB1ENR	|= (1<<15))

/*
 * Clock enable macros for UARTx peripherals
 */
#define USART1_PCLK_EN()           (RCC->APB2ENR	|= (1<<4))
#define USART6_PCLK_EN()           (RCC->APB2ENR	|= (1<<5))
#define USART2_PCLK_EN()           (RCC->APB1ENR	|= (1<<17))
#define USART3_PCLK_EN()           (RCC->APB1ENR	|= (1<<18))
#define UART4_PCLK_EN()            (RCC->APB1ENR	|= (1<<19))
#define UART5_PCLK_EN()            (RCC->APB1ENR	|= (1<<20))

/*
 * Clock enable macros for SYSCFGx peripherals
 */
#define SYSCFG_PCLK_EN()            (RCC->APB2ENR	|= (1<<14))

/*
* Clock enable macros for TIMx peripherals
*/
#define TIM1_PCLK_EN()           (RCC->APB2ENR	|= (1<<0))
#define TIM2_PCLK_EN()           (RCC->APB1ENR	|= (1<<0))
#define TIM3_PCLK_EN()           (RCC->APB1ENR	|= (1<<1))
#define TIM4_PCLK_EN()           (RCC->APB1ENR	|= (1<<2))
#define TIM5_PCLK_EN()           (RCC->APB1ENR	|= (1<<3))
#define TIM6_PCLK_EN()           (RCC->APB1ENR	|= (1<<4))
#define TIM7_PCLK_EN()           (RCC->APB1ENR	|= (1<<5))
#define TIM8_PCLK_EN()           (RCC->APB2ENR	|= (1<<1))
#define TIM9_PCLK_EN()           (RCC->APB2ENR	|= (1<<16))
#define TIM10_PCLK_EN()           (RCC->APB2ENR	|= (1<<17))
#define TIM11_PCLK_EN()           (RCC->APB2ENR	|= (1<<18))
#define TIM12_PCLK_EN()           (RCC->APB1ENR	|= (1<<6))
#define TIM13_PCLK_EN()           (RCC->APB1ENR	|= (1<<7))
#define TIM14_PCLK_EN()           (RCC->APB1ENR	|= (1<<8))

/*
 * Clock disable macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()        (RCC->AHB1ENR	&= ~(1<<0))
#define GPIOB_PCLK_DI()        (RCC->AHB1ENR	&= ~(1<<1))
#define GPIOC_PCLK_DI()        (RCC->AHB1ENR	&= ~(1<<2))
#define GPIOD_PCLK_DI()        (RCC->AHB1ENR	&= ~(1<<3))
#define GPIOE_PCLK_DI()        (RCC->AHB1ENR	&= ~(1<<4))
#define GPIOF_PCLK_DI()        (RCC->AHB1ENR	&= ~(1<<5))
#define GPIOG_PCLK_DI()        (RCC->AHB1ENR	&= ~(1<<6))
#define GPIOH_PCLK_DI()        (RCC->AHB1ENR	&= ~(1<<7))
#define GPIOI_PCLK_DI()        (RCC->AHB1ENR	&= ~(1<<8))

/*
 * Clock disable macros for I2Cx peripherals
 */
#define I2C1_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<21))
#define I2C2_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<22))
#define I2C3_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<23))

/*
 * Clock disable macros for SPIx peripherals
 */
#define SPI1_PCLK_DI()           (RCC->APB2ENR	&= ~(1<<12))
#define SPI2_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<14))
#define SPI3_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<15))

/*
 * Clock disable macros for UARTx peripherals
 */
#define USART1_PCLK_DI()           (RCC->APB2ENR	&= ~(1<<4))
#define USART6_PCLK_DI()           (RCC->APB2ENR	&= ~(1<<5))
#define USART2_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<17))
#define USART3_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<18))
#define UART4_PCLK_DI()            (RCC->APB1ENR	&= ~(1<<19))
#define UART5_PCLK_DI()            (RCC->APB1ENR	&= ~(1<<20))

/*
 * Clock disable macros for SYSCFGx peripherals
 */
#define SYSCFG_PCLK_DI()            (RCC->APB2ENR	&= ~(1<<14))

/*
* Clock disable macros for TIMx peripherals
*/
#define TIM1_PCLK_DI()           (RCC->APB2ENR	&= ~(1<<0))
#define TIM2_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<0))
#define TIM3_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<1))
#define TIM4_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<2))
#define TIM5_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<3))
#define TIM6_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<4))
#define TIM7_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<5))
#define TIM8_PCLK_DI()           (RCC->APB2ENR	&= ~(1<<1))
#define TIM9_PCLK_DI()           (RCC->APB2ENR	&= ~(1<<16))
#define TIM10_PCLK_DI()           (RCC->APB2ENR	&= ~(1<<17))
#define TIM11_PCLK_DI()           (RCC->APB2ENR	&= ~(1<<18))
#define TIM12_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<6))
#define TIM13_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<7))
#define TIM14_PCLK_DI()           (RCC->APB1ENR	&= ~(1<<8))


/*
*   Macros to reset GPIOx peripherals
*/
#define GPIOA_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()	do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)




















#endif /* INC_STM32F407XX_H_ */
