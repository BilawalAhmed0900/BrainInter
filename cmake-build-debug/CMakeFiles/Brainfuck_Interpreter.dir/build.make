# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Brainfuck_Interpreter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Brainfuck_Interpreter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Brainfuck_Interpreter.dir/flags.make

CMakeFiles/Brainfuck_Interpreter.dir/main.cpp.obj: CMakeFiles/Brainfuck_Interpreter.dir/flags.make
CMakeFiles/Brainfuck_Interpreter.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Brainfuck_Interpreter.dir/main.cpp.obj"
	C:\PROGRA~2\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Brainfuck_Interpreter.dir\main.cpp.obj -c "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\main.cpp"

CMakeFiles/Brainfuck_Interpreter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Brainfuck_Interpreter.dir/main.cpp.i"
	C:\PROGRA~2\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\main.cpp" > CMakeFiles\Brainfuck_Interpreter.dir\main.cpp.i

CMakeFiles/Brainfuck_Interpreter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Brainfuck_Interpreter.dir/main.cpp.s"
	C:\PROGRA~2\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\main.cpp" -o CMakeFiles\Brainfuck_Interpreter.dir\main.cpp.s

CMakeFiles/Brainfuck_Interpreter.dir/interpreter.cpp.obj: CMakeFiles/Brainfuck_Interpreter.dir/flags.make
CMakeFiles/Brainfuck_Interpreter.dir/interpreter.cpp.obj: ../interpreter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Brainfuck_Interpreter.dir/interpreter.cpp.obj"
	C:\PROGRA~2\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Brainfuck_Interpreter.dir\interpreter.cpp.obj -c "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\interpreter.cpp"

CMakeFiles/Brainfuck_Interpreter.dir/interpreter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Brainfuck_Interpreter.dir/interpreter.cpp.i"
	C:\PROGRA~2\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\interpreter.cpp" > CMakeFiles\Brainfuck_Interpreter.dir\interpreter.cpp.i

CMakeFiles/Brainfuck_Interpreter.dir/interpreter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Brainfuck_Interpreter.dir/interpreter.cpp.s"
	C:\PROGRA~2\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\interpreter.cpp" -o CMakeFiles\Brainfuck_Interpreter.dir\interpreter.cpp.s

# Object files for target Brainfuck_Interpreter
Brainfuck_Interpreter_OBJECTS = \
"CMakeFiles/Brainfuck_Interpreter.dir/main.cpp.obj" \
"CMakeFiles/Brainfuck_Interpreter.dir/interpreter.cpp.obj"

# External object files for target Brainfuck_Interpreter
Brainfuck_Interpreter_EXTERNAL_OBJECTS =

Brainfuck_Interpreter.exe: CMakeFiles/Brainfuck_Interpreter.dir/main.cpp.obj
Brainfuck_Interpreter.exe: CMakeFiles/Brainfuck_Interpreter.dir/interpreter.cpp.obj
Brainfuck_Interpreter.exe: CMakeFiles/Brainfuck_Interpreter.dir/build.make
Brainfuck_Interpreter.exe: CMakeFiles/Brainfuck_Interpreter.dir/linklibs.rsp
Brainfuck_Interpreter.exe: CMakeFiles/Brainfuck_Interpreter.dir/objects1.rsp
Brainfuck_Interpreter.exe: CMakeFiles/Brainfuck_Interpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Brainfuck_Interpreter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Brainfuck_Interpreter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Brainfuck_Interpreter.dir/build: Brainfuck_Interpreter.exe

.PHONY : CMakeFiles/Brainfuck_Interpreter.dir/build

CMakeFiles/Brainfuck_Interpreter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Brainfuck_Interpreter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Brainfuck_Interpreter.dir/clean

CMakeFiles/Brainfuck_Interpreter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter" "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter" "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\cmake-build-debug" "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\cmake-build-debug" "C:\Users\Mian Bilawal\CLionProjects\Brainfuck_Interpreter\cmake-build-debug\CMakeFiles\Brainfuck_Interpreter.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Brainfuck_Interpreter.dir/depend

