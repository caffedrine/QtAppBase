cmake_minimum_required(VERSION 3.9)

project(QtAppBase VERSION 1.0.0 DESCRIPTION "Qt base components to be used across multiple projects")

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Enable optimizations for release
add_compile_options(
        -Wall -Werror -Wno-error=maybe-uninitialized
        $<$<CONFIG:RELEASE>:-Ofast>
        $<$<CONFIG:DEBUG>:-O0>
        $<$<CONFIG:DEBUG>:-ggdb3>
)
add_compile_definitions($<$<CONFIG:RELEASE>:NDEBUG>)

# Assume error console to print out data always
set(QT_ASSUME_STDERR_HAS_CONSOLE 1)

# Find required Qt5 or Qt6 dependencies
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Core Concurrent Xml REQUIRED)

# Get all sources
file(GLOB_RECURSE Proj_SOURCES "src/base/*.c" "src/base/*.cpp" "src/base/*.qrc")
# file(GLOB_RECURSE Thirdparty_SOURCES "thirdparty/*.c" "thirdparty/*.cpp")

message(${Proj_SOURCES})

# Create library
add_library(QtAppBase SHARED ${Proj_SOURCES})
add_library(base::QtAppBase ALIAS QtAppBase)
set_target_properties(QtAppBase PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1)
configure_file(QtAppBase.pc.in QtAppBase.pc @ONLY)
include_directories(${CMAKE_CURRENT_LIST_DIR}/src)
set(IS_BUILT_AS_LIBRARY 1)

# include thirdparty libs
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src/base/thirdparty/ASN1)
include_directories(${CMAKE_CURRENT_LIST_DIR}/src/base/thirdparty/ASN1)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src/base/thirdparty/spdlog)
include_directories(${CMAKE_CURRENT_LIST_DIR}/src/base/thirdparty/spdlog/include)

# include private code
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src/private/thirdparty/uriparser)
include_directories(${CMAKE_CURRENT_LIST_DIR}/src/private/thirdparty/uriparser/src)

target_link_libraries(QtAppBase PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Concurrent
        Qt${QT_VERSION_MAJOR}::Xml
        spdlog::spdlog
        Uri::UriParser)

# Public API headers
target_include_directories(QtAppBase PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:src>)

# Spdlog
target_include_directories(QtAppBase PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/base/thirdparty/spdlog/include>
        $<INSTALL_INTERFACE:src/thirdparty/spdlog/include>)

install(TARGETS QtAppBase LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS QtAppBase EXPORT QtAppBaseConfig LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
export(TARGETS QtAppBase FILE "${CMAKE_CURRENT_BINARY_DIR}/QtAppBaseConfig.cmake")
install(EXPORT QtAppBaseConfig DESTINATION "${CMAKE_INSTALL_LIBDIR}/QtAppBase/cmake" NAMESPACE base::)
install(DIRECTORY src DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES ${CMAKE_BINARY_DIR}/QtAppBase.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

# Perform local installation in the build folder after each build
#set(LOCAL_DEPLOY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/deploy)
#add_custom_command(TARGET QtAppBase POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_NAME:QtAppBase> ${LOCAL_DEPLOY_DIR}/lib/$<TARGET_FILE_NAME:QtAppBase>)
#add_custom_command(TARGET QtAppBase POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_NAME:QtAppBase>.a ${LOCAL_DEPLOY_DIR}/lib/$<TARGET_FILE_NAME:QtAppBase>.a)
## copy headers
#file(COPY "src/" DESTINATION "${LOCAL_DEPLOY_DIR}/includes/QtAppBase" FILES_MATCHING PATTERN "*.h")
#file(COPY thirdparty/spdlog/include/spdlog DESTINATION ${LOCAL_DEPLOY_DIR}/includes/QtAppBase/thirdparty)
#file(COPY thirdparty/MultiSelectComboBox/MultiSelectComboBox.h DESTINATION ${LOCAL_DEPLOY_DIR}/includes/QtAppBase/thirdparty)
#file(COPY thirdparty/QJsonModel/QJsonModel.h DESTINATION ${LOCAL_DEPLOY_DIR}/includes/QtAppBase/thirdparty)

## Install the library into a given folder
#set(DEPLOY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/deploy)
#install(TARGETS QtAppBase DESTINATION ${DEPLOY_DIR}/lib)
#
## Install headers for sources
#install(DIRECTORY "src/" DESTINATION "${DEPLOY_DIR}/includes/QtAppBase" FILES_MATCHING PATTERN "*.h")
#
### Install headers for thirdparty applications
#install(DIRECTORY thirdparty/spdlog/include/spdlog DESTINATION ${DEPLOY_DIR}/includes/QtAppBase/thirdparty)
#install(FILES thirdparty/MultiSelectComboBox/MultiSelectComboBox.h DESTINATION ${DEPLOY_DIR}/includes/QtAppBase/thirdparty)
#install(FILES thirdparty/QJsonModel/QJsonModel.h DESTINATION ${DEPLOY_DIR}/includes/QtAppBase/thirdparty)

if(${IS_BUILT_AS_LIBRARY})
    add_definitions(-DDLL_DECL_SPEC=Q_DECL_EXPORT)
else()
    add_definitions(-DDLL_DECL_SPEC=Q_DECL_IMPORT)
endif()