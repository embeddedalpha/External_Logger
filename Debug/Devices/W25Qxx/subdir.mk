################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Devices/W25Qxx/W25Qxx.c 

OBJS += \
./Devices/W25Qxx/W25Qxx.o 

C_DEPS += \
./Devices/W25Qxx/W25Qxx.d 


# Each subdirectory must supply rules for building sources it contributes
Devices/W25Qxx/%.o Devices/W25Qxx/%.su Devices/W25Qxx/%.cyclo: ../Devices/W25Qxx/%.c Devices/W25Qxx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/STM32F407_Projects/Ext_Logger/Drivers" -I"D:/STM32F407_Projects/Ext_Logger/Ext_Logger" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Devices-2f-W25Qxx

clean-Devices-2f-W25Qxx:
	-$(RM) ./Devices/W25Qxx/W25Qxx.cyclo ./Devices/W25Qxx/W25Qxx.d ./Devices/W25Qxx/W25Qxx.o ./Devices/W25Qxx/W25Qxx.su

.PHONY: clean-Devices-2f-W25Qxx

