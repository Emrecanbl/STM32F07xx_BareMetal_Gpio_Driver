/*
 * STM32F0XX_GPIO_driver.h
 *
 *  Created on: Mar 14, 2024
 *      Author: EmrecanBL
 */

#ifndef INC_STM32F0XX_GPIO_DRIVER_H_
#define INC_STM32F0XX_GPIO_DRIVER_H_

#include "Stm32f0xx.h"
/*
 *Configuration structure for a GPIO pin
 */
typedef struct
{
	uint8_t GPIO_PinNummer;				/*GPIO_PIN_NUMBERS*/
	uint8_t GPIO_PinMode;  				/*GPIO PIN MODES*/
	uint8_t GPIO_PinSpeed;				/*GPIO PIN SPEED*/
	uint8_t GPIO_PinPuPdControl;		/*GPIO PIN port pull-up/pull-down*/
	uint8_t GPIO_PinOpType;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;


typedef struct
{
	GPIO_REGDEF_t *pGPIOx; 				//This holds the base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig; 	//GPIO pin configuration settings
}GPIO_Handle_t;


/*
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0  				0
#define GPIO_PIN_NO_1  				1
#define GPIO_PIN_NO_2  				2
#define GPIO_PIN_NO_3  				3
#define GPIO_PIN_NO_4  				4
#define GPIO_PIN_NO_5  				5
#define GPIO_PIN_NO_6  				6
#define GPIO_PIN_NO_7  				7
#define GPIO_PIN_NO_8  				8
#define GPIO_PIN_NO_9  				9
#define GPIO_PIN_NO_10  			10
#define GPIO_PIN_NO_11 				11
#define GPIO_PIN_NO_12  			12
#define GPIO_PIN_NO_13 				13
#define GPIO_PIN_NO_14 				14
#define GPIO_PIN_NO_15 				15

/*
 * @GPIO PIN MODES
*/
#define GPIO_Mode_In 		0
#define GPIO_Mode_OUT 		1
#define GPIO_Mode_ALTFEN 	2
#define GPIO_Mode_ANALOG 	3
#define GPIO_Mode_IT_FT		4
#define GPIO_Mode_IT_RT 	5
#define GPIO_Mode_IT_RFT	6
/*
 * @GPIO PIN OUTPUT TYPE MODES
*/
#define GPIO_OP_TYPR_PP     0
#define GPIO_OP_TYPR_OD     1
/*
 * @GPIO PIN OUTPUT SPEEDS
*/
#define GPIO_OP_SPEED_LOW     		0
#define GPIO_OP_SPEED_MEDİUM     	1
#define GPIO_OP_SPEED_FAST     		2
#define GPIO_OP_SPEED_HIGH    		3
/*
 * @GPIO PIN PULL-UP AND PULL-DOWN CONFİGURATİON
*/
#define GPIO_NO_PUPD				0
#define GPIO_PU 					1
#define GPIO_PD 					2

/* Peripheral Clock Setup*/
void GPIO_periperalclockControl(GPIO_REGDEF_t *pGPIOx,uint8_t EnorDi);
/* GPIO INIT DEINIT */
void GPIO_Inıt(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInıt(GPIO_REGDEF_t *pGPIOx);
/*DATA Read And Write*/
uint8_t GPIO_ReadfrominputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadfrominputPort(GPIO_REGDEF_t *pGPIOx);
void GPIO_WritetoOutputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNumber,uint8_t Value);
void GPIO_WritetoOutputPort(GPIO_REGDEF_t *pGPIOx,uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNumber);
/*IRQ and ISR Handle */
void GPIO_IRQITConfig(uint8_t IRQNumber , uint8_t enordı);
void GPIO_IRQPrıorityConfig(uint8_t IRQNumber , uint32_t IRQPriority );
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* INC_STM32F0XX_GPIO_DRIVER_H_ */
