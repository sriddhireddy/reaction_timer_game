#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "stm32f4xx.h"

void GPIO_Init(void);
void GPIO_LED_On(void);
void GPIO_LED_Off(void);
void GPIO_LED_Toggle(void);
uint8_t GPIO_ReadButton(void);

#endif /* GPIO_DRIVER_H_ */
