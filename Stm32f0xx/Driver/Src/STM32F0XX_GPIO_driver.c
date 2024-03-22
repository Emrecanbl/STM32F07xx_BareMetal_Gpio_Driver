/*
 * STM32F0XX_GPIO_driver.c
 *
 *  Created on: Mar 14, 2024
 *      Author: EmrecanBL
 */

//#include "Stm32f0xx.h"
#include "STM32F0XX_GPIO_driver.h"
/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */

/* Peripheral Clock Setup*/
void GPIO_periperalclockControl(GPIO_REGDEF_t *pGPIOx,uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{

		if(pGPIOx == GPIOA){
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB){
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC){
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF){
			GPIOF_PCLK_EN();
		}
	}

	else {
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB){
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC){
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD){
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE){
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOF){
			GPIOF_PCLK_DI();
		}
	}
}
/*********************************************************************
 * @fn      		  - GPIO_Init
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_Inıt(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;	//temp. register

	GPIO_periperalclockControl(pGPIOHandle -> pGPIOx, ENABLE);

		//Configure mode of pin

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_Mode_ANALOG ){

		//non interrup mode

		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer));
		pGPIOHandle->pGPIOx->MODER &= ~( 0x3 << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer));
		pGPIOHandle->pGPIOx->MODER |= temp ;

	}
	else {//interrup mode

			if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_IT_FT)

			{//Fallig edge

				//set FTSR
				EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer);
				//RESET RTSR
				EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer);
			}
			else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_IT_RT	)
			{//Rising edge

				//set FTSR
				EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer);
				//RESET RTSR
				EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer);
			}
			else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_IT_RFT)
			{// SET botH FTSR RTSR
				EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer);
				EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer);
			}
			//EXTİ İNTERRUPT DELİVERY USİNG IMR

			EXTI->IMR |= 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer ;

			//CONFİGURE  GPIO_PORT  SYSCFG_EXTICR

			uint8_t temp1 =pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer/4;
			uint8_t temp2 =pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer%4;
			uint8_t portcode = GPIOBASEADRSS_TO_CODE(pGPIOHandle ->pGPIOx);
			SYSCFG_PCLK_EN();
			SYSCONF->EXTICR[temp1] |= portcode << (temp2 * 4);
	}

	temp = 0;

	//Configure the Speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed <<(2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~( 0x3 << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	temp = 0;
	//Configure the Pull Up Pull Down
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl <<(2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer));
	pGPIOHandle->pGPIOx->PUPDR &= ~( 0x3 << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer));
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp = 0;
	//Configure the optype
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOpType <<(pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer));
	pGPIOHandle->pGPIOx->OTYPER &= ~( 0x1 << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer));
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;
	//Configure the ALT functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_ALTFEN )
	{
		//configure the alt function registers.
		uint8_t temp1 , temp2 ;
		temp1= pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer / 8 ;
		temp2= pGPIOHandle->GPIO_PinConfig.GPIO_PinNummer % 8 ;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << ( 4 * temp2 ) ); //clean
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle-> GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}
/*********************************************************************
* @fn      		  - GPIO_DeInit
* *
* @brief             -
*
* @param[in]         -
* @param[in]         -
* @param[in]         -
*
* @return            -
*
* @Note              -

*/

}
void GPIO_DeInıt(GPIO_REGDEF_t *pGPIOx)
{		if(pGPIOx == GPIOA)
		{
			GPIOA_REG_RESET();
		}else if (pGPIOx == GPIOB)
		{
			GPIOB_REG_RESET();
		}else if (pGPIOx == GPIOC)
		{
			GPIOC_REG_RESET();
		}else if (pGPIOx == GPIOD)
		{
			GPIOD_REG_RESET();
		}else if (pGPIOx == GPIOE)
		{
			GPIOE_REG_RESET();
		}else if (pGPIOx == GPIOF)
		{
			GPIOF_REG_RESET();
		}

}
/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -   0 or 1
 *
 * @Note              -

 */
uint8_t GPIO_ReadfrominputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNumber)
{
	uint8_t value ;
	value = (uint8_t)((pGPIOx -> IDR >> PinNumber) & (0x00000001));
	return value;
}
/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -   0 or 1
 *
 * @Note              -

 */
uint16_t GPIO_ReadfrominputPort(GPIO_REGDEF_t *pGPIOx)
{
		uint16_t value ;
		value = (uint16_t)pGPIOx -> IDR ;
		return value;
}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WritetoOutputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNumber,uint8_t Value)
{
	if(Value == GPIO_PIN_SET )
	{
		pGPIOx->ODR |= (1<<PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1<<PinNumber);
	}
}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WritetoOutputPort(GPIO_REGDEF_t *pGPIOx,uint16_t Value)
{
	pGPIOx->ODR = Value;
}
/*********************************************************************
 * @fn      		  - GPIO_ToggleOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_ToggleOutputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR ^=(1 <<PinNumber);
}
/*********************************************************************
 * @fn      		  - GPIO_IRQITConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQITConfig(uint8_t IRQNumber , uint8_t enordı)
{
	if (enordı==ENABLE)
	{									/*cortex m0 has ony one ISER and normally we need to positions split to ISER */
		*NVIC_ISER |= (1 << IRQNumber);//program ISER0 register
	}
	else {
		*NVIC_ICER   |= (1 << IRQNumber);//program ICER0 register
	}

}
/*********************************************************************
 * @fn      		  - GPIO_IRQPrıorityConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQPrıorityConfig(uint8_t IRQNumber , uint32_t IRQPriority )
{
  uint8_t iprx = IRQNumber/4 ;
  uint8_t iprx_section = IRQNumber%4 ;// the ipr register
  uint8_t Schift_amo = (iprx_section*8)+(8-NO_PR_BİTS);
  *(NVIC_PR_BASEADRSS+iprx) |= (IRQPriority << Schift_amo);
}
/*********************************************************************
 * @fn      		  - GPIO_IRQHandling
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQHandling(uint8_t PinNumber)
{
	if (EXTI->PR & (1<<PinNumber))//clear the exti PR register the pin number
	{
		EXTI->PR |= (1<<PinNumber);
	}
}







