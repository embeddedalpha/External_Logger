################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SPI/SPI.c 

OBJS += \
./Drivers/SPI/SPI.o 

C_DEPS += \
./Drivers/SPI/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SPI/%.o Drivers/SPI/%.su Drivers/SPI/%.cyclo: ../Drivers/SPI/%.c Drivers/SPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/STM32F407_Projects/Ext_Logger/Drivers" -I"D:/STM32F407_Projects/Ext_Logger/Ext_Logger" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-SPI

clean-Drivers-2f-SPI:
	-$(RM) ./Drivers/SPI/SPI.cyclo ./Drivers/SPI/SPI.d ./Drivers/SPI/SPI.o ./Drivers/SPI/SPI.su

.PHONY: clean-Drivers-2f-SPI

