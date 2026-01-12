function(add_productive_sources)
    target_sources(
        util_lib
        PRIVATE src/Minus.cpp
                src/Plus.cpp
    )
endfunction()
