function(add_productive_sources)
    target_sources(
        app1
        PRIVATE Core/Src/app_freertos.c
                Core/Src/gpio.c
                Core/Src/main.c
                Core/Src/stm32g4xx_hal_msp.c
                Core/Src/stm32g4xx_hal_timebase_tim.c
                Core/Src/stm32g4xx_it.c
                Core/Src/syscalls.c
                Core/Src/sysmem.c
                Core/Src/system_stm32g4xx.c
                src/app1Main.cpp
                src/Factories/DeviceFactory.cpp
                src/Factories/DriverFactory.cpp
                startup_stm32g491xx.s
    )
endfunction()
