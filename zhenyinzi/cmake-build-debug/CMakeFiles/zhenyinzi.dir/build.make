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
CMAKE_SOURCE_DIR = C:\Users\jbji\CLionProjects\zhenyinzi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jbji\CLionProjects\zhenyinzi\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zhenyinzi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zhenyinzi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zhenyinzi.dir/flags.make

CMakeFiles/zhenyinzi.dir/main.cpp.obj: CMakeFiles/zhenyinzi.dir/flags.make
CMakeFiles/zhenyinzi.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\zhenyinzi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zhenyinzi.dir/main.cpp.obj"
	"D:\Program Files\mingw64\bin\G__~1.EXE"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\zhenyinzi.dir\main.cpp.obj -c C:\Users\jbji\CLionProjects\zhenyinzi\main.cpp

CMakeFiles/zhenyinzi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zhenyinzi.dir/main.cpp.i"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jbji\CLionProjects\zhenyinzi\main.cpp > CMakeFiles\zhenyinzi.dir\main.cpp.i

CMakeFiles/zhenyinzi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zhenyinzi.dir/main.cpp.s"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jbji\CLionProjects\zhenyinzi\main.cpp -o CMakeFiles\zhenyinzi.dir\main.cpp.s

# Object files for target zhenyinzi
zhenyinzi_OBJECTS = \
"CMakeFiles/zhenyinzi.dir/main.cpp.obj"

# External object files for target zhenyinzi
zhenyinzi_EXTERNAL_OBJECTS =

zhenyinzi.exe: CMakeFiles/zhenyinzi.dir/main.cpp.obj
zhenyinzi.exe: CMakeFiles/zhenyinzi.dir/build.make
zhenyinzi.exe: CMakeFiles/zhenyinzi.dir/linklibs.rsp
zhenyinzi.exe: CMakeFiles/zhenyinzi.dir/objects1.rsp
zhenyinzi.exe: CMakeFiles/zhenyinzi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jbji\CLionProjects\zhenyinzi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zhenyinzi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zhenyinzi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zhenyinzi.dir/build: zhenyinzi.exe

.PHONY : CMakeFiles/zhenyinzi.dir/build

CMakeFiles/zhenyinzi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zhenyinzi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zhenyinzi.dir/clean

CMakeFiles/zhenyinzi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jbji\CLionProjects\zhenyinzi C:\Users\jbji\CLionProjects\zhenyinzi C:\Users\jbji\CLionProjects\zhenyinzi\cmake-build-debug C:\Users\jbji\CLionProjects\zhenyinzi\cmake-build-debug C:\Users\jbji\CLionProjects\zhenyinzi\cmake-build-debug\CMakeFiles\zhenyinzi.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zhenyinzi.dir/depend

