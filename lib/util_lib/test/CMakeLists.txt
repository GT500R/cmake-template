set(TARGET_NAME util_lib)
target_include_directories(${TARGET_NAME}
    INTERFACE ../include
              include
)

set(TARGET_NAME test_util_lib)
add_executable(${TARGET_NAME})

include(../cmake/AddTestSources.cmake)
add_test_sources()

target_link_libraries(${TARGET_NAME}
    PRIVATE GTest::gtest
            GTest::gmock
)

gtest_discover_tests(${TARGET_NAME})
