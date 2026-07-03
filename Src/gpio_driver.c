#include "gpio_driver.h"

#define GPIOAEN			(1U<<0)
#define GPIOCEN			(1U<<2)
#define LED_PIN			(1U<<5) //usermanual: pa5 is led
#define BTN_PIN			(1U<<13) //um: pc13 is button


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
	return (GPIOC->IDR & BTN_PIN) ? 0:1;
}
