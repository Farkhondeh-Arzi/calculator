# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\installed files\CLion 2020.2.4\clion\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\installed files\CLion 2020.2.4\clion\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Ir_Informatic\CLionProjects\forth exercise"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Ir_Informatic\CLionProjects\forth exercise\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/forth_excercise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/forth_excercise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/forth_excercise.dir/flags.make

CMakeFiles/forth_excercise.dir/source.cpp.obj: CMakeFiles/forth_excercise.dir/flags.make
CMakeFiles/forth_excercise.dir/source.cpp.obj: ../source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Ir_Informatic\CLionProjects\forth exercise\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/forth_excercise.dir/source.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\forth_excercise.dir\source.cpp.obj -c "C:\Users\Ir_Informatic\CLionProjects\forth exercise\source.cpp"

CMakeFiles/forth_excercise.dir/source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/forth_excercise.dir/source.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Ir_Informatic\CLionProjects\forth exercise\source.cpp" > CMakeFiles\forth_excercise.dir\source.cpp.i

CMakeFiles/forth_excercise.dir/source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/forth_excercise.dir/source.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Ir_Informatic\CLionProjects\forth exercise\source.cpp" -o CMakeFiles\forth_excercise.dir\source.cpp.s

# Object files for target forth_excercise
forth_excercise_OBJECTS = \
"CMakeFiles/forth_excercise.dir/source.cpp.obj"

# External object files for target forth_excercise
forth_excercise_EXTERNAL_OBJECTS =

forth_excercise.exe: CMakeFiles/forth_excercise.dir/source.cpp.obj
forth_excercise.exe: CMakeFiles/forth_excercise.dir/build.make
forth_excercise.exe: CMakeFiles/forth_excercise.dir/linklibs.rsp
forth_excercise.exe: CMakeFiles/forth_excercise.dir/objects1.rsp
forth_excercise.exe: CMakeFiles/forth_excercise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Ir_Informatic\CLionProjects\forth exercise\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable forth_excercise.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\forth_excercise.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/forth_excercise.dir/build: forth_excercise.exe

.PHONY : CMakeFiles/forth_excercise.dir/build

CMakeFiles/forth_excercise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\forth_excercise.dir\cmake_clean.cmake
.PHONY : CMakeFiles/forth_excercise.dir/clean

CMakeFiles/forth_excercise.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Ir_Informatic\CLionProjects\forth exercise" "C:\Users\Ir_Informatic\CLionProjects\forth exercise" "C:\Users\Ir_Informatic\CLionProjects\forth exercise\cmake-build-debug" "C:\Users\Ir_Informatic\CLionProjects\forth exercise\cmake-build-debug" "C:\Users\Ir_Informatic\CLionProjects\forth exercise\cmake-build-debug\CMakeFiles\forth_excercise.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/forth_excercise.dir/depend

