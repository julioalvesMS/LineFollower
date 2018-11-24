################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Util/debugUart.c \
../Sources/Util/fsl_debug_console.c \
../Sources/Util/print_scan.c 

OBJS += \
./Sources/Util/debugUart.o \
./Sources/Util/fsl_debug_console.o \
./Sources/Util/print_scan.o 

C_DEPS += \
./Sources/Util/debugUart.d \
./Sources/Util/fsl_debug_console.d \
./Sources/Util/print_scan.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Util/%.o: ../Sources/Util/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	echo -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


