################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/STM32F0XX_GPIO_driver.c 

OBJS += \
./Driver/Src/STM32F0XX_GPIO_driver.o 

C_DEPS += \
./Driver/Src/STM32F0XX_GPIO_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/%.o Driver/Src/%.su Driver/Src/%.cyclo: ../Driver/Src/%.c Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F072RBTx -DNUCLEO_F072RB -c -I../Inc -I"C:/Users/Emrec/OneDrive/Masaüstü/STM32/Projeler/Stm32_f0xx_Driver/Drivers/Inc" -I"C:/Users/Emrec/STM32CubeIDE/workspace_1.14.1/Stm32f0xx/Driver/Inc" -I"C:/Users/Emrec/STM32CubeIDE/workspace_1.14.1/Stm32f0xx/Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-Src

clean-Driver-2f-Src:
	-$(RM) ./Driver/Src/STM32F0XX_GPIO_driver.cyclo ./Driver/Src/STM32F0XX_GPIO_driver.d ./Driver/Src/STM32F0XX_GPIO_driver.o ./Driver/Src/STM32F0XX_GPIO_driver.su

.PHONY: clean-Driver-2f-Src

