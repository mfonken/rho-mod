################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/UniSM/platforms/stm32_interface.c 

OBJS += \
./Libs/UniSM/platforms/stm32_interface.o 

C_DEPS += \
./Libs/UniSM/platforms/stm32_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/UniSM/platforms/%.o Libs/UniSM/platforms/%.su: ../Libs/UniSM/platforms/%.c Libs/UniSM/platforms/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -D__STM32__=1 -D__OV9712__=1 -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniLog" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniSM" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniSM/platforms" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/rho_mod_v7/Libs/UniSM/OV9712" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-UniSM-2f-platforms

clean-Libs-2f-UniSM-2f-platforms:
	-$(RM) ./Libs/UniSM/platforms/stm32_interface.d ./Libs/UniSM/platforms/stm32_interface.o ./Libs/UniSM/platforms/stm32_interface.su

.PHONY: clean-Libs-2f-UniSM-2f-platforms

