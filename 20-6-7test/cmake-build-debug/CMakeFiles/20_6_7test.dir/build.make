# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jbji\CLionProjects\20-6-7test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jbji\CLionProjects\20-6-7test\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/20_6_7test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/20_6_7test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/20_6_7test.dir/flags.make

CMakeFiles/20_6_7test.dir/main.cpp.obj: CMakeFiles/20_6_7test.dir/flags.make
CMakeFiles/20_6_7test.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\20-6-7test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/20_6_7test.dir/main.cpp.obj"
	"D:\Program Files\mingw64\bin\G__~1.EXE"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\20_6_7test.dir\main.cpp.obj -c C:\Users\jbji\CLionProjects\20-6-7test\main.cpp

CMakeFiles/20_6_7test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/20_6_7test.dir/main.cpp.i"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jbji\CLionProjects\20-6-7test\main.cpp > CMakeFiles\20_6_7test.dir\main.cpp.i

CMakeFiles/20_6_7test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/20_6_7test.dir/main.cpp.s"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jbji\CLionProjects\20-6-7test\main.cpp -o CMakeFiles\20_6_7test.dir\main.cpp.s

# Object files for target 20_6_7test
20_6_7test_OBJECTS = \
"CMakeFiles/20_6_7test.dir/main.cpp.obj"

# External object files for target 20_6_7test
20_6_7test_EXTERNAL_OBJECTS =

20_6_7test.exe: CMakeFiles/20_6_7test.dir/main.cpp.obj
20_6_7test.exe: CMakeFiles/20_6_7test.dir/build.make
20_6_7test.exe: CMakeFiles/20_6_7test.dir/linklibs.rsp
20_6_7test.exe: CMakeFiles/20_6_7test.dir/objects1.rsp
20_6_7test.exe: CMakeFiles/20_6_7test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jbji\CLionProjects\20-6-7test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 20_6_7test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\20_6_7test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/20_6_7test.dir/build: 20_6_7test.exe

.PHONY : CMakeFiles/20_6_7test.dir/build

CMakeFiles/20_6_7test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\20_6_7test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/20_6_7test.dir/clean

CMakeFiles/20_6_7test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jbji\CLionProjects\20-6-7test C:\Users\jbji\CLionProjects\20-6-7test C:\Users\jbji\CLionProjects\20-6-7test\cmake-build-debug C:\Users\jbji\CLionProjects\20-6-7test\cmake-build-debug C:\Users\jbji\CLionProjects\20-6-7test\cmake-build-debug\CMakeFiles\20_6_7test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/20_6_7test.dir/depend

