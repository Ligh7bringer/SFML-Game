# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/svet/Repositories/SFML-Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/svet/Repositories/SFML-Game/cmake-build-release-clang

# Include any dependencies generated for this target.
include CMakeFiles/lib_ecm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lib_ecm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lib_ecm.dir/flags.make

CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o: CMakeFiles/lib_ecm.dir/flags.make
CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o: ../engine/lib_ecm/ecm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svet/Repositories/SFML-Game/cmake-build-release-clang/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o -c /home/svet/Repositories/SFML-Game/engine/lib_ecm/ecm.cpp

CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svet/Repositories/SFML-Game/engine/lib_ecm/ecm.cpp > CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.i

CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svet/Repositories/SFML-Game/engine/lib_ecm/ecm.cpp -o CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.s

CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o.requires:

.PHONY : CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o.requires

CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o.provides: CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o.requires
	$(MAKE) -f CMakeFiles/lib_ecm.dir/build.make CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o.provides.build
.PHONY : CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o.provides

CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o.provides.build: CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o


# Object files for target lib_ecm
lib_ecm_OBJECTS = \
"CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o"

# External object files for target lib_ecm
lib_ecm_EXTERNAL_OBJECTS =

liblib_ecm.a: CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o
liblib_ecm.a: CMakeFiles/lib_ecm.dir/build.make
liblib_ecm.a: CMakeFiles/lib_ecm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/svet/Repositories/SFML-Game/cmake-build-release-clang/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblib_ecm.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lib_ecm.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib_ecm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lib_ecm.dir/build: liblib_ecm.a

.PHONY : CMakeFiles/lib_ecm.dir/build

CMakeFiles/lib_ecm.dir/requires: CMakeFiles/lib_ecm.dir/engine/lib_ecm/ecm.cpp.o.requires

.PHONY : CMakeFiles/lib_ecm.dir/requires

CMakeFiles/lib_ecm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lib_ecm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lib_ecm.dir/clean

CMakeFiles/lib_ecm.dir/depend:
	cd /home/svet/Repositories/SFML-Game/cmake-build-release-clang && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/svet/Repositories/SFML-Game /home/svet/Repositories/SFML-Game /home/svet/Repositories/SFML-Game/cmake-build-release-clang /home/svet/Repositories/SFML-Game/cmake-build-release-clang /home/svet/Repositories/SFML-Game/cmake-build-release-clang/CMakeFiles/lib_ecm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lib_ecm.dir/depend

