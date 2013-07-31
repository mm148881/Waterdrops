################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Input.cpp \
../src/MakeWaterDrops.cpp \
../src/MyUtilClass.cpp \
../src/Sequence.cpp \
../src/Topol.cpp \
../src/Waters.cpp 

OBJS += \
./src/Input.o \
./src/MakeWaterDrops.o \
./src/MyUtilClass.o \
./src/Sequence.o \
./src/Topol.o \
./src/Waters.o 

CPP_DEPS += \
./src/Input.d \
./src/MakeWaterDrops.d \
./src/MyUtilClass.d \
./src/Sequence.d \
./src/Topol.d \
./src/Waters.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


