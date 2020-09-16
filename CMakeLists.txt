cmake_minimum_required(VERSION 2.8)

project(utag)

set(CMAKE_CXX_STANDARD 17)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

include_directories(app)

add_executable(utag app/main.cpp)

add_subdirectory(app)

target_link_libraries(utag liba)

# Link the target to the GTK+ libraries
TARGET_LINK_LIBRARIES(utag ${GTK3_LIBRARIES})

set_target_properties(utag PROPERTIES RUNTIME_OUTPUT_DIRECTORY ..)
