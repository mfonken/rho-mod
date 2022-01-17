################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Matthew\ Fonken/Desktop/marbl/Techincal/RhoMod/Core/Src/system_stm32g4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32g4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32g4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32g4xx.o: C:/Users/Matthew\ Fonken/Desktop/marbl/Techincal/RhoMod/Core/Src/system_stm32g4xx.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -D__STM32__ -DGLOBAL_LOG_LEVEL=TEST -D__OV9712__ -c -I../../Core/Inc -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/STM32CubeIDE/Application/User/App" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/STM32CubeIDE/Application/User/UniSM" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/STM32CubeIDE/Application/User/UniLog" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/STM32CubeIDE/Application/User/Rho" -I"C:/Users/Matthew Fonken/STM32Cube/Repository/STM32Cube_FW_G4_V1.4.0/Drivers/STM32G4xx_HAL_Driver/Inc" -I"C:/Users/Matthew Fonken/STM32Cube/Repository/STM32Cube_FW_G4_V1.4.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Matthew Fonken/STM32Cube/Repository/STM32Cube_FW_G4_V1.4.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"C:/Users/Matthew Fonken/STM32Cube/Repository/STM32Cube_FW_G4_V1.4.0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/system_stm32g4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

