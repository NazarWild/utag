# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/ndykyy/.brew/Cellar/cmake/3.18.2/bin/cmake

# The command to remove a file.
RM = /Users/ndykyy/.brew/Cellar/cmake/3.18.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ndykyy/Desktop/utag

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ndykyy/Desktop/utag/build

# Utility rule file for docs.

# Include the progress variables for this target.
include 3dparty/taglib/CMakeFiles/docs.dir/progress.make

3dparty/taglib/CMakeFiles/docs:
	cd /Users/ndykyy/Desktop/utag/build/3dparty/taglib && doxygen

docs: 3dparty/taglib/CMakeFiles/docs
docs: 3dparty/taglib/CMakeFiles/docs.dir/build.make

.PHONY : docs

# Rule to build all files generated by this target.
3dparty/taglib/CMakeFiles/docs.dir/build: docs

.PHONY : 3dparty/taglib/CMakeFiles/docs.dir/build

3dparty/taglib/CMakeFiles/docs.dir/clean:
	cd /Users/ndykyy/Desktop/utag/build/3dparty/taglib && $(CMAKE_COMMAND) -P CMakeFiles/docs.dir/cmake_clean.cmake
.PHONY : 3dparty/taglib/CMakeFiles/docs.dir/clean

3dparty/taglib/CMakeFiles/docs.dir/depend:
	cd /Users/ndykyy/Desktop/utag/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ndykyy/Desktop/utag /Users/ndykyy/Desktop/utag/3dparty/taglib /Users/ndykyy/Desktop/utag/build /Users/ndykyy/Desktop/utag/build/3dparty/taglib /Users/ndykyy/Desktop/utag/build/3dparty/taglib/CMakeFiles/docs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 3dparty/taglib/CMakeFiles/docs.dir/depend

