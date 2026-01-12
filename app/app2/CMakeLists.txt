# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME app2)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Enable CMake support for ASM, C and C++ languages
enable_language(ASM C CXX)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

if(NOT UNITTESTS_ENABLED)
    # Create an executable object type
    add_executable(${CMAKE_PROJECT_NAME})

    include(cmake/AddProductiveSources.cmake)
    add_productive_sources()

    # Add include paths
    target_include_directories(${CMAKE_PROJECT_NAME}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc
                ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

    # Add linked libraries
    target_link_libraries(${CMAKE_PROJECT_NAME}
        device_lib
        driver_lib
        FreeRTOS_lib
        hardware_lib
        rtosAdapter_lib
        util_lib
    )

    # Validate that user code is compatible with C++ standard
    if(CMAKE_CXX_STANDARD LESS 17)
        message(FATAL_ERROR "User code requires C++17 or higher")
    endif()

    # read version from version.h
    file(READ "${CMAKE_CURRENT_SOURCE_DIR}/src/version.h" VERSION_HEADER_CONTENTS)

    string(REGEX MATCH "#define VERSION_MAJOR ([0-9]+)" _ ${VERSION_HEADER_CONTENTS})
    set(VERSION_MAJOR ${CMAKE_MATCH_1})

    string(REGEX MATCH "#define VERSION_MINOR ([0-9]+)" _ ${VERSION_HEADER_CONTENTS})
    set(VERSION_MINOR ${CMAKE_MATCH_1})

    string(REGEX MATCH "#define VERSION_PATCH ([0-9]+)" _ ${VERSION_HEADER_CONTENTS})
    set(VERSION_PATCH ${CMAKE_MATCH_1})

    set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

    # Print the version
    message(STATUS "Version: ${VERSION}")
    
    # Convert CMAKE_BUILD_TYPE to lowercase for filenames
    string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE_LOWER)
    
    # Add version to hex file name
    set(HEX_FILENAME "${CMAKE_PROJECT_NAME}_${VERSION}_${BUILD_TYPE_LOWER}.hex")

    # Post build steps
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMENT "Generate .hex from .elf"
        COMMAND ${CMAKE_OBJCOPY} -O ihex ${CMAKE_PROJECT_NAME}.elf ${HEX_FILENAME}
    )
endif()
