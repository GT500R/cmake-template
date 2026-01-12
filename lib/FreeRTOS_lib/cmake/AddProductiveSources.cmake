function(add_productive_sources)
    target_sources(
        FreeRTOS_lib
        PRIVATE src/CMSIS_RTOS_V2/cmsis_os2.c
                src/portable/GCC/ARM_CM4F/port.c
                src/portable/MemMang/heap_4.c
                src/croutine.c
                src/event_groups.c
                src/list.c
                src/queue.c
                src/stream_buffer.c
                src/tasks.c
                src/timers.c
    )
endfunction()
