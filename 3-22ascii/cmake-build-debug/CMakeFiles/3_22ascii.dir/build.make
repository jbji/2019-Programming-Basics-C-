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
CMAKE_SOURCE_DIR = C:\Users\jbji\CLionProjects\3-22ascii

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jbji\CLionProjects\3-22ascii\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/3_22ascii.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3_22ascii.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3_22ascii.dir/flags.make

CMakeFiles/3_22ascii.dir/main.cpp.obj: CMakeFiles/3_22ascii.dir/flags.make
CMakeFiles/3_22ascii.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\3-22ascii\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3_22ascii.dir/main.cpp.obj"
	"D:\Program Files\mingw64\bin\G__~1.EXE"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\3_22ascii.dir\main.cpp.obj -c C:\Users\jbji\CLionProjects\3-22ascii\main.cpp

CMakeFiles/3_22ascii.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3_22ascii.dir/main.cpp.i"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jbji\CLionProjects\3-22ascii\main.cpp > CMakeFiles\3_22ascii.dir\main.cpp.i

CMakeFiles/3_22ascii.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3_22ascii.dir/main.cpp.s"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jbji\CLionProjects\3-22ascii\main.cpp -o CMakeFiles\3_22ascii.dir\main.cpp.s

# Object files for target 3_22ascii
3_22ascii_OBJECTS = \
"CMakeFiles/3_22ascii.dir/main.cpp.obj"

# External object files for target 3_22ascii
3_22ascii_EXTERNAL_OBJECTS =

3_22ascii.exe: CMakeFiles/3_22ascii.dir/main.cpp.obj
3_22ascii.exe: CMakeFiles/3_22ascii.dir/build.make
3_22ascii.exe: CMakeFiles/3_22ascii.dir/linklibs.rsp
3_22ascii.exe: CMakeFiles/3_22ascii.dir/objects1.rsp
3_22ascii.exe: CMakeFiles/3_22ascii.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jbji\CLionProjects\3-22ascii\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3_22ascii.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\3_22ascii.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3_22ascii.dir/build: 3_22ascii.exe

.PHONY : CMakeFiles/3_22ascii.dir/build

CMakeFiles/3_22ascii.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\3_22ascii.dir\cmake_clean.cmake
.PHONY : CMakeFiles/3_22ascii.dir/clean

CMakeFiles/3_22ascii.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jbji\CLionProjects\3-22ascii C:\Users\jbji\CLionProjects\3-22ascii C:\Users\jbji\CLionProjects\3-22ascii\cmake-build-debug C:\Users\jbji\CLionProjects\3-22ascii\cmake-build-debug C:\Users\jbji\CLionProjects\3-22ascii\cmake-build-debug\CMakeFiles\3_22ascii.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3_22ascii.dir/depend
