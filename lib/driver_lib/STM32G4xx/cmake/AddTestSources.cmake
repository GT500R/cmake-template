function(add_test_sources)
    target_sources(
        ${TARGET_NAME}
        PRIVATE gtest_main.cpp
    )
endfunction()
