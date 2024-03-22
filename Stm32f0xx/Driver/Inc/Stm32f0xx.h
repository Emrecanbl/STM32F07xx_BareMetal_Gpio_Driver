/*
 * Stm32f0xx.h
 *
 *  Created on: Mar 14, 2024
 *      Author: EmrecanBL
 */

#ifndef INC_STM32F0XX_H_
#define INC_STM32F0XX_H_

#include <stdint.h>


#define __vo  volatile

/**********************************START:Processor Specific Details **********************************/

/*
 *NVIC ISER and ICER  register Addresses
 */

#define NVIC_ISER                       ((__vo uint32_t*)0xE000E100)
#define NVIC_ICER                       ((__vo uint32_t*)0xE000E180)

/*
 *Priority Register Address and Bits
 */
#define NVIC_PR_BASEADRSS 				((__vo uint32_t*)0xE000E400)
#define NO_PR_BİTS 					5
/*
 * base addresses of Flash and SRAM memories
 */

#define FLASH_BASEADDR 		0x08000000U
#define SRAM1_BASEADDR		0x20000000U
#define ROM_BASEADDR        0x1FFFC800U
#define SRAM 				SRAM1_BASEADDR

/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PRIPH_BASE 			0x40000000U
#define APBPRIPH_BASE		PRIPH_BASE
#define AHB1PRIPH_BASE 		0x40020000U
#define AHB2PRIPH_BASE 		0x48000000U
/*
 * Base addresses of peripherals which are hanging on AHB2 bus
 */

#define GPIOA_BASEADDR 		(AHB2PRIPH_BASE + 0x0000)
#define GPIOB_BASEADDR 		(AHB2PRIPH_BASE + 0x0400)
#define GPIOC_BASEADDR 		(AHB2PRIPH_BASE + 0x0800)
#define GPIOD_BASEADDR 		(AHB2PRIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR 		(AHB2PRIPH_BASE + 0x1000)
#define GPIOF_BASEADDR 		(AHB2PRIPH_BASE + 0x1400)
/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */
#define RCC_BASEADDR 		(AHB1PRIPH_BASE + 0x1000)
/*
 * Base addresses of peripherals which are hanging on APB bus
 */
#define I2C1_BASEADDR 		(APBPRIPH_BASE + 0x5400)
#define I2C2_BASEADDR 		(APBPRIPH_BASE + 0x5800)

#define SPI1_BASEADDR 		(APBPRIPH_BASE + 0x13000)
#define SPI2_BASEADDR 		(APBPRIPH_BASE + 0x3800)

#define USART2_BASEADDR 		(APBPRIPH_BASE + 0x4400)
#define USART3_BASEADDR 		(APBPRIPH_BASE + 0x4800)
#define USART4_BASEADDR 		(APBPRIPH_BASE + 0x4C00)
#define USART5_BASEADDR 		(APBPRIPH_BASE + 0x5000)
#define USART6_BASEADDR 		(APBPRIPH_BASE + 0x1400)
#define USART7_BASEADDR 		(APBPRIPH_BASE + 0x1800)
#define USART8_BASEADDR 		(APBPRIPH_BASE + 0x1C00)
#define USART1_BASEADDR 		(APBPRIPH_BASE + 0x3800)

#define SYSCFG_BASEADDR 		(APBPRIPH_BASE + 0x10000)
#define EXTI_BASEADDR 			(APBPRIPH_BASE + 0x10400)

/**********************************peripheral register definition structures **********************************/
typedef struct
{
	__vo uint32_t MODER;  				 /* GPIO port mode register* offset : 0x00*/
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];				/*!< AFR[0] : GPIO alternate function low register, AF[1] : GPIO alternate function high register */


}GPIO_REGDEF_t;

/*
 * peripheral register definition structure for RCC
 */
typedef struct
{
	__vo uint32_t CR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t CFGR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t CIR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t APB2RSTR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t APB1RSTR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t AHBENR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t APB2ENR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t APB1ENR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t BDCR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t CSR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t AHBRSTR;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t CFGR2;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t CFGR3;					/*!< TODO,  Adress ofset: 0x00*/
	__vo uint32_t CR2;					/*!< TODO,  Adress ofset: 0x00*/

}RCC_REGDEF_t;


