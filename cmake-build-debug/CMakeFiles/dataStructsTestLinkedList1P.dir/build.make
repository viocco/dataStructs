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
include CMakeFiles/dataStructsTestLinkedList1P.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dataStructsTestLinkedList1P.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dataStructsTestLinkedList1P.dir/flags.make

CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.o: CMakeFiles/dataStructsTestLinkedList1P.dir/flags.make
CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.o: ../test/LinkedList1PTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.o -c /Users/vittorioiocco/Code/CLionProjects/dataStructs/test/LinkedList1PTest.cpp

CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vittorioiocco/Code/CLionProjects/dataStructs/test/LinkedList1PTest.cpp > CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.i

CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vittorioiocco/Code/CLionProjects/dataStructs/test/LinkedList1PTest.cpp -o CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.s

# Object files for target dataStructsTestLinkedList1P
dataStructsTestLinkedList1P_OBJECTS = \
"CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.o"

# External object files for target dataStructsTestLinkedList1P
dataStructsTestLinkedList1P_EXTERNAL_OBJECTS =

dataStructsTestLinkedList1P: CMakeFiles/dataStructsTestLinkedList1P.dir/test/LinkedList1PTest.cpp.o
dataStructsTestLinkedList1P: CMakeFiles/dataStructsTestLinkedList1P.dir/build.make
dataStructsTestLinkedList1P: lib/libgtest_maind.a
dataStructsTestLinkedList1P: lib/libgtestd.a
dataStructsTestLinkedList1P: CMakeFiles/dataStructsTestLinkedList1P.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dataStructsTestLinkedList1P"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dataStructsTestLinkedList1P.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dataStructsTestLinkedList1P.dir/build: dataStructsTestLinkedList1P

.PHONY : CMakeFiles/dataStructsTestLinkedList1P.dir/build

CMakeFiles/dataStructsTestLinkedList1P.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dataStructsTestLinkedList1P.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dataStructsTestLinkedList1P.dir/clean

CMakeFiles/dataStructsTestLinkedList1P.dir/depend:
	cd /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vittorioiocco/Code/CLionProjects/dataStructs /Users/vittorioiocco/Code/CLionProjects/dataStructs /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug /Users/vittorioiocco/Code/CLionProjects/dataStructs/cmake-build-debug/CMakeFiles/dataStructsTestLinkedList1P.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dataStructsTestLinkedList1P.dir/depend
