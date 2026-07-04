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
static uint32_t readyStartTime;
static uint8_t readyStarted = 0;
static uint8_t resultPrinted = 0;

void Game_Init(void){
	currentState = WAIT;
	readyStarted = 0;
	GPIO_LED_Off();
	UART_WriteString("REACTION GAME TIMER\r\n");
	UART_WriteString("Press the button to start!\r\n");
}

void Game_Update(void){
	switch(currentState){
	    case WAIT:
	    	GPIO_LED_Off();
//	    	UART_WriteString("WAIT\r\n");
	    	if(GPIO_ButtonPressed()){
	    		randomDelay = (Random_Generate() % 3001) + 2000; // range desired: 2000-5000 ms [random % (5000-2000+1) -> 0 to 3000. so add 2000
	    		UART_WriteString("Get Ready! Press the button as soon as u see the led turn on!\r\n");
	    		currentState = READY;
	    	}
	        break;

//	    case READY:
//	    	SysTick_DelayMs(randomDelay);
//	    	GPIO_LED_On();
//	    	startTime = SysTick_Millis();
//	    	UART_WriteString("GO!\r\n");
//	    	currentState = GO;
//	        break;

	    case READY:
	    	if(!readyStarted){
	    		readyStartTime = SysTick_Millis();
	    		readyStarted = 1;
	    	}
	    	if(GPIO_ButtonPressed()){
	    		UART_WriteString("Too Early!\r\n");
	    		readyStarted = 0;
	    		currentState = WAIT;
	    		break;
	    	}
	    	if((SysTick_Millis()-readyStartTime) >= randomDelay){
	    		GPIO_LED_On();
	    		startTime = SysTick_Millis();
	    		UART_WriteString("GO!\r\n");
	    		readyStarted = 0;
	    		currentState = GO;
	    	}
	    	break;

	    case GO:
//	    	GPIO_LED_On();
	    	if(GPIO_ButtonPressed()){
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
	    		UART_WriteString("\r\n");
	    		resultPrinted = 1;
	    	}
	    	if(GPIO_ButtonPressed()){
//	    		UART_WriteString("Button detected in RESULT\r\n");
	    		resultPrinted = 0;
	    		reactionTime = 0;
	    		startTime = 0;
	    		endTime = 0;
	    		readyStartTime = 0;
	    		currentState = WAIT;
	    	}
	        break;

	    default:
	        break;
	}

}
