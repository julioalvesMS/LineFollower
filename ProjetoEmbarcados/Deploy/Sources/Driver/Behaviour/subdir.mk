################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Driver/Behaviour/cmdMachine.c 

OBJS += \
./Sources/Driver/Behaviour/cmdMachine.o 

C_DEPS += \
./Sources/Driver/Behaviour/cmdMachine.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Driver/Behaviour/%.o: ../Sources/Driver/Behaviour/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	echo -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


