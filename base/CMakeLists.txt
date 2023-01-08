cmake_minimum_required(VERSION 3.5)

set(PROJECT_VERSION 1.0.0)
set(LIB_API_VERSION 1)

project(LibQtAppBase VERSION ${PROJECT_VERSION})
set(LIB_NAME QtAppBase)

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
    message(STATUS "Building ${LIB_NAME} by default in Release mode unless a different mode is specified")
    set(CMAKE_BUILD_TYPE Release)
endif()

# Find required Qt5 or Qt6 dependencies
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Core Concurrent REQUIRED)

#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/spdlog)
include_directories(${CMAKE_CURRENT_LIST_DIR}/thirdparty/spdlog/include)

add_library(${LIB_NAME} SHARED src/utils/Logger.cpp src/utils/Logger.h
        src/extensions/MultiSelectComboBox/MultiSelectComboBox.cpp src/extensions/MultiSelectComboBox/MultiSelectComboBox.h)

set_target_properties(${LIB_NAME} PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${LIB_API_VERSION})
include_directories(${LIB_NAME} ${CMAKE_CURRENT_LIST_DIR}/)

target_link_libraries(${LIB_NAME} PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Concurrent)

# Install the library
install(TARGETS ${LIB_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
install(DIRECTORY thirdparty/spdlog/include/spdlog DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/thirdparty)
install(FILES src/utils/Logger.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/${LIB_NAME})
install(FILES src/extensions/MultiSelectComboBox/MultiSelectComboBox.h DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/${LIB_NAME}/extensions/MultiSelectComboBox.h)