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
CMAKE_SOURCE_DIR = C:\Users\jbji\CLionProjects\bestScore

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jbji\CLionProjects\bestScore\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bestScore.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bestScore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bestScore.dir/flags.make

CMakeFiles/bestScore.dir/main.cpp.obj: CMakeFiles/bestScore.dir/flags.make
CMakeFiles/bestScore.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\bestScore\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bestScore.dir/main.cpp.obj"
	"D:\Program Files\mingw64\bin\G__~1.EXE"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\bestScore.dir\main.cpp.obj -c C:\Users\jbji\CLionProjects\bestScore\main.cpp

CMakeFiles/bestScore.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bestScore.dir/main.cpp.i"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jbji\CLionProjects\bestScore\main.cpp > CMakeFiles\bestScore.dir\main.cpp.i

CMakeFiles/bestScore.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bestScore.dir/main.cpp.s"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jbji\CLionProjects\bestScore\main.cpp -o CMakeFiles\bestScore.dir\main.cpp.s

# Object files for target bestScore
bestScore_OBJECTS = \
"CMakeFiles/bestScore.dir/main.cpp.obj"

# External object files for target bestScore
bestScore_EXTERNAL_OBJECTS =

bestScore.exe: CMakeFiles/bestScore.dir/main.cpp.obj
bestScore.exe: CMakeFiles/bestScore.dir/build.make
bestScore.exe: CMakeFiles/bestScore.dir/linklibs.rsp
bestScore.exe: CMakeFiles/bestScore.dir/objects1.rsp
bestScore.exe: CMakeFiles/bestScore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jbji\CLionProjects\bestScore\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bestScore.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bestScore.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bestScore.dir/build: bestScore.exe

.PHONY : CMakeFiles/bestScore.dir/build

CMakeFiles/bestScore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bestScore.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bestScore.dir/clean

CMakeFiles/bestScore.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jbji\CLionProjects\bestScore C:\Users\jbji\CLionProjects\bestScore C:\Users\jbji\CLionProjects\bestScore\cmake-build-debug C:\Users\jbji\CLionProjects\bestScore\cmake-build-debug C:\Users\jbji\CLionProjects\bestScore\cmake-build-debug\CMakeFiles\bestScore.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bestScore.dir/depend
