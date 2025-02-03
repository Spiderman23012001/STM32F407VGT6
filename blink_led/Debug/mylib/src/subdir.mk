################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mylib/src/Button.c 

OBJS += \
./mylib/src/Button.o 

C_DEPS += \
./mylib/src/Button.d 


# Each subdirectory must supply rules for building sources it contributes
mylib/src/%.o mylib/src/%.su mylib/src/%.cyclo: ../mylib/src/%.c mylib/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Rambo/Desktop/stm32/blink_led/mylib/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-mylib-2f-src

clean-mylib-2f-src:
	-$(RM) ./mylib/src/Button.cyclo ./mylib/src/Button.d ./mylib/src/Button.o ./mylib/src/Button.su

.PHONY: clean-mylib-2f-src

