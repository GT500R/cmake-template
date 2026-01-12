target_include_directories(${TARGET_NAME}
    PUBLIC include
)

include(cmake/AddProductiveSources.cmake)
add_productive_sources()

target_link_libraries(${TARGET_NAME}
    hardware_lib
)
