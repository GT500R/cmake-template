# Compiler Configuration for Unit Tests

# Helper function to get the full path to the compiler
function(get_compiler_full_path output_var base_compiler)
    if(${CMAKE_HOST_SYSTEM_NAME} MATCHES "Linux")
        # For Linux, use the specified version
        set(CLANG_VERSION "-18" CACHE STRING "Clang version to use")
        set(${output_var} "/usr/bin/${base_compiler}${CLANG_VERSION}" PARENT_SCOPE)
    else() # Windows
        # For Windows, get the path from the already configured compiler
        get_filename_component(CLANG_PATH ${CMAKE_C_COMPILER} DIRECTORY)
        set(${output_var} "${CLANG_PATH}/${base_compiler}.exe" PARENT_SCOPE)
    endif()
endfunction()

# Set the proper compiler based on platform
if(UNIX)
    message(STATUS "Detected OS: Unix")
    set(TOOLCHAIN_PREFIX                clang)
    set(CLANG_VERSION                   "-18")
    set(CMAKE_C_COMPILER                ${TOOLCHAIN_PREFIX}${CLANG_VERSION})
    set(CMAKE_ASM_COMPILER              ${CMAKE_C_COMPILER})
    set(CMAKE_CXX_COMPILER              ${TOOLCHAIN_PREFIX}++${CLANG_VERSION})
elseif(WIN32)
    message(STATUS "Detected OS: Windows")
    set(TOOLCHAIN_PREFIX                clang)
    set(CMAKE_C_COMPILER                ${TOOLCHAIN_PREFIX})
    set(CMAKE_ASM_COMPILER              ${CMAKE_C_COMPILER})
    set(CMAKE_CXX_COMPILER              ${TOOLCHAIN_PREFIX}++)
else()
    message(FATAL_ERROR "Detected OS: Unsupported")
endif()
