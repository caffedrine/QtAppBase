cmake_minimum_required(VERSION 3.5)

project(qtappbase_app LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Enable debugging options
set(VERBOSE ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Assume error console to print out data always
set(QT_ASSUME_STDERR_HAS_CONSOLE 1)

# Default build release
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Building ${PROJECT_NAME} by default in Release mode unless a different mode is specified")
    set(CMAKE_BUILD_TYPE Release)
endif()

# make sure __cplusplus is defined when using msvc
if(MSVC)
    string(APPEND CMAKE_CXX_FLAGS " /Zc:__cplusplus /MP")
endif()

# Find required Qt5 or Qt6 dependencies
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Core Concurrent REQUIRED)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/base)

add_executable(${PROJECT_NAME} example/main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Concurrent
        qtappbase)