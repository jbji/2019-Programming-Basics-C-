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
CMAKE_SOURCE_DIR = C:\Users\jbji\CLionProjects\60badGirlFriend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jbji\CLionProjects\60badGirlFriend\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/60badGirlFriend.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/60badGirlFriend.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/60badGirlFriend.dir/flags.make

CMakeFiles/60badGirlFriend.dir/main.c.obj: CMakeFiles/60badGirlFriend.dir/flags.make
CMakeFiles/60badGirlFriend.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\60badGirlFriend\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/60badGirlFriend.dir/main.c.obj"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\60badGirlFriend.dir\main.c.obj   -c C:\Users\jbji\CLionProjects\60badGirlFriend\main.c

CMakeFiles/60badGirlFriend.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/60badGirlFriend.dir/main.c.i"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\jbji\CLionProjects\60badGirlFriend\main.c > CMakeFiles\60badGirlFriend.dir\main.c.i

CMakeFiles/60badGirlFriend.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/60badGirlFriend.dir/main.c.s"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\jbji\CLionProjects\60badGirlFriend\main.c -o CMakeFiles\60badGirlFriend.dir\main.c.s

# Object files for target 60badGirlFriend
60badGirlFriend_OBJECTS = \
"CMakeFiles/60badGirlFriend.dir/main.c.obj"

# External object files for target 60badGirlFriend
60badGirlFriend_EXTERNAL_OBJECTS =

60badGirlFriend.exe: CMakeFiles/60badGirlFriend.dir/main.c.obj
60badGirlFriend.exe: CMakeFiles/60badGirlFriend.dir/build.make
60badGirlFriend.exe: CMakeFiles/60badGirlFriend.dir/linklibs.rsp
60badGirlFriend.exe: CMakeFiles/60badGirlFriend.dir/objects1.rsp
60badGirlFriend.exe: CMakeFiles/60badGirlFriend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jbji\CLionProjects\60badGirlFriend\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 60badGirlFriend.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\60badGirlFriend.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/60badGirlFriend.dir/build: 60badGirlFriend.exe

.PHONY : CMakeFiles/60badGirlFriend.dir/build

CMakeFiles/60badGirlFriend.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\60badGirlFriend.dir\cmake_clean.cmake
.PHONY : CMakeFiles/60badGirlFriend.dir/clean

CMakeFiles/60badGirlFriend.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jbji\CLionProjects\60badGirlFriend C:\Users\jbji\CLionProjects\60badGirlFriend C:\Users\jbji\CLionProjects\60badGirlFriend\cmake-build-debug C:\Users\jbji\CLionProjects\60badGirlFriend\cmake-build-debug C:\Users\jbji\CLionProjects\60badGirlFriend\cmake-build-debug\CMakeFiles\60badGirlFriend.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/60badGirlFriend.dir/depend
