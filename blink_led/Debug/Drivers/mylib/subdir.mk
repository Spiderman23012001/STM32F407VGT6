################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/mylib/Button.c 

OBJS += \
./Drivers/mylib/Button.o 

C_DEPS += \
./Drivers/mylib/Button.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/mylib/%.o Drivers/mylib/%.su Drivers/mylib/%.cyclo: ../Drivers/mylib/%.c Drivers/mylib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Rambo/Desktop/stm32/blink_led/mylib/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-mylib

clean-Drivers-2f-mylib:
	-$(RM) ./Drivers/mylib/Button.cyclo ./Drivers/mylib/Button.d ./Drivers/mylib/Button.o ./Drivers/mylib/Button.su

.PHONY: clean-Drivers-2f-mylib

