# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/grig/Documents/1. Projects/college/pg/lab1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/grig/Documents/1. Projects/college/pg/lab1/cmake"

# Include any dependencies generated for this target.
include CMakeFiles/YourApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/YourApp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/YourApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/YourApp.dir/flags.make

CMakeFiles/YourApp.dir/src/main.cpp.o: CMakeFiles/YourApp.dir/flags.make
CMakeFiles/YourApp.dir/src/main.cpp.o: /Users/grig/Documents/1.\ Projects/college/pg/lab1/src/main.cpp
CMakeFiles/YourApp.dir/src/main.cpp.o: CMakeFiles/YourApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/grig/Documents/1. Projects/college/pg/lab1/cmake/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/YourApp.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/YourApp.dir/src/main.cpp.o -MF CMakeFiles/YourApp.dir/src/main.cpp.o.d -o CMakeFiles/YourApp.dir/src/main.cpp.o -c "/Users/grig/Documents/1. Projects/college/pg/lab1/src/main.cpp"

CMakeFiles/YourApp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/YourApp.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/grig/Documents/1. Projects/college/pg/lab1/src/main.cpp" > CMakeFiles/YourApp.dir/src/main.cpp.i

CMakeFiles/YourApp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/YourApp.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/grig/Documents/1. Projects/college/pg/lab1/src/main.cpp" -o CMakeFiles/YourApp.dir/src/main.cpp.s

CMakeFiles/YourApp.dir/src/GPSLab1.cpp.o: CMakeFiles/YourApp.dir/flags.make
CMakeFiles/YourApp.dir/src/GPSLab1.cpp.o: /Users/grig/Documents/1.\ Projects/college/pg/lab1/src/GPSLab1.cpp
CMakeFiles/YourApp.dir/src/GPSLab1.cpp.o: CMakeFiles/YourApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/grig/Documents/1. Projects/college/pg/lab1/cmake/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/YourApp.dir/src/GPSLab1.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/YourApp.dir/src/GPSLab1.cpp.o -MF CMakeFiles/YourApp.dir/src/GPSLab1.cpp.o.d -o CMakeFiles/YourApp.dir/src/GPSLab1.cpp.o -c "/Users/grig/Documents/1. Projects/college/pg/lab1/src/GPSLab1.cpp"

CMakeFiles/YourApp.dir/src/GPSLab1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/YourApp.dir/src/GPSLab1.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/grig/Documents/1. Projects/college/pg/lab1/src/GPSLab1.cpp" > CMakeFiles/YourApp.dir/src/GPSLab1.cpp.i

CMakeFiles/YourApp.dir/src/GPSLab1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/YourApp.dir/src/GPSLab1.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/grig/Documents/1. Projects/college/pg/lab1/src/GPSLab1.cpp" -o CMakeFiles/YourApp.dir/src/GPSLab1.cpp.s

# Object files for target YourApp
YourApp_OBJECTS = \
"CMakeFiles/YourApp.dir/src/main.cpp.o" \
"CMakeFiles/YourApp.dir/src/GPSLab1.cpp.o"

# External object files for target YourApp
YourApp_EXTERNAL_OBJECTS =

YourApp: CMakeFiles/YourApp.dir/src/main.cpp.o
YourApp: CMakeFiles/YourApp.dir/src/GPSLab1.cpp.o
YourApp: CMakeFiles/YourApp.dir/build.make
YourApp: libs/glm/glm/libglm.a
YourApp: CMakeFiles/YourApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/grig/Documents/1. Projects/college/pg/lab1/cmake/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable YourApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/YourApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/YourApp.dir/build: YourApp
.PHONY : CMakeFiles/YourApp.dir/build

CMakeFiles/YourApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/YourApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/YourApp.dir/clean

CMakeFiles/YourApp.dir/depend:
	cd "/Users/grig/Documents/1. Projects/college/pg/lab1/cmake" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/grig/Documents/1. Projects/college/pg/lab1" "/Users/grig/Documents/1. Projects/college/pg/lab1" "/Users/grig/Documents/1. Projects/college/pg/lab1/cmake" "/Users/grig/Documents/1. Projects/college/pg/lab1/cmake" "/Users/grig/Documents/1. Projects/college/pg/lab1/cmake/CMakeFiles/YourApp.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/YourApp.dir/depend

