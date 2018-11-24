################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Sensor/Speed/speed.c 

OBJS += \
./Sources/Sensor/Speed/speed.o 

C_DEPS += \
./Sources/Sensor/Speed/speed.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Sensor/Speed/%.o: ../Sources/Sensor/Speed/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	echo -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


