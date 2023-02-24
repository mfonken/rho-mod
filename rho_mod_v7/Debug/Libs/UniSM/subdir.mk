################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/UniSM/master.c \
../Libs/UniSM/platform.c \
../Libs/UniSM/printers.c \
../Libs/UniSM/system.c 

OBJS += \
./Libs/UniSM/master.o \
./Libs/UniSM/platform.o \
./Libs/UniSM/printers.o \
./Libs/UniSM/system.o 

C_DEPS += \
./Libs/UniSM/master.d \
./Libs/UniSM/platform.d \
./Libs/UniSM/printers.d \
./Libs/UniSM/system.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/UniSM/%.o Libs/UniSM/%.su: ../Libs/UniSM/%.c Libs/UniSM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -D__STM32__=1 -D__OV9712__=1 -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniLog" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniSM" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniSM/platforms" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniSM/OV9712" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-UniSM

clean-Libs-2f-UniSM:
	-$(RM) ./Libs/UniSM/master.d ./Libs/UniSM/master.o ./Libs/UniSM/master.su ./Libs/UniSM/platform.d ./Libs/UniSM/platform.o ./Libs/UniSM/platform.su ./Libs/UniSM/printers.d ./Libs/UniSM/printers.o ./Libs/UniSM/printers.su ./Libs/UniSM/system.d ./Libs/UniSM/system.o ./Libs/UniSM/system.su

.PHONY: clean-Libs-2f-UniSM

