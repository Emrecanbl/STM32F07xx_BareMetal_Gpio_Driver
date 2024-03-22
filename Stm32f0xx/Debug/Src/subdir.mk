################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Interrupt.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/Interrupt.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/Interrupt.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F072RBTx -DNUCLEO_F072RB -c -I../Inc -I"C:/Users/Emrec/OneDrive/Masaüstü/STM32/Projeler/Stm32_f0xx_Driver/Drivers/Inc" -I"C:/Users/Emrec/STM32CubeIDE/workspace_1.14.1/Stm32f0xx/Driver/Inc" -I"C:/Users/Emrec/STM32CubeIDE/workspace_1.14.1/Stm32f0xx/Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Interrupt.cyclo ./Src/Interrupt.d ./Src/Interrupt.o ./Src/Interrupt.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

