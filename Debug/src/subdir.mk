################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ball.cpp \
../src/BallRender.cpp \
../src/Game.cpp \
../src/Pad.cpp \
../src/main.cpp 

OBJS += \
./src/Ball.o \
./src/BallRender.o \
./src/Game.o \
./src/Pad.o \
./src/main.o 

CPP_DEPS += \
./src/Ball.d \
./src/BallRender.d \
./src/Game.d \
./src/Pad.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -DSFML_DYNAMIC -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


