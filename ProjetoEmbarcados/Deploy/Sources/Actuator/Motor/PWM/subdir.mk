################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Actuator/Motor/PWM/pwm_motor.c 

OBJS += \
./Sources/Actuator/Motor/PWM/pwm_motor.o 

C_DEPS += \
./Sources/Actuator/Motor/PWM/pwm_motor.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Actuator/Motor/PWM/%.o: ../Sources/Actuator/Motor/PWM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	echo -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


