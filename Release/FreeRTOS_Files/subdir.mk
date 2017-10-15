################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Files/croutine.c \
../FreeRTOS_Files/event_groups.c \
../FreeRTOS_Files/heap_1.c \
../FreeRTOS_Files/list.c \
../FreeRTOS_Files/mpu_wrappers.c \
../FreeRTOS_Files/port.c \
../FreeRTOS_Files/queue.c \
../FreeRTOS_Files/tasks.c \
../FreeRTOS_Files/timers.c 

OBJS += \
./FreeRTOS_Files/croutine.o \
./FreeRTOS_Files/event_groups.o \
./FreeRTOS_Files/heap_1.o \
./FreeRTOS_Files/list.o \
./FreeRTOS_Files/mpu_wrappers.o \
./FreeRTOS_Files/port.o \
./FreeRTOS_Files/queue.o \
./FreeRTOS_Files/tasks.o \
./FreeRTOS_Files/timers.o 

C_DEPS += \
./FreeRTOS_Files/croutine.d \
./FreeRTOS_Files/event_groups.d \
./FreeRTOS_Files/heap_1.d \
./FreeRTOS_Files/list.d \
./FreeRTOS_Files/mpu_wrappers.d \
./FreeRTOS_Files/port.d \
./FreeRTOS_Files/queue.d \
./FreeRTOS_Files/tasks.d \
./FreeRTOS_Files/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Files/%.o: ../FreeRTOS_Files/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC1302_T038x0200 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC1300_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Libraries" -Os -ffunction-sections -fdata-sections -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m0 -mthumb -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

