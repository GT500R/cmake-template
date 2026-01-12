set(TARGET_NAME util_lib)

add_library(${TARGET_NAME})
target_include_directories(${TARGET_NAME}
    PUBLIC  include
    PRIVATE src
)

include(cmake/AddProductiveSources.cmake)
add_productive_sources()

target_link_libraries(${TARGET_NAME}
    driver_lib
    rtosAdapter_lib
)

if(UNITTESTS_ENABLED)
    add_subdirectory(test)
endif()
