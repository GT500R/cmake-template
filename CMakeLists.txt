cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(APP1_FIRMWARE_ENABLED OR APP2_FIRMWARE_ENABLED)
    set(FIRMWARE_ENABLED ON)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(FIRMWARE_ENABLED AND NOT UNITTESTS_ENABLED)
    # Include toolchain file for firmware builds
    include(cmake/gcc-arm-none-eabi.cmake)
elseif(UNITTESTS_ENABLED)
    enable_testing()

    # Include compiler configuration for unit tests
    include(cmake/clang.cmake)

    # Include testing framework
    add_subdirectory(dep/googletest)
    include(GoogleTest)
endif()

project(cmake-template)

#
# Project setup
#

# Firmware-only libraries
if(FIRMWARE_ENABLED AND NOT UNITTESTS_ENABLED)
    add_subdirectory(lib/hardware_lib)
    add_subdirectory(lib/FreeRTOS_lib)
endif()

#
# common libs for unit test and productive code
#
if(FIRMWARE_ENABLED)
    add_subdirectory(lib/device_lib)
    add_subdirectory(lib/driver_lib)
    add_subdirectory(lib/rtosAdapter_lib)
    add_subdirectory(lib/util_lib)
endif()

#
# apps
#
if(APP1_FIRMWARE_ENABLED)
    add_subdirectory(app/app1)
endif()
if(APP2_FIRMWARE_ENABLED)
    add_subdirectory(app/app2)
endif()
