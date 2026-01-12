function(add_productive_sources)
    target_sources(
        rtosAdapter_lib
        PRIVATE src/RtosTask.cpp
    )
endfunction()
