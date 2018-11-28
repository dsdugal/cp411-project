################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ball.cpp \
../src/Board.cpp \
../src/Camera.cpp \
../src/Matrix.cpp \
../src/Menu.cpp \
../src/Paddle.cpp \
../src/Point.cpp \
../src/Prism.cpp \
../src/Prong.cpp \
../src/Scoreboard.cpp \
../src/Shape3D.cpp \
../src/Sphere.cpp \
../src/Vector.cpp \
../src/World.cpp 

OBJS += \
./src/Ball.o \
./src/Board.o \
./src/Camera.o \
./src/Matrix.o \
./src/Menu.o \
./src/Paddle.o \
./src/Point.o \
./src/Prism.o \
./src/Prong.o \
./src/Scoreboard.o \
./src/Shape3D.o \
./src/Sphere.o \
./src/Vector.o \
./src/World.o 

CPP_DEPS += \
./src/Ball.d \
./src/Board.d \
./src/Camera.d \
./src/Matrix.d \
./src/Menu.d \
./src/Paddle.d \
./src/Point.d \
./src/Prism.d \
./src/Prong.d \
./src/Scoreboard.d \
./src/Shape3D.d \
./src/Sphere.d \
./src/Vector.d \
./src/World.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


