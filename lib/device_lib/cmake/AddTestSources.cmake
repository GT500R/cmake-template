function(add_test_sources)
    target_sources(
        ${TARGET_NAME}
        PRIVATE ../src/DigitalIoBridge.cpp
                GTestDigitalIoBridge.cpp
                gtest_main.cpp
    )
endfunction()
