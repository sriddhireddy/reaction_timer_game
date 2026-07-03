#include "gpio_driver.h"
#include "uart_driver.h"

int main(void)
{
	GPIO_Init();
	UART_Init();

    while(1)
    {
//    	if(GPIO_ReadButton()){
//    		GPIO_LED_On();
//    	}
//    	else GPIO_LED_Off();

//    	GPIO_LED_Toggle();
//    	for(volatile int i=0;i<1000000;i++){}

    	UART_WriteString("Hello\r\n");

    }
}
