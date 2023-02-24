################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/UniSM/OV9712/OV9712.c 

OBJS += \
./Libs/UniSM/OV9712/OV9712.o 

C_DEPS += \
./Libs/UniSM/OV9712/OV9712.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/UniSM/OV9712/%.o Libs/UniSM/OV9712/%.su: ../Libs/UniSM/OV9712/%.c Libs/UniSM/OV9712/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -D__STM32__=1 -D__OV9712__=1 -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniLog" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniSM" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniSM/platforms" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniSM/OV9712" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-UniSM-2f-OV9712

clean-Libs-2f-UniSM-2f-OV9712:
	-$(RM) ./Libs/UniSM/OV9712/OV9712.d ./Libs/UniSM/OV9712/OV9712.o ./Libs/UniSM/OV9712/OV9712.su

.PHONY: clean-Libs-2f-UniSM-2f-OV9712

