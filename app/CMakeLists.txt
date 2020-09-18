cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_CXX_STANDARD 17)

find_library(TAGLIB taglib)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(
    ./src
    ../build/3dparty/taglib
    ../3dparty/taglib/taglib/ape
    ../3dparty/taglib/taglib/asf
    ../3dparty/taglib/taglib/flac
    ../3dparty/taglib/taglib/it
    ../3dparty/taglib/taglib/mod
    ../3dparty/taglib/taglib/mp4
    ../3dparty/taglib/taglib/mpc
    ../3dparty/taglib/taglib/mpeg
    ../3dparty/taglib/taglib/mpeg/id3v2
    ../3dparty/taglib/taglib/mpeg/id3v2/frames
    ../3dparty/taglib/taglib/ogg
    ../3dparty/taglib/taglib/riff
    ../3dparty/taglib/taglib/s3m
    ../3dparty/taglib/taglib/toolkit
    ../3dparty/taglib/taglib/trueaudio
    ../3dparty/taglib/taglib/wavpack
    ../3dparty/taglib/taglib/xm
    ../3dparty/taglib/taglib
)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(utag main.cpp)

add_subdirectory(src)

target_link_libraries(utag tag liba ${GTK3_LIBRARIES})

set_target_properties(utag PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../..)