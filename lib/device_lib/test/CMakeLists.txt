set(TARGET_NAME device_lib)

add_library(${TARGET_NAME} INTERFACE)

target_include_directories(${TARGET_NAME}
    INTERFACE ../include
              include
)

set(TARGET_NAME test_device_lib)

add_executable(${TARGET_NAME})

include(../cmake/AddTestSources.cmake)
add_test_sources()

target_link_libraries(${TARGET_NAME}
    PRIVATE device_lib
            driver_lib
            util_lib
            GTest::gtest
            GTest::gmock
)

gtest_discover_tests(${TARGET_NAME})
