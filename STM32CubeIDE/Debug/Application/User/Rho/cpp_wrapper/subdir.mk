################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/Rho/cpp_wrapper/rho_deco.c 

OBJS += \
./Application/User/Rho/cpp_wrapper/rho_deco.o 

C_DEPS += \
./Application/User/Rho/cpp_wrapper/rho_deco.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Rho/cpp_wrapper/%.o: ../Application/User/Rho/cpp_wrapper/%.c Application/User/Rho/cpp_wrapper/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -D__STM32__ -DGLOBAL_LOG_LEVEL=TEST -D__RHO__ -D__OV9712__ -c -I../../Core/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/STM32CubeIDE/Application/User/App" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/STM32CubeIDE/Application/User/UniSM" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/STM32CubeIDE/Application/User/UniLog" -I"C:/Users/Matthew Fonken/Desktop/marbl/Techincal/RhoMod/STM32CubeIDE/Application/User/Rho" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

