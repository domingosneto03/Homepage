# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/luiscontreiras/ProjectAED_G24

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/luiscontreiras/ProjectAED_G24/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjectAED_G24.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProjectAED_G24.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjectAED_G24.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjectAED_G24.dir/flags.make

CMakeFiles/ProjectAED_G24.dir/main.cpp.o: CMakeFiles/ProjectAED_G24.dir/flags.make
CMakeFiles/ProjectAED_G24.dir/main.cpp.o: ../main.cpp
CMakeFiles/ProjectAED_G24.dir/main.cpp.o: CMakeFiles/ProjectAED_G24.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/luiscontreiras/ProjectAED_G24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProjectAED_G24.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjectAED_G24.dir/main.cpp.o -MF CMakeFiles/ProjectAED_G24.dir/main.cpp.o.d -o CMakeFiles/ProjectAED_G24.dir/main.cpp.o -c /Users/luiscontreiras/ProjectAED_G24/main.cpp

CMakeFiles/ProjectAED_G24.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectAED_G24.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/luiscontreiras/ProjectAED_G24/main.cpp > CMakeFiles/ProjectAED_G24.dir/main.cpp.i

CMakeFiles/ProjectAED_G24.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectAED_G24.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/luiscontreiras/ProjectAED_G24/main.cpp -o CMakeFiles/ProjectAED_G24.dir/main.cpp.s

CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.o: CMakeFiles/ProjectAED_G24.dir/flags.make
CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.o: ../Schedule.cpp
CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.o: CMakeFiles/ProjectAED_G24.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/luiscontreiras/ProjectAED_G24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.o -MF CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.o.d -o CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.o -c /Users/luiscontreiras/ProjectAED_G24/Schedule.cpp

CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/luiscontreiras/ProjectAED_G24/Schedule.cpp > CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.i

CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/luiscontreiras/ProjectAED_G24/Schedule.cpp -o CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.s

CMakeFiles/ProjectAED_G24.dir/Student.cpp.o: CMakeFiles/ProjectAED_G24.dir/flags.make
CMakeFiles/ProjectAED_G24.dir/Student.cpp.o: ../Student.cpp
CMakeFiles/ProjectAED_G24.dir/Student.cpp.o: CMakeFiles/ProjectAED_G24.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/luiscontreiras/ProjectAED_G24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProjectAED_G24.dir/Student.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjectAED_G24.dir/Student.cpp.o -MF CMakeFiles/ProjectAED_G24.dir/Student.cpp.o.d -o CMakeFiles/ProjectAED_G24.dir/Student.cpp.o -c /Users/luiscontreiras/ProjectAED_G24/Student.cpp

CMakeFiles/ProjectAED_G24.dir/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectAED_G24.dir/Student.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/luiscontreiras/ProjectAED_G24/Student.cpp > CMakeFiles/ProjectAED_G24.dir/Student.cpp.i

CMakeFiles/ProjectAED_G24.dir/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectAED_G24.dir/Student.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/luiscontreiras/ProjectAED_G24/Student.cpp -o CMakeFiles/ProjectAED_G24.dir/Student.cpp.s

CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.o: CMakeFiles/ProjectAED_G24.dir/flags.make
CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.o: ../UniClass.cpp
CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.o: CMakeFiles/ProjectAED_G24.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/luiscontreiras/ProjectAED_G24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.o -MF CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.o.d -o CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.o -c /Users/luiscontreiras/ProjectAED_G24/UniClass.cpp

CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/luiscontreiras/ProjectAED_G24/UniClass.cpp > CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.i

CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/luiscontreiras/ProjectAED_G24/UniClass.cpp -o CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.s

CMakeFiles/ProjectAED_G24.dir/Menu.cpp.o: CMakeFiles/ProjectAED_G24.dir/flags.make
CMakeFiles/ProjectAED_G24.dir/Menu.cpp.o: ../Menu.cpp
CMakeFiles/ProjectAED_G24.dir/Menu.cpp.o: CMakeFiles/ProjectAED_G24.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/luiscontreiras/ProjectAED_G24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ProjectAED_G24.dir/Menu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjectAED_G24.dir/Menu.cpp.o -MF CMakeFiles/ProjectAED_G24.dir/Menu.cpp.o.d -o CMakeFiles/ProjectAED_G24.dir/Menu.cpp.o -c /Users/luiscontreiras/ProjectAED_G24/Menu.cpp

