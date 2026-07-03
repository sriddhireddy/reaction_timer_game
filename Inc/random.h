#ifndef RANDOM_H_
#define RANDOM_H_

#include "stm32f4xx.h"

void Random_Init(uint32_t seed);
uint32_t Random_Generate(void);

#endif /* RANDOM_H_ */
