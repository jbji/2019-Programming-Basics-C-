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
CMAKE_SOURCE_DIR = C:\Users\jbji\CLionProjects\redpocketcalc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jbji\CLionProjects\redpocketcalc\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/redpocketcalc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/redpocketcalc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/redpocketcalc.dir/flags.make

CMakeFiles/redpocketcalc.dir/main.cpp.obj: CMakeFiles/redpocketcalc.dir/flags.make
CMakeFiles/redpocketcalc.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\redpocketcalc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/redpocketcalc.dir/main.cpp.obj"
	"D:\Program Files\mingw64\bin\G__~1.EXE"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\redpocketcalc.dir\main.cpp.obj -c C:\Users\jbji\CLionProjects\redpocketcalc\main.cpp

CMakeFiles/redpocketcalc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redpocketcalc.dir/main.cpp.i"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jbji\CLionProjects\redpocketcalc\main.cpp > CMakeFiles\redpocketcalc.dir\main.cpp.i

CMakeFiles/redpocketcalc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redpocketcalc.dir/main.cpp.s"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jbji\CLionProjects\redpocketcalc\main.cpp -o CMakeFiles\redpocketcalc.dir\main.cpp.s

# Object files for target redpocketcalc
redpocketcalc_OBJECTS = \
"CMakeFiles/redpocketcalc.dir/main.cpp.obj"

# External object files for target redpocketcalc
redpocketcalc_EXTERNAL_OBJECTS =

redpocketcalc.exe: CMakeFiles/redpocketcalc.dir/main.cpp.obj
redpocketcalc.exe: CMakeFiles/redpocketcalc.dir/build.make
redpocketcalc.exe: CMakeFiles/redpocketcalc.dir/linklibs.rsp
redpocketcalc.exe: CMakeFiles/redpocketcalc.dir/objects1.rsp
redpocketcalc.exe: CMakeFiles/redpocketcalc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jbji\CLionProjects\redpocketcalc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable redpocketcalc.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\redpocketcalc.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/redpocketcalc.dir/build: redpocketcalc.exe

.PHONY : CMakeFiles/redpocketcalc.dir/build

CMakeFiles/redpocketcalc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\redpocketcalc.dir\cmake_clean.cmake
.PHONY : CMakeFiles/redpocketcalc.dir/clean

CMakeFiles/redpocketcalc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jbji\CLionProjects\redpocketcalc C:\Users\jbji\CLionProjects\redpocketcalc C:\Users\jbji\CLionProjects\redpocketcalc\cmake-build-debug C:\Users\jbji\CLionProjects\redpocketcalc\cmake-build-debug C:\Users\jbji\CLionProjects\redpocketcalc\cmake-build-debug\CMakeFiles\redpocketcalc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/redpocketcalc.dir/depend

