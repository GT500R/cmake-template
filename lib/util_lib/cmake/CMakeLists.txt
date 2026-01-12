set(TARGET_NAME util_lib)

add_library(${TARGET_NAME})
target_include_directories(${TARGET_NAME}
    PUBLIC  include
    PRIVATE src
)

include(cmake/AddProductiveSources.cmake)
add_productive_sources()

if(UNITTESTS_ENABLED)
    add_subdirectory(test)
endif()
