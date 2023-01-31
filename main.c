#include "stm32f4xx.h"
#include "CLOCK.h"
#include "GPIO.h"
#include "SYS_INIT.h"
#include "USART.h"

void GPIO_config(void){

	RCC->AHB1ENR |= (1<<0);
	GPIOA->MODER |= (1<<14);
	
	GPIOA->OTYPER = 0;
	GPIOA->OSPEEDR = 0;
}
void delay(uint32_t time)
{
	while(time--);
}
int main(void)
{
	initClock();
	sysInit();
	
	GPIO_InitTypeDef x;
	
	GPIO_Init(GPIOA, &x);
	
	while(1)
	{
		GPIOA->BSRR |= (1<<7);
		GPIO_WritePin(GPIOA, 7, GPIO_PIN_RESET);
		ms_delay(1000);
		GPIO_WritePin(GPIOA, 7, GPIO_PIN_SET);
		ms_delay(1000);
	}
	
}
