# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software/build

# Include any dependencies generated for this target.
include CMakeFiles/longvein.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/longvein.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/longvein.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/longvein.dir/flags.make

CMakeFiles/longvein.dir/longvein.cpp.o: CMakeFiles/longvein.dir/flags.make
CMakeFiles/longvein.dir/longvein.cpp.o: ../longvein.cpp
CMakeFiles/longvein.dir/longvein.cpp.o: CMakeFiles/longvein.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/longvein.dir/longvein.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/longvein.dir/longvein.cpp.o -MF CMakeFiles/longvein.dir/longvein.cpp.o.d -o CMakeFiles/longvein.dir/longvein.cpp.o -c /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software/longvein.cpp

CMakeFiles/longvein.dir/longvein.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/longvein.dir/longvein.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software/longvein.cpp > CMakeFiles/longvein.dir/longvein.cpp.i

CMakeFiles/longvein.dir/longvein.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/longvein.dir/longvein.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software/longvein.cpp -o CMakeFiles/longvein.dir/longvein.cpp.s

# Object files for target longvein
longvein_OBJECTS = \
"CMakeFiles/longvein.dir/longvein.cpp.o"

# External object files for target longvein
longvein_EXTERNAL_OBJECTS =

liblongvein.a: CMakeFiles/longvein.dir/longvein.cpp.o
liblongvein.a: CMakeFiles/longvein.dir/build.make
liblongvein.a: CMakeFiles/longvein.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblongvein.a"
	$(CMAKE_COMMAND) -P CMakeFiles/longvein.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/longvein.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/longvein.dir/build: liblongvein.a
.PHONY : CMakeFiles/longvein.dir/build

CMakeFiles/longvein.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/longvein.dir/cmake_clean.cmake
.PHONY : CMakeFiles/longvein.dir/clean

CMakeFiles/longvein.dir/depend:
	cd /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software/build /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software/build /home/chris/Desktop/sdu/MySQL/Exam/Portef-lge_software/build/CMakeFiles/longvein.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/longvein.dir/depend

