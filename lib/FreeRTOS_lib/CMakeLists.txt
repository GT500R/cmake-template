set(TARGET_NAME FreeRTOS_lib)

add_library(${TARGET_NAME})

if(NOT DEFINED APP_CORE_INCLUDE_DIR)
    message(FATAL_ERROR "APP_CORE_INCLUDE_DIR is not defined")
endif()

target_include_directories(${TARGET_NAME}
    PUBLIC  include
            src/CMSIS_RTOS_V2
            src/portable/GCC/ARM_CM4F
    PRIVATE ${APP_CORE_INCLUDE_DIR}
)

include(cmake/AddProductiveSources.cmake)
add_productive_sources()

target_link_libraries(${TARGET_NAME}
    hardware_lib
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(FATAL_ERROR "Generated code requires C11 or higher")
endif()
