################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Ext_Logger/Ext_Logger.c 

OBJS += \
./Ext_Logger/Ext_Logger.o 

C_DEPS += \
./Ext_Logger/Ext_Logger.d 


# Each subdirectory must supply rules for building sources it contributes
Ext_Logger/%.o Ext_Logger/%.su Ext_Logger/%.cyclo: ../Ext_Logger/%.c Ext_Logger/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/STM32F407_Projects/Ext_Logger/Drivers" -I"D:/STM32F407_Projects/Ext_Logger/Ext_Logger" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Ext_Logger

clean-Ext_Logger:
	-$(RM) ./Ext_Logger/Ext_Logger.cyclo ./Ext_Logger/Ext_Logger.d ./Ext_Logger/Ext_Logger.o ./Ext_Logger/Ext_Logger.su

.PHONY: clean-Ext_Logger

