function(add_test_sources)
    target_sources(
        ${TARGET_NAME}
        PRIVATE ../src/Minus.cpp
                ../src/Plus.cpp
                GTestMinus.cpp
                GTestPlus.cpp
                gtest_main.cpp
    )
endfunction()
