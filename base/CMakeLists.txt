cmake_minimum_required(VERSION 3.5)

set(QTAPPBASE_VERSION 1.0.0)
project(qtappbase VERSION ${QTAPPBASE_VERSION} LANGUAGES CXX C)
message(STATUS "Building qtappbase ${QTAPPBASE_VERSION}")

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
    message(STATUS "Building qtappbase by default in Release mode unless a different mode is specified")
    set(CMAKE_BUILD_TYPE Release)
endif()

# make sure __cplusplus is defined when using msvc and enable parallel build
if(MSVC)
    string(APPEND CMAKE_CXX_FLAGS " /Zc:__cplusplus /MP")
endif()

# Find required Qt5 or Qt6 dependencies
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Core Concurrent REQUIRED)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/spdlog)

add_library(qtappbase Logger.cpp Logger.h)
include_directories(qtappbase ${CMAKE_CURRENT_LIST_DIR}/)

target_link_libraries(qtappbase PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Concurrent
        spdlog::spdlog)