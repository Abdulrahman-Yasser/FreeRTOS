cmake_minimum_required(VERSION 3.11.1)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(targetPrj C)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY") # For cross-compiling

set(CMAKE_C_COMPILER "/home/abdu/Downloads/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc")
set(CMAKE_C_OBJCOPY "/home/abdu/Downloads/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-objcopy")
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
add_executable(application.axf ${SOURCES})

add_custom_target(application.bin ALL DEPENDS application.axf)
add_custom_command(TARGET application.bin
    COMMAND ${CMAKE_C_OBJCOPY} ARGS -O binary application.axf application.bin)


add_custom_target(flash DEPENDS application.bin)
add_custom_command(TARGET flash
    USES_TERMINAL
    COMMAND lm4flash -V
    COMMAND lm4flash application.bin)

set(FLASH_EXECUTABLE cat ~/myPassword.txt | sudo ~/temp/embedded/lm4tools/lm4flash/lm4flash)
ADD_CUSTOM_TARGET("flash_2" DEPENDS application.axf 
    COMMAND ${CMAKE_C_OBJCOPY} -O binary application.axf application.bin 
    COMMAND ${FLASH_EXECUTABLE} application.bin
)
