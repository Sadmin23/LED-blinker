#include "stm32f4xx.h"
#include "CLOCK.h"
#include "GPIO.h"
#include "SYS_INIT.h"
#include "USART.h"

int main(void)
{
	initClock();
	sysInit();
	
	GPIO_InitTypeDef z;
	
	z.Alternate=0;
	z.Pull=0;
	z.Speed=0;
	z.Pin=16;
	z.Mode=0;
	
	while(1)
	{
		GPIO_WritePin(GPIOA, 5, GPIO_PIN_RESET);
		ms_delay(1000);
		GPIO_WritePin(GPIOA, 5, GPIO_PIN_SET);
		ms_delay(1000);
	}
	
}
