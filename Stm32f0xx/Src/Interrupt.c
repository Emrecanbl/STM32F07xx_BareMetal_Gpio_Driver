#include <stdint.h>
#include <Stm32f0xx.h>
#include <STM32F0XX_GPIO_driver.h>

void delay(uint8_t Value)
{
	for(uint32_t i = 0 ; i < Value ; i ++);
}
int main(void)
{
	GPIO_Handle_t GpioLed , GpioBtn;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNummer = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_Mode_OUT  ;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_FAST   ;
	GpioLed.GPIO_PinConfig.GPIO_PinOpType = GPIO_OP_TYPR_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	//GpioLed.GPIO_PinConfig.GPIO_PinOpType = GPIO_OP_TYPR_OD; //OPEN DRAIN MODE
	//GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU; //PULL-UP RESİSTOR
	GpioBtn.pGPIOx = GPIOC;
	GpioBtn.GPIO_PinConfig.GPIO_PinNummer = GPIO_PIN_NO_13;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_Mode_IT_FT;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OP_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_IRQITConfig(IRQ_No_EXTI4_15,ENABLE);
	GPIO_IRQPrıorityConfig(IRQ_No_EXTI4_15,15);
	//GPIO_IRQPrıorityConfig(IRQ_No_EXTI4_15,15);

	GPIO_periperalclockControl(GPIOA,ENABLE);
	GPIO_periperalclockControl(GPIOC,ENABLE);
	GPIO_Inıt(&GpioLed);
	GPIO_Inıt(&GpioBtn);
	GpioLed.pGPIOx = GPIOA;
	GpioBtn.pGPIOx = GPIOC;

	while(1)
		{


		}
}

void EXTI4_15_IRQHandler(void){

	GPIO_IRQHandling(GPIO_PIN_NO_13 );
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);

}
