################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/stm32f407xx_gpio.c \
../drivers/Src/stm32f407xx_i2c.c \
../drivers/Src/stm32f407xx_rcc_driver.c 

OBJS += \
./drivers/Src/stm32f407xx_gpio.o \
./drivers/Src/stm32f407xx_i2c.o \
./drivers/Src/stm32f407xx_rcc_driver.o 

C_DEPS += \
./drivers/Src/stm32f407xx_gpio.d \
./drivers/Src/stm32f407xx_i2c.d \
./drivers/Src/stm32f407xx_rcc_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/%.o drivers/Src/%.su drivers/Src/%.cyclo: ../drivers/Src/%.c drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/Rambo/Desktop/stm32/I2C_driver/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-Src

clean-drivers-2f-Src:
	-$(RM) ./drivers/Src/stm32f407xx_gpio.cyclo ./drivers/Src/stm32f407xx_gpio.d ./drivers/Src/stm32f407xx_gpio.o ./drivers/Src/stm32f407xx_gpio.su ./drivers/Src/stm32f407xx_i2c.cyclo ./drivers/Src/stm32f407xx_i2c.d ./drivers/Src/stm32f407xx_i2c.o ./drivers/Src/stm32f407xx_i2c.su ./drivers/Src/stm32f407xx_rcc_driver.cyclo ./drivers/Src/stm32f407xx_rcc_driver.d ./drivers/Src/stm32f407xx_rcc_driver.o ./drivers/Src/stm32f407xx_rcc_driver.su

.PHONY: clean-drivers-2f-Src

