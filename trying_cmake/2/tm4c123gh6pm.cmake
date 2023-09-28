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
