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
CMAKE_SOURCE_DIR = C:\Users\jbji\CLionProjects\PiC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jbji\CLionProjects\PiC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PiC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PiC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PiC.dir/flags.make

CMakeFiles/PiC.dir/main.c.obj: CMakeFiles/PiC.dir/flags.make
CMakeFiles/PiC.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\PiC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PiC.dir/main.c.obj"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PiC.dir\main.c.obj   -c C:\Users\jbji\CLionProjects\PiC\main.c

CMakeFiles/PiC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PiC.dir/main.c.i"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\jbji\CLionProjects\PiC\main.c > CMakeFiles\PiC.dir\main.c.i

CMakeFiles/PiC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PiC.dir/main.c.s"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\jbji\CLionProjects\PiC\main.c -o CMakeFiles\PiC.dir\main.c.s

# Object files for target PiC
PiC_OBJECTS = \
"CMakeFiles/PiC.dir/main.c.obj"

# External object files for target PiC
PiC_EXTERNAL_OBJECTS =

PiC.exe: CMakeFiles/PiC.dir/main.c.obj
PiC.exe: CMakeFiles/PiC.dir/build.make
PiC.exe: CMakeFiles/PiC.dir/linklibs.rsp
PiC.exe: CMakeFiles/PiC.dir/objects1.rsp
PiC.exe: CMakeFiles/PiC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jbji\CLionProjects\PiC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PiC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PiC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PiC.dir/build: PiC.exe

.PHONY : CMakeFiles/PiC.dir/build

CMakeFiles/PiC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PiC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PiC.dir/clean

CMakeFiles/PiC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jbji\CLionProjects\PiC C:\Users\jbji\CLionProjects\PiC C:\Users\jbji\CLionProjects\PiC\cmake-build-debug C:\Users\jbji\CLionProjects\PiC\cmake-build-debug C:\Users\jbji\CLionProjects\PiC\cmake-build-debug\CMakeFiles\PiC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PiC.dir/depend
