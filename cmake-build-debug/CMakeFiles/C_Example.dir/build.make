# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/HouXinLin/apps/Developer/CLion-2021.2.1/clion-2021.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/HouXinLin/apps/Developer/CLion-2021.2.1/clion-2021.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/HouXinLin/project/c/C-Example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/HouXinLin/project/c/C-Example/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/C_Example.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/C_Example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C_Example.dir/flags.make

CMakeFiles/C_Example.dir/example/数组合并.c.o: CMakeFiles/C_Example.dir/flags.make
CMakeFiles/C_Example.dir/example/数组合并.c.o: ../example/数组合并.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/HouXinLin/project/c/C-Example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/C_Example.dir/example/数组合并.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C_Example.dir/example/数组合并.c.o -c /home/HouXinLin/project/c/C-Example/example/数组合并.c

CMakeFiles/C_Example.dir/example/数组合并.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C_Example.dir/example/数组合并.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/HouXinLin/project/c/C-Example/example/数组合并.c > CMakeFiles/C_Example.dir/example/数组合并.c.i

CMakeFiles/C_Example.dir/example/数组合并.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C_Example.dir/example/数组合并.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/HouXinLin/project/c/C-Example/example/数组合并.c -o CMakeFiles/C_Example.dir/example/数组合并.c.s

# Object files for target C_Example
C_Example_OBJECTS = \
"CMakeFiles/C_Example.dir/example/数组合并.c.o"

# External object files for target C_Example
C_Example_EXTERNAL_OBJECTS =

C_Example: CMakeFiles/C_Example.dir/example/数组合并.c.o
C_Example: CMakeFiles/C_Example.dir/build.make
C_Example: CMakeFiles/C_Example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/HouXinLin/project/c/C-Example/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable C_Example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/C_Example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C_Example.dir/build: C_Example
.PHONY : CMakeFiles/C_Example.dir/build

CMakeFiles/C_Example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/C_Example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/C_Example.dir/clean

CMakeFiles/C_Example.dir/depend:
	cd /home/HouXinLin/project/c/C-Example/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/HouXinLin/project/c/C-Example /home/HouXinLin/project/c/C-Example /home/HouXinLin/project/c/C-Example/cmake-build-debug /home/HouXinLin/project/c/C-Example/cmake-build-debug /home/HouXinLin/project/c/C-Example/cmake-build-debug/CMakeFiles/C_Example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C_Example.dir/depend

