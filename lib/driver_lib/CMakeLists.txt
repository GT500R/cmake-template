set(TARGET_NAME driver_lib)

if(NOT UNITTESTS_ENABLED)
    add_library(${TARGET_NAME})

    #include the interfaces
    target_include_directories(${TARGET_NAME}
        PUBLIC include
    )

    #add the specific DRIVER implementation
    if(DRIVER STREQUAL "STM32G4xx")
        add_subdirectory(STM32G4xx)
    else()
        message(FATAL_ERROR "DRIVER is not set in CMakePresets.json.")
    endif()
else()
    add_subdirectory(test)
endif()
