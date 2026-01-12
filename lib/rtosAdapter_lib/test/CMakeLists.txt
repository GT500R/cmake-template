set(TARGET_NAME rtosAdapter_lib)

add_library(${TARGET_NAME} INTERFACE)
target_include_directories(${TARGET_NAME}
    INTERFACE ../include
              include
)
