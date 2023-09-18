cmake_minimum_required(VERSION 3.11.1)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(targetPrj C)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY") # For cross-compiling

set(CMAKE_C_COMPILER "/home/abdu/Downloads/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc")
string(CONCAT FLAGS
    " -ffunction-sections"
    " -fdata-sections"
    " -mthumb"
    " -mabi=aapcs"
    " -mcpu=cortex-m4"
    " -mfpu=fpv4-sp-d16"
    " -mfloat-abi=hard"
    " -specs=\"nosys.specs\""
    " -Wl,--gc-sections"
    " -Wl,--script \"${CMAKE_CURRENT_SOURCE_DIR}/tm4c123gh6pm.lds\""
)
set(CMAKE_C_FLAGS "${FLAGS}")

set(SOURCES 
  "${CMAKE_CURRENT_SOURCE_DIR}/main.c" 
  "${CMAKE_CURRENT_SOURCE_DIR}/tm4c123gh6pm_startup_ccs_gcc.c"
)
add_executable(application ${SOURCES})