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
CMAKE_SOURCE_DIR = C:\Users\jbji\CLionProjects\learning_pointer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jbji\CLionProjects\learning_pointer\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/learning_pointer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learning_pointer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learning_pointer.dir/flags.make

CMakeFiles/learning_pointer.dir/main.c.obj: CMakeFiles/learning_pointer.dir/flags.make
CMakeFiles/learning_pointer.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\learning_pointer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/learning_pointer.dir/main.c.obj"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\learning_pointer.dir\main.c.obj   -c C:\Users\jbji\CLionProjects\learning_pointer\main.c

CMakeFiles/learning_pointer.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/learning_pointer.dir/main.c.i"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\jbji\CLionProjects\learning_pointer\main.c > CMakeFiles\learning_pointer.dir\main.c.i

CMakeFiles/learning_pointer.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/learning_pointer.dir/main.c.s"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\jbji\CLionProjects\learning_pointer\main.c -o CMakeFiles\learning_pointer.dir\main.c.s

# Object files for target learning_pointer
learning_pointer_OBJECTS = \
"CMakeFiles/learning_pointer.dir/main.c.obj"

# External object files for target learning_pointer
learning_pointer_EXTERNAL_OBJECTS =

learning_pointer.exe: CMakeFiles/learning_pointer.dir/main.c.obj
learning_pointer.exe: CMakeFiles/learning_pointer.dir/build.make
learning_pointer.exe: CMakeFiles/learning_pointer.dir/linklibs.rsp
learning_pointer.exe: CMakeFiles/learning_pointer.dir/objects1.rsp
learning_pointer.exe: CMakeFiles/learning_pointer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jbji\CLionProjects\learning_pointer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable learning_pointer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\learning_pointer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learning_pointer.dir/build: learning_pointer.exe

.PHONY : CMakeFiles/learning_pointer.dir/build

CMakeFiles/learning_pointer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\learning_pointer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/learning_pointer.dir/clean

CMakeFiles/learning_pointer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jbji\CLionProjects\learning_pointer C:\Users\jbji\CLionProjects\learning_pointer C:\Users\jbji\CLionProjects\learning_pointer\cmake-build-debug C:\Users\jbji\CLionProjects\learning_pointer\cmake-build-debug C:\Users\jbji\CLionProjects\learning_pointer\cmake-build-debug\CMakeFiles\learning_pointer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learning_pointer.dir/depend