/*
 * peripheral register definition structure for EXTI
 */
typedef struct
{
	__vo uint32_t IMR;    /*!< Give a short description,          	  	    Address offset: 0x00 */
	__vo uint32_t EMR;    /*!< TODO,                						Address offset: 0x04 */
	__vo uint32_t RTSR;   /*!< TODO,  									     Address offset: 0x08 */
	__vo uint32_t FTSR;   /*!< TODO, 										Address offset: 0x0C */
	__vo uint32_t SWIER;  /*!< TODO,  									   Address offset: 0x10 */
	__vo uint32_t PR;     /*!< TODO,                   					   Address offset: 0x14 */

}EXTI_RegDef_t;
/*
 * peripheral register definition structure for SYSCONFIG
 */
typedef struct
{
	__vo uint32_t CFGR1;    /*!< Give a short description,          	  	    Address offset: 0x00 */
	__vo uint32_t CFGR1_2;    /*!< TODO,                						Address offset: 0x04 */
	__vo uint32_t EXTICR[4]; /*!< TODO,  									     Address offset: 0x08 */
	__vo uint32_t CFGR2;/*!< TODO,                   					   Address offset: 0x14 */

}SYSCONF_RegDef_t;

/*
 *Peripheral base addresses typecasted to xxx_RegDef_t
 */

#define GPIOA ((GPIO_REGDEF_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_REGDEF_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_REGDEF_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_REGDEF_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_REGDEF_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_REGDEF_t*)GPIOF_BASEADDR)

#define RCC ((RCC_REGDEF_t*)RCC_BASEADDR)
#define EXTI ((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCONF ((SYSCONF_RegDef_t*)SYSCFG_BASEADDR)
#define SPI1 ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2 ((SPI_RegDef_t*)SPI2_BASEADDR)

#define I2C1 ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2 ((I2C_RegDef_t*)I2C2_BASEADDR)

/*
 *Clock enable macros for GPIOS
 */

#define GPIOA_PCLK_EN() (RCC ->AHBENR |= (1<<17))
#define GPIOB_PCLK_EN() (RCC ->AHBENR |= (1<<18))
#define GPIOC_PCLK_EN() (RCC ->AHBENR |= (1<<19))
#define GPIOD_PCLK_EN() (RCC ->AHBENR |= (1<<20))
#define GPIOE_PCLK_EN() (RCC ->AHBENR |= (1<<21))
#define GPIOF_PCLK_EN() (RCC ->AHBENR |= (1<<22))

/*
 *I2CX CLOCK ENABLE
 */
#define I2C1_PCLK_EN() (RCC ->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN() (RCC ->APB1ENR |= (1<<22))
/*
 *SPIX CLOCK ENABLE
 */
#define SPI1_PCLK_EN() (RCC ->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN() (RCC ->APB1ENR |= (1<<14))

/*
 *USART CLOCK ENABLE
 */
#define USART1_PCLK_EN() (RCC ->APB2ENR |= (1<<14)
#define USART2_PCLK_EN() (RCC ->APB1ENR |= (1<<17)
#define USART3_PCLK_EN() (RCC ->APB1ENR |= (1<<18)
#define USART4_PCLK_EN() (RCC ->APB1ENR |= (1<<19)
#define USART5_PCLK_EN() (RCC ->APB1ENR |= (1<<20)
#define USART6_PCLK_EN() (RCC ->APB2ENR |= (1<<5)
#define USART7_PCLK_EN() (RCC ->APB2ENR |= (1<<6)
#define USART8_PCLK_EN() (RCC ->APB2ENR |= (1<<7)

/*
 *SYSCONF CLOCK ENABLE
 */
#define SYSCFG_PCLK_EN() (RCC ->APB2ENR |= (1<<0))
/*
 *GPIO CLOCK DISABLE
 */
