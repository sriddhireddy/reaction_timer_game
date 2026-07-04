################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/game.c \
../Src/gpio_driver.c \
../Src/main.c \
../Src/random.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/systick_driver.c \
../Src/uart_driver.c 

OBJS += \
./Src/game.o \
./Src/gpio_driver.o \
./Src/main.o \
./Src/random.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/systick_driver.o \
./Src/uart_driver.o 

C_DEPS += \
./Src/game.d \
./Src/gpio_driver.d \
./Src/main.d \
./Src/random.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/systick_driver.d \
./Src/uart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -Dstm32f446xx -DSTM32F446xx -c -I../Inc -I"D:/reddy/stm32_baremetal/mcu1_projects/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/reddy/stm32_baremetal/mcu1_projects/chip_headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/game.cyclo ./Src/game.d ./Src/game.o ./Src/game.su ./Src/gpio_driver.cyclo ./Src/gpio_driver.d ./Src/gpio_driver.o ./Src/gpio_driver.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/random.cyclo ./Src/random.d ./Src/random.o ./Src/random.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/systick_driver.cyclo ./Src/systick_driver.d ./Src/systick_driver.o ./Src/systick_driver.su ./Src/uart_driver.cyclo ./Src/uart_driver.d ./Src/uart_driver.o ./Src/uart_driver.su

.PHONY: clean-Src

