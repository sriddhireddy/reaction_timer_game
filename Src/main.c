#include "gpio_driver.h"
#include "uart_driver.h"
#include "systick_driver.h"
#include "random.h"
#include "game.h"

int main(void)
{
	GPIO_Init();
	UART_Init();
	SysTick_Init();
	Random_Init(1234);

	Game_Init();

    while(1)
    {
//    	if(GPIO_ReadButton()){
//    		GPIO_LED_On();
//    	}
//    	else GPIO_LED_Off();

//    	GPIO_LED_Toggle();
//    	for(volatile int i=0;i<1000000;i++){}

//    	UART_WriteString("Hello\r\n");

//    	uint32_t value = Random_Generate();
//    	UART_WriteUInt(value);
//    	UART_WriteString("\r\n");
//        SysTick_DelayMs(1000);

    	Game_Update();

    }
}
