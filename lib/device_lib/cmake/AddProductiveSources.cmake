function(add_productive_sources)
    target_sources(
        device_lib
        PRIVATE src/DigitalIoBridge.cpp
    )
endfunction()
