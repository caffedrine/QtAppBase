cmake_minimum_required(VERSION 3.9)

project(UriParser LANGUAGES CXX C VERSION 1.0.1 DESCRIPTION "Uri Parser Library")

include(GNUInstallDirs)

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# Get all sources
file(GLOB_RECURSE LIB_SOURCES "src/*.c" "src/*.cpp")

add_library(UriParser ${LIB_SOURCES})
add_library(Uri::UriParser ALIAS UriParser)
set_target_properties(UriParser PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1)
include_directories(src)

configure_file(UriParser.pc.in UriParser.pc @ONLY)

# Public API headers
target_include_directories(UriParser PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:src>)

install(TARGETS UriParser LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS UriParser EXPORT UriParserConfig LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
export(TARGETS UriParser FILE "${CMAKE_CURRENT_BINARY_DIR}/UriParserConfig.cmake")
install(EXPORT UriParserConfig DESTINATION "${CMAKE_INSTALL_LIBDIR}/UriParser/cmake" NAMESPACE Uri::)
install(DIRECTORY src DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES ${CMAKE_BINARY_DIR}/UriParser.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)