set(TARGET_NAME rtosAdapter_lib)

if(NOT UNITTESTS_ENABLED)
    add_library(${TARGET_NAME})

    #include the interfaces
    target_include_directories(${TARGET_NAME}
        PUBLIC include
    )

    #add the specific RTOS implementation
    if(RTOS STREQUAL "FreeRTOS")
        add_subdirectory(FreeRTOS)
    else()
        message(FATAL_ERROR "RTOS is not set in CMakePresets.json.")
    endif()
else()
    add_subdirectory(test)
endif()
