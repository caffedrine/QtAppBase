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
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Core Concurrent Xml REQUIRED)

# include spdlog
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/spdlog)
include_directories(${CMAKE_CURRENT_LIST_DIR}/thirdparty/spdlog/include)

# include headers
include_directories(${CMAKE_CURRENT_LIST_DIR}/src)

add_library(${LIB_NAME} SHARED
        # src/data_structures
        src/data_structures/Dict.cpp src/data_structures/Dict.h
        src/data_structures/DictTreeModel.cpp src/data_structures/DictTreeModel.h
        src/data_structures/DomModel.cpp src/data_structures/DomModel.h
        src/data_structures/QListViewModel.cpp src/data_structures/QListViewModel.h

        # src/Utils
        src/Utils/LambdaEventFilter.h
        src/utils/Logger.cpp src/utils/Logger.h
        src/utils/NetworkUtils.cpp src/utils/NetworkUtils.h
        src/utils/RegexUtils.cpp src/utils/RegexUtils.h
        src/utils/Singleton.cpp src/utils/Singleton.h
        src/utils/WebUtils.cpp src/utils/WebUtils.h
        src/utils/utils.cpp src/utils/utils.h

        # src/Extensions
        src/extensions/AdvancedPlainTextEdit.cpp src/extensions/AdvancedPlainTextEdit.h
        src/extensions/AdvancedTableWidget.cpp src/extensions/AdvancedTableWidget.h
        src/extensions/AdvancedTextEdit.cpp src/extensions/AdvancedTextEdit.h
        src/extensions/QDialogExtended.cpp src/extensions/QDialogExtended.h
        src/extensions/QMainWindowExtended.cpp src/extensions/QMainWindowExtended.h
        src/extensions/QThreadPoolExtended.cpp src/extensions/QThreadPoolExtended.h
        src/extensions/QTreeWidgetExtended.cpp src/extensions/QTreeWidgetExtended.h
        src/extensions/QTabBarExtended.cpp src/extensions/QTabBarExtended.h
        src/extensions/QTabWidgetExtended.cpp src/extensions/QTabWidgetExtended.h

        # Third-party sources
        thirdparty/MultiSelectComboBox/MultiSelectComboBox.cpp thirdparty/MultiSelectComboBox/MultiSelectComboBox.h)

set_target_properties(${LIB_NAME} PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${LIB_API_VERSION})

target_link_libraries(${LIB_NAME} PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Concurrent
        Qt${QT_VERSION_MAJOR}::Xml
        spdlog::spdlog)

# Install the library
set(DEPLOY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/deploy)
install(TARGETS ${LIB_NAME} DESTINATION ${DEPLOY_DIR}/lib)

# Deploy src/data_structures
install(FILES
        src/data_structures/Dict.h
        src/data_structures/DictTreeModel.h
        src/data_structures/DomModel.h
        src/data_structures/QListViewModel.h
        src/data_structures/Dict.h
        DESTINATION ${DEPLOY_DIR}/includes/${LIB_NAME}/data_structures)

# Deploy utils
install(FILES
        src/Utils/LambdaEventFilter.h
        src/Utils/Logger.h
        src/Utils/NetworkUtils.h
        src/Utils/RegexUtils.h
        src/Utils/Singleton.h
        src/Utils/WebUtils.h
        src/Utils/utils.h
        DESTINATION ${DEPLOY_DIR}/includes/${LIB_NAME}/utils)

# Deploy Qt extensions
install(FILES
        src/extensions/AdvancedPlainTextEdit.h
        src/extensions/AdvancedTableWidget.h
        src/extensions/AdvancedTextEdit.h
        src/extensions/QDialogExtended.h
        src/extensions/QMainWindowExtended.h
        src/extensions/QThreadPoolExtended.h
        src/extensions/QTreeWidgetExtended.h
        src/extensions/QTabBarExtended.h
        src/extensions/QTabWidgetExtended.h
        DESTINATION ${DEPLOY_DIR}/includes/${LIB_NAME}/extensions)

# Deploy third part source code
install(DIRECTORY thirdparty/spdlog/include/spdlog DESTINATION ${DEPLOY_DIR}/includes/thirdparty)
install(FILES thirdparty/MultiSelectComboBox/MultiSelectComboBox.h DESTINATION ${DEPLOY_DIR}/includes/thirdparty)