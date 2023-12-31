#Set cross compilation information
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# GCC toolchain prefix
set(TOOLCHAIN_PREFIX "arm-none-eabi")

# set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}-gcc)
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}-gcc-10.3.1)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}-as)
set(CMAKE_AR ${TOOLCHAIN_PREFIX}-ar)
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}-objcopy)
set(CMAKE_OBJDUMP ${TOOLCHAIN_PREFIX}-objdump)
set(CMAKE_VERBOSE_MAKEFILE ON)
# enable_language(ASM)

# # set(CPU "-mtune==cortex-m4")
set(CPU "-mcpu=cortex-m4 -march=armv7e-m -mfpu=fpv4-sp-d16 -mfloat-abi=softfp")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mthumb ${CPU}  ${FPU} -MD")
# # set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mthumb ${CPU} ${FPU} -std=gnu99 -Os -ffunction-sections -fdata-sections -MD -Wall -pedantic")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -c -mthumb ${CPU} ${FPU} -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs=\"nosys.specs\" -MD")

# set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
# set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
set(MCU_LINKER_SCRIPT " -T\"../tm4c123gh6pm.lds\"")
# set(CMAKE_EXE_LINKER_FLAGS "-T${CMAKE_CURRENT_LIST_DIR}/tm4c123gh6pm.lds")
# # set(CMAKE_EXE_LINKER_FLAGS "-mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -Og -ffunction-sections -fdata-sections 
# # -g -gdwarf-3 -gstrict-dwarf -Wall -specs=\"nosys.specs\" -mcpu=cortex-m4 -Wl,-Map,\"blinking_led.map\"
# #                             -T${PROJECT_SOURCE_DIR}/tm4c123gh6pm.lds -specs=${PROJECT_SOURCE_DIR}/tm4c123gh6pm_startup_ccs.c")



# # Processor specific definitions
# add_definitions(-DPART_TM4C123GH6PM)
# add_definitions(-DTARGET_IS_TM4C123_RA1)
# add_definitions(-Dgcc)

# set(EXECUTABLE ${CMAKE_PROJECT_NAME})


# set(FLASH_EXECUTABLE "App")

# ADD_CUSTOM_TARGET("flash" 
#     DEPENDS ${CMAKE_PROJECT_NAME}.elf 
#     COMMAND ${CMAKE_OBJCOPY} -O binary ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.hex 
# )

