set(TARGET_NAME hardware_lib)

add_library(${TARGET_NAME})

if(NOT DEFINED MICROCONTROLLER)
    message(FATAL_ERROR "MICROCONTROLLER is not defined")
endif()

target_compile_definitions(${TARGET_NAME}
    PUBLIC  ${MICROCONTROLLER}
    PRIVATE USE_HAL_DRIVER
)

if(NOT DEFINED APP_CORE_INCLUDE_DIR)
    message(FATAL_ERROR "APP_CORE_INCLUDE_DIR is not defined")
endif()

target_include_directories(${TARGET_NAME}
    PUBLIC  src/CMSIS/Device/ST/STM32G4xx/Include
            src/CMSIS/Include
            src/STM32G4xx_HAL_Driver/Inc
            src/STM32G4xx_HAL_Driver/Inc/Legacy
            ${APP_CORE_INCLUDE_DIR}
)

include(cmake/AddProductiveSources.cmake)
add_productive_sources()

target_link_libraries(${TARGET_NAME})

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(FATAL_ERROR "Generated code requires C11 or higher")
endif()
