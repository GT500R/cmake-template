set(TARGET_NAME device_lib)

if(NOT UNITTESTS_ENABLED)
    add_library(${TARGET_NAME})

    target_include_directories(${TARGET_NAME}
        PUBLIC  include
        PRIVATE src
    )

    include(cmake/AddProductiveSources.cmake)
    add_productive_sources()

    target_link_libraries(${TARGET_NAME}
        driver_lib
        util_lib
    )
else()
    add_subdirectory(test)
endif()
