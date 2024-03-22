/*
 * 02Buton_Led.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Emrec
 */

#include <stdint.h>
#include <Stm32f0xx.h>


#define Buton_pressed 0

void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}

int main(void)
{	//PA5 Led Config
	GPIO_Handle_t GpioLed ,GpioBtn ;
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNummer = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_Mode_OUT  ;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_FAST   ;
	GpioLed.GPIO_PinConfig.GPIO_PinOpType = GPIO_OP_TYPR_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	//GpioLed.GPIO_PinConfig.GPIO_PinOpType = GPIO_OP_TYPR_OD; //OPEN DRAIN MODE
	//GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU; //PULL-UP RESİSTOR

	//Pc13 Button Config
	GpioBtn.pGPIOx = GPIOC;
	GpioBtn.GPIO_PinConfig.GPIO_PinNummer = GPIO_PIN_NO_13;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_Mode_In  ;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_FAST   ;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;



	GPIO_periperalclockControl(GPIOA,ENABLE);
	GPIO_periperalclockControl(GPIOC,ENABLE);
	GPIO_Inıt(&GpioLed);
	GPIO_Inıt(&GpioBtn);
	GpioLed.pGPIOx = GPIOA;
	GpioBtn.pGPIOx = GPIOC;
	while(1)
	{		uint8_t val = GPIO_ReadfrominputPin(GPIOC, GPIO_PIN_NO_13) ;
			if (val == Buton_pressed)
			{
				GPIO_WritetoOutputPin(GPIOA,GPIO_PIN_NO_5,0);
			}
			else
			{
				GPIO_WritetoOutputPin(GPIOA,GPIO_PIN_NO_5,1);
			}

		}
}

