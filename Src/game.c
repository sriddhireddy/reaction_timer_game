#include "game.h"
#include "uart_driver.h"
#include "gpio_driver.h"
#include "random.h"
#include "systick_driver.h"


typedef enum{
	WAIT,
	READY,
	GO,
	RESULT
} GameState;

static GameState currentState = WAIT;
static uint32_t randomDelay;
static uint32_t startTime;
static uint32_t endTime;
static uint32_t reactionTime;
static uint8_t resultPrinted = 0;

void Game_Init(void){
	currentState = WAIT;
	GPIO_LED_Off();
	UART_WriteString("REACTION GAME TIMER\r\n");
	UART_WriteString("Press the button to start!\r\n");
}

void Game_Update(void){
	switch(currentState){
	    case WAIT:
//	    	GPIO_LED_Off();
	    	if(GPIO_ReadButton()){
	    		randomDelay = (Random_Generate() % 3001) + 2000; // range desired: 2000-5000 ms [random % (5000-2000+1) -> 0 to 3000. so add 2000
	    		UART_WriteString("Get Ready! Press the button as soon as u see the led turn on!\r\n");
	    		currentState = READY;
	    	}
	        break;

	    case READY:
	    	SysTick_DelayMs(randomDelay);
	    	GPIO_LED_On();
	    	startTime = SysTick_Millis();
	    	UART_WriteString("GO!\r\n");
	    	currentState = GO;
	        break;

	    case GO:
//	    	GPIO_LED_On();
	    	if(GPIO_ReadButton()){
	    		endTime = SysTick_Millis();
	    		GPIO_LED_Off();
	    		reactionTime = endTime - startTime;
	    		currentState = RESULT;
	    	}
	        break;

	    case RESULT:
	    	if(!resultPrinted){
	    		UART_WriteString("Your reaction time is: ");
	    		UART_WriteUInt(reactionTime);
	    		UART_WriteString("\r\n");
	    		UART_WriteString("Press button again to play\r\n");
	    		resultPrinted = 1;
	    	}
	    	if(GPIO_ReadButton()){
	    		resultPrinted = 0;
	    		currentState = WAIT;
	    	}
	        break;

	    default:
	        break;
	}

}