#define GPIOA_PCLK_DI() (RCC ->AHBRSTR & ~(0<<17))
#define GPIOB_PCLK_DI() (RCC ->AHBRSTR & ~(0<<18))
#define GPIOC_PCLK_DI() (RCC ->AHBRSTR & ~(0<<19))
#define GPIOD_PCLK_DI() (RCC ->AHBRSTR & ~(0<<20))
#define GPIOE_PCLK_DI() (RCC ->AHBRSTR & ~(0<<21))
#define GPIOF_PCLK_DI() (RCC ->AHBRSTR & ~(0<<22))

/*
 *I2CX CLOCK DISABLE
 */
#define I2C1_PCLK_DI() (RCC ->APB1RSTR & ~(0<<21))
#define I2C2_PCLK_DI() (RCC ->APB1RSTR & ~(0<<22))

/*
 *SPIX CLOCK DISABLE
 */
#define SPI1_PCLK_DI() (RCC ->APB2RSTR & ~(1<<12))
#define SPI2_PCLK_DI() (RCC ->APB1RSTR & ~(1<<14))

/*
 *USART CLOCK DISABLE
 */
#define USART1_PCLK_DI() (RCC ->APB2RSTR  & ~(1<<14)
#define USART2_PCLK_DI() (RCC ->APB1RSTR  & ~(1<<17)
#define USART3_PCLK_DI() (RCC ->APB1RSTR  & ~(1<<18)
#define USART4_PCLK_DI() (RCC ->APB1RSTR  & ~(1<<19)
#define USART5_PCLK_DI() (RCC ->APB1RSTR  & ~(1<<20)
#define USART6_PCLK_DI() (RCC ->APB2RSTR  & ~(1<<5)
#define USART7_PCLK_DI() (RCC ->APB2RSTR  & ~(1<<6)
#define USART8_PCLK_DI() (RCC ->APB2RSTR  & ~(1<<7)


/*
 *GPIOX peripheral Reset Makros
 */
#define GPIOA_REG_RESET()    do{(RCC ->AHBRSTR |= (1<<17));(RCC ->AHBRSTR  &= ~(1<<17));} while(0)
#define GPIOB_REG_RESET()    do{(RCC ->AHBRSTR |= (1<<18));(RCC ->AHBRSTR  &= ~(1<<18));} while(0)
#define GPIOC_REG_RESET()    do{(RCC ->AHBRSTR |= (1<<19));(RCC ->AHBRSTR  &= ~(1<<19));} while(0)
#define GPIOD_REG_RESET()    do{(RCC ->AHBRSTR |= (1<<20));(RCC ->AHBRSTR  &= ~(1<<20));} while(0)
#define GPIOE_REG_RESET()    do{(RCC ->AHBRSTR |= (1<<21));(RCC ->AHBRSTR  &= ~(1<<21));} while(0)
#define GPIOF_REG_RESET()    do{(RCC ->AHBRSTR |= (1<<22));(RCC ->AHBRSTR  &= ~(1<<22));} while(0)
/*
 *GENERIC MAKROS
 */

#define ENABLE 	1
#define DISABLE 0

#define SET 	1
#define RESET 	0

#define GPIO_PIN_SET 	1
#define GPIO_PIN_RESET 	0

#define FLAG_SET		SET
#define FLAG_RESET		RESET

/*
 *EXTICR SELECTOR
 */
#define GPIOBASEADRSS_TO_CODE(x)  ( (x==GPIOA) ? 0:\
									(x==GPIOB) ? 1:\
									(x==GPIOC) ? 2:\
									(x==GPIOD) ? 3:\
									(x==GPIOE) ? 4:\
									(x==GPIOF) ? 5:0)
/*
 *IRQ NUMBER
 */
#define IRQ_No_EXTI0_1   5
#define IRQ_No_EXTI2_3   6
#define IRQ_No_EXTI4_15   7
#define SPI1_No_EXTI4_15   25
#define SPI2_No_EXTI4_15   26

#include <STM32F0XX_GPIO_driver.h>
#endif /* INC_STM32F0XX_H_ */