CMakeFiles/ProjectAED_G24.dir/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectAED_G24.dir/Menu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/luiscontreiras/ProjectAED_G24/Menu.cpp > CMakeFiles/ProjectAED_G24.dir/Menu.cpp.i

CMakeFiles/ProjectAED_G24.dir/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectAED_G24.dir/Menu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/luiscontreiras/ProjectAED_G24/Menu.cpp -o CMakeFiles/ProjectAED_G24.dir/Menu.cpp.s

CMakeFiles/ProjectAED_G24.dir/Application.cpp.o: CMakeFiles/ProjectAED_G24.dir/flags.make
CMakeFiles/ProjectAED_G24.dir/Application.cpp.o: ../Application.cpp
CMakeFiles/ProjectAED_G24.dir/Application.cpp.o: CMakeFiles/ProjectAED_G24.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/luiscontreiras/ProjectAED_G24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ProjectAED_G24.dir/Application.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjectAED_G24.dir/Application.cpp.o -MF CMakeFiles/ProjectAED_G24.dir/Application.cpp.o.d -o CMakeFiles/ProjectAED_G24.dir/Application.cpp.o -c /Users/luiscontreiras/ProjectAED_G24/Application.cpp

CMakeFiles/ProjectAED_G24.dir/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectAED_G24.dir/Application.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/luiscontreiras/ProjectAED_G24/Application.cpp > CMakeFiles/ProjectAED_G24.dir/Application.cpp.i

CMakeFiles/ProjectAED_G24.dir/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectAED_G24.dir/Application.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/luiscontreiras/ProjectAED_G24/Application.cpp -o CMakeFiles/ProjectAED_G24.dir/Application.cpp.s

# Object files for target ProjectAED_G24
ProjectAED_G24_OBJECTS = \
"CMakeFiles/ProjectAED_G24.dir/main.cpp.o" \
"CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.o" \
"CMakeFiles/ProjectAED_G24.dir/Student.cpp.o" \
"CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.o" \
"CMakeFiles/ProjectAED_G24.dir/Menu.cpp.o" \
"CMakeFiles/ProjectAED_G24.dir/Application.cpp.o"

# External object files for target ProjectAED_G24
ProjectAED_G24_EXTERNAL_OBJECTS =

ProjectAED_G24: CMakeFiles/ProjectAED_G24.dir/main.cpp.o
ProjectAED_G24: CMakeFiles/ProjectAED_G24.dir/Schedule.cpp.o
ProjectAED_G24: CMakeFiles/ProjectAED_G24.dir/Student.cpp.o
ProjectAED_G24: CMakeFiles/ProjectAED_G24.dir/UniClass.cpp.o
ProjectAED_G24: CMakeFiles/ProjectAED_G24.dir/Menu.cpp.o
ProjectAED_G24: CMakeFiles/ProjectAED_G24.dir/Application.cpp.o
ProjectAED_G24: CMakeFiles/ProjectAED_G24.dir/build.make
ProjectAED_G24: CMakeFiles/ProjectAED_G24.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/luiscontreiras/ProjectAED_G24/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ProjectAED_G24"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjectAED_G24.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjectAED_G24.dir/build: ProjectAED_G24
.PHONY : CMakeFiles/ProjectAED_G24.dir/build

CMakeFiles/ProjectAED_G24.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjectAED_G24.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjectAED_G24.dir/clean

CMakeFiles/ProjectAED_G24.dir/depend:
	cd /Users/luiscontreiras/ProjectAED_G24/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/luiscontreiras/ProjectAED_G24 /Users/luiscontreiras/ProjectAED_G24 /Users/luiscontreiras/ProjectAED_G24/cmake-build-debug /Users/luiscontreiras/ProjectAED_G24/cmake-build-debug /Users/luiscontreiras/ProjectAED_G24/cmake-build-debug/CMakeFiles/ProjectAED_G24.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjectAED_G24.dir/depend

