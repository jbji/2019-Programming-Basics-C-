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
CMAKE_SOURCE_DIR = C:\Users\jbji\CLionProjects\58twodimmartix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jbji\CLionProjects\58twodimmartix\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/58twodimmartix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/58twodimmartix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/58twodimmartix.dir/flags.make

CMakeFiles/58twodimmartix.dir/main.c.obj: CMakeFiles/58twodimmartix.dir/flags.make
CMakeFiles/58twodimmartix.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\58twodimmartix\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/58twodimmartix.dir/main.c.obj"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\58twodimmartix.dir\main.c.obj   -c C:\Users\jbji\CLionProjects\58twodimmartix\main.c

CMakeFiles/58twodimmartix.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/58twodimmartix.dir/main.c.i"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\jbji\CLionProjects\58twodimmartix\main.c > CMakeFiles\58twodimmartix.dir\main.c.i

CMakeFiles/58twodimmartix.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/58twodimmartix.dir/main.c.s"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\jbji\CLionProjects\58twodimmartix\main.c -o CMakeFiles\58twodimmartix.dir\main.c.s

# Object files for target 58twodimmartix
58twodimmartix_OBJECTS = \
"CMakeFiles/58twodimmartix.dir/main.c.obj"

# External object files for target 58twodimmartix
58twodimmartix_EXTERNAL_OBJECTS =

58twodimmartix.exe: CMakeFiles/58twodimmartix.dir/main.c.obj
58twodimmartix.exe: CMakeFiles/58twodimmartix.dir/build.make
58twodimmartix.exe: CMakeFiles/58twodimmartix.dir/linklibs.rsp
58twodimmartix.exe: CMakeFiles/58twodimmartix.dir/objects1.rsp
58twodimmartix.exe: CMakeFiles/58twodimmartix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jbji\CLionProjects\58twodimmartix\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 58twodimmartix.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\58twodimmartix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/58twodimmartix.dir/build: 58twodimmartix.exe

.PHONY : CMakeFiles/58twodimmartix.dir/build

CMakeFiles/58twodimmartix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\58twodimmartix.dir\cmake_clean.cmake
.PHONY : CMakeFiles/58twodimmartix.dir/clean

CMakeFiles/58twodimmartix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jbji\CLionProjects\58twodimmartix C:\Users\jbji\CLionProjects\58twodimmartix C:\Users\jbji\CLionProjects\58twodimmartix\cmake-build-debug C:\Users\jbji\CLionProjects\58twodimmartix\cmake-build-debug C:\Users\jbji\CLionProjects\58twodimmartix\cmake-build-debug\CMakeFiles\58twodimmartix.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/58twodimmartix.dir/depend

