#include "random.h"

static uint32_t currentSeed = 0;

void Random_Init(uint32_t seed){
	currentSeed = seed;
}

uint32_t Random_Generate(void){
	currentSeed = (1664525 * currentSeed) + 1013904223; //Linear Congruential Generator constants published in Numerical Recipes
	return currentSeed;
}
