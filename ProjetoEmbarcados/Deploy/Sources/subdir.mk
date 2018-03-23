################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/buzzer_hal.c \
../Sources/ledswi_hal.c \
../Sources/main.c \
../Sources/mcg_hal.c \
../Sources/util.c 

OBJS += \
./Sources/buzzer_hal.o \
./Sources/ledswi_hal.o \
./Sources/main.o \
./Sources/mcg_hal.o \
./Sources/util.o 

C_DEPS += \
./Sources/buzzer_hal.d \
./Sources/ledswi_hal.d \
./Sources/main.d \
./Sources/mcg_hal.d \
./Sources/util.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	echo -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


