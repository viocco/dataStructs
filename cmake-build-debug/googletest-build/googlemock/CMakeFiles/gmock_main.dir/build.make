# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/vittorioiocco/Software/IDEs/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/vittorioiocco/Software/IDEs/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vittorioiocco/Code/CLionProjects/dataStructs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug

# Include any dependencies generated for this target.
include googletest-build/googlemock/CMakeFiles/gmock_main.dir/depend.make

# Include the progress variables for this target.
include googletest-build/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include googletest-build/googlemock/CMakeFiles/gmock_main.dir/flags.make

googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: googletest-build/googlemock/CMakeFiles/gmock_main.dir/flags.make
googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: googletest-src/googlemock/src/gmock_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-build/googlemock && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-src/googlemock/src/gmock_main.cc

googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-build/googlemock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-src/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-build/googlemock && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-src/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_maind.a: googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
lib/libgmock_maind.a: googletest-build/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_maind.a: googletest-build/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libgmock_maind.a"
	cd /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-build/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-build/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest-build/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_maind.a

.PHONY : googletest-build/googlemock/CMakeFiles/gmock_main.dir/build

googletest-build/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-build/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : googletest-build/googlemock/CMakeFiles/gmock_main.dir/clean

googletest-build/googlemock/CMakeFiles/gmock_main.dir/depend:
	cd /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vittorioiocco/Code/CLionProjects/dataStructs /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-src/googlemock /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-build/googlemock /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/googletest-build/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googletest-build/googlemock/CMakeFiles/gmock_main.dir/depend

