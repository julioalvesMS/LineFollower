################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Sensor/Track/Emitter/emitter_hal.c 

OBJS += \
./Sources/Sensor/Track/Emitter/emitter_hal.o 

C_DEPS += \
./Sources/Sensor/Track/Emitter/emitter_hal.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Sensor/Track/Emitter/%.o: ../Sources/Sensor/Track/Emitter/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	echo -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


