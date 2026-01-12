function(add_productive_sources)
    target_sources(
        driver_lib
        PRIVATE src/DigitalInput.cpp
                src/DigitalOutput.cpp
    )
endfunction()
