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
CMAKE_SOURCE_DIR = C:\Users\jbji\CLionProjects\eduscorestatistic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jbji\CLionProjects\eduscorestatistic\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/eduscorestatistic.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/eduscorestatistic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/eduscorestatistic.dir/flags.make

CMakeFiles/eduscorestatistic.dir/main.cpp.obj: CMakeFiles/eduscorestatistic.dir/flags.make
CMakeFiles/eduscorestatistic.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\eduscorestatistic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/eduscorestatistic.dir/main.cpp.obj"
	"D:\Program Files\mingw64\bin\G__~1.EXE"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\eduscorestatistic.dir\main.cpp.obj -c C:\Users\jbji\CLionProjects\eduscorestatistic\main.cpp

CMakeFiles/eduscorestatistic.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eduscorestatistic.dir/main.cpp.i"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jbji\CLionProjects\eduscorestatistic\main.cpp > CMakeFiles\eduscorestatistic.dir\main.cpp.i

CMakeFiles/eduscorestatistic.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eduscorestatistic.dir/main.cpp.s"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jbji\CLionProjects\eduscorestatistic\main.cpp -o CMakeFiles\eduscorestatistic.dir\main.cpp.s

CMakeFiles/eduscorestatistic.dir/Student.cpp.obj: CMakeFiles/eduscorestatistic.dir/flags.make
CMakeFiles/eduscorestatistic.dir/Student.cpp.obj: ../Student.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jbji\CLionProjects\eduscorestatistic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/eduscorestatistic.dir/Student.cpp.obj"
	"D:\Program Files\mingw64\bin\G__~1.EXE"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\eduscorestatistic.dir\Student.cpp.obj -c C:\Users\jbji\CLionProjects\eduscorestatistic\Student.cpp

CMakeFiles/eduscorestatistic.dir/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eduscorestatistic.dir/Student.cpp.i"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jbji\CLionProjects\eduscorestatistic\Student.cpp > CMakeFiles\eduscorestatistic.dir\Student.cpp.i

CMakeFiles/eduscorestatistic.dir/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eduscorestatistic.dir/Student.cpp.s"
	"D:\Program Files\mingw64\bin\G__~1.EXE" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jbji\CLionProjects\eduscorestatistic\Student.cpp -o CMakeFiles\eduscorestatistic.dir\Student.cpp.s

# Object files for target eduscorestatistic
eduscorestatistic_OBJECTS = \
"CMakeFiles/eduscorestatistic.dir/main.cpp.obj" \
"CMakeFiles/eduscorestatistic.dir/Student.cpp.obj"

# External object files for target eduscorestatistic
eduscorestatistic_EXTERNAL_OBJECTS =

eduscorestatistic.exe: CMakeFiles/eduscorestatistic.dir/main.cpp.obj
eduscorestatistic.exe: CMakeFiles/eduscorestatistic.dir/Student.cpp.obj
eduscorestatistic.exe: CMakeFiles/eduscorestatistic.dir/build.make
eduscorestatistic.exe: CMakeFiles/eduscorestatistic.dir/linklibs.rsp
eduscorestatistic.exe: CMakeFiles/eduscorestatistic.dir/objects1.rsp
eduscorestatistic.exe: CMakeFiles/eduscorestatistic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jbji\CLionProjects\eduscorestatistic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable eduscorestatistic.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\eduscorestatistic.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/eduscorestatistic.dir/build: eduscorestatistic.exe

.PHONY : CMakeFiles/eduscorestatistic.dir/build

CMakeFiles/eduscorestatistic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\eduscorestatistic.dir\cmake_clean.cmake
.PHONY : CMakeFiles/eduscorestatistic.dir/clean

CMakeFiles/eduscorestatistic.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jbji\CLionProjects\eduscorestatistic C:\Users\jbji\CLionProjects\eduscorestatistic C:\Users\jbji\CLionProjects\eduscorestatistic\cmake-build-debug C:\Users\jbji\CLionProjects\eduscorestatistic\cmake-build-debug C:\Users\jbji\CLionProjects\eduscorestatistic\cmake-build-debug\CMakeFiles\eduscorestatistic.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/eduscorestatistic.dir/depend

