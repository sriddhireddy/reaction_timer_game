#include "gpio_driver.h"
#include "systick_driver.h"

#define GPIOAEN			(1U<<0)
#define GPIOCEN			(1U<<2)
#define LED_PIN			(1U<<5) //usermanual: pa5 is led
#define BTN_PIN			(1U<<13) //um: pc13 is button

#define BUTTON_DEBOUNCE_MS    10U

static uint8_t previousButtonState = 0;

void GPIO_Init(void){
	RCC->AHB1ENR |= (GPIOAEN | GPIOCEN);

	GPIOA->MODER &=~(3U<<10);
	GPIOA->MODER |= (1U<<10);

	GPIOC->MODER &=~(3U<<26);
}

void GPIO_LED_On(void){
	GPIOA->ODR |= LED_PIN;
}

void GPIO_LED_Off(void){
	GPIOA->ODR &= ~LED_PIN;
}

void GPIO_LED_Toggle(void){
	GPIOA->ODR ^= LED_PIN;
}

uint8_t GPIO_ReadButton(void){
	return (GPIOC->IDR & BTN_PIN) ? 0 : 1;
}

uint8_t GPIO_ButtonPressed(void){
	uint8_t currentButtonState = GPIO_ReadButton();
	uint8_t event = 0;
	if(previousButtonState == 0 && currentButtonState == 1){
		SysTick_DelayMs(BUTTON_DEBOUNCE_MS);
		currentButtonState = GPIO_ReadButton();
		if(currentButtonState == 1){
			event = 1;
		}
	}

	//ALTER: uint8_t event = (!previousButtonState && currentButtonState);
	previousButtonState = currentButtonState;
	return event;
}

