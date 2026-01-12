set(TARGET_NAME driver_lib)

add_library(${TARGET_NAME} INTERFACE)

target_include_directories(${TARGET_NAME}
    INTERFACE ../include
              include
)

set(TARGET_NAME test_driver_lib)

add_executable(${TARGET_NAME})

include(../STM32G4xx/cmake/AddTestSources.cmake)
add_test_sources()

target_link_libraries(${TARGET_NAME}
    PRIVATE driver_lib
            GTest::gtest
            GTest::gmock
)

gtest_discover_tests(${TARGET_NAME})
