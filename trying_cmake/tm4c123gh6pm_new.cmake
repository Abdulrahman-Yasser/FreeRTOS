
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING 1)

set(TOOLCHAIN_PREFIX "arm-none-eabi")
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}-gcc-10.3.1)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}-as)
set(CMAKE_AR ${TOOLCHAIN_PREFIX}-ar)
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}-objcopy)
set(CMAKE_C_OBJCOPY ${TOOLCHAIN_PREFIX}-objcopy)
set(CMAKE_OBJDUMP ${TOOLCHAIN_PREFIX}-objdump)


set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=softfp
-mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -ffunction-sections -fdata-sections -Wall
-specs=\"nosys.specs\"")

set(CMAKE_C_FLAGS_RELEASE "-Os")
set(CMAKE_C_FLAGS_DEBUG "-Og -g -gdwarf-3 -gstrict-dwarf")
set(CMAKE_EXE_LINKER_FLAGS "--entry ResetISR -Wl,-T\"../tm4c123gh6pm.lds\"")
message("${CMAKE_EXE_LINKER_FLAGS}")

 