# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/charles/VE482/Labs/l4/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/charles/VE482/Labs/l4/code/build

# Include any dependencies generated for this target.
include CMakeFiles/cli.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cli.dir/flags.make

CMakeFiles/cli.dir/cli.c.o: CMakeFiles/cli.dir/flags.make
CMakeFiles/cli.dir/cli.c.o: ../cli.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Labs/l4/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cli.dir/cli.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cli.dir/cli.c.o   -c /home/charles/VE482/Labs/l4/code/cli.c

CMakeFiles/cli.dir/cli.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cli.dir/cli.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/charles/VE482/Labs/l4/code/cli.c > CMakeFiles/cli.dir/cli.c.i

CMakeFiles/cli.dir/cli.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cli.dir/cli.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/charles/VE482/Labs/l4/code/cli.c -o CMakeFiles/cli.dir/cli.c.s

CMakeFiles/cli.dir/cli.c.o.requires:

.PHONY : CMakeFiles/cli.dir/cli.c.o.requires

CMakeFiles/cli.dir/cli.c.o.provides: CMakeFiles/cli.dir/cli.c.o.requires
	$(MAKE) -f CMakeFiles/cli.dir/build.make CMakeFiles/cli.dir/cli.c.o.provides.build
.PHONY : CMakeFiles/cli.dir/cli.c.o.provides

CMakeFiles/cli.dir/cli.c.o.provides.build: CMakeFiles/cli.dir/cli.c.o


CMakeFiles/cli.dir/interface.c.o: CMakeFiles/cli.dir/flags.make
CMakeFiles/cli.dir/interface.c.o: ../interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Labs/l4/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cli.dir/interface.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cli.dir/interface.c.o   -c /home/charles/VE482/Labs/l4/code/interface.c

CMakeFiles/cli.dir/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cli.dir/interface.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/charles/VE482/Labs/l4/code/interface.c > CMakeFiles/cli.dir/interface.c.i

CMakeFiles/cli.dir/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cli.dir/interface.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/charles/VE482/Labs/l4/code/interface.c -o CMakeFiles/cli.dir/interface.c.s

CMakeFiles/cli.dir/interface.c.o.requires:

.PHONY : CMakeFiles/cli.dir/interface.c.o.requires

CMakeFiles/cli.dir/interface.c.o.provides: CMakeFiles/cli.dir/interface.c.o.requires
	$(MAKE) -f CMakeFiles/cli.dir/build.make CMakeFiles/cli.dir/interface.c.o.provides.build
.PHONY : CMakeFiles/cli.dir/interface.c.o.provides

CMakeFiles/cli.dir/interface.c.o.provides.build: CMakeFiles/cli.dir/interface.c.o


CMakeFiles/cli.dir/api.c.o: CMakeFiles/cli.dir/flags.make
CMakeFiles/cli.dir/api.c.o: ../api.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Labs/l4/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cli.dir/api.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cli.dir/api.c.o   -c /home/charles/VE482/Labs/l4/code/api.c

CMakeFiles/cli.dir/api.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cli.dir/api.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/charles/VE482/Labs/l4/code/api.c > CMakeFiles/cli.dir/api.c.i

CMakeFiles/cli.dir/api.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cli.dir/api.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/charles/VE482/Labs/l4/code/api.c -o CMakeFiles/cli.dir/api.c.s

CMakeFiles/cli.dir/api.c.o.requires:

.PHONY : CMakeFiles/cli.dir/api.c.o.requires

CMakeFiles/cli.dir/api.c.o.provides: CMakeFiles/cli.dir/api.c.o.requires
	$(MAKE) -f CMakeFiles/cli.dir/build.make CMakeFiles/cli.dir/api.c.o.provides.build
.PHONY : CMakeFiles/cli.dir/api.c.o.provides

CMakeFiles/cli.dir/api.c.o.provides.build: CMakeFiles/cli.dir/api.c.o


CMakeFiles/cli.dir/list.c.o: CMakeFiles/cli.dir/flags.make
CMakeFiles/cli.dir/list.c.o: ../list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Labs/l4/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cli.dir/list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cli.dir/list.c.o   -c /home/charles/VE482/Labs/l4/code/list.c

CMakeFiles/cli.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cli.dir/list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/charles/VE482/Labs/l4/code/list.c > CMakeFiles/cli.dir/list.c.i

CMakeFiles/cli.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cli.dir/list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/charles/VE482/Labs/l4/code/list.c -o CMakeFiles/cli.dir/list.c.s

CMakeFiles/cli.dir/list.c.o.requires:

.PHONY : CMakeFiles/cli.dir/list.c.o.requires

CMakeFiles/cli.dir/list.c.o.provides: CMakeFiles/cli.dir/list.c.o.requires
	$(MAKE) -f CMakeFiles/cli.dir/build.make CMakeFiles/cli.dir/list.c.o.provides.build
.PHONY : CMakeFiles/cli.dir/list.c.o.provides

CMakeFiles/cli.dir/list.c.o.provides.build: CMakeFiles/cli.dir/list.c.o


# Object files for target cli
cli_OBJECTS = \
"CMakeFiles/cli.dir/cli.c.o" \
"CMakeFiles/cli.dir/interface.c.o" \
"CMakeFiles/cli.dir/api.c.o" \
"CMakeFiles/cli.dir/list.c.o"

# External object files for target cli
cli_EXTERNAL_OBJECTS =

cli: CMakeFiles/cli.dir/cli.c.o
cli: CMakeFiles/cli.dir/interface.c.o
cli: CMakeFiles/cli.dir/api.c.o
cli: CMakeFiles/cli.dir/list.c.o
cli: CMakeFiles/cli.dir/build.make
cli: CMakeFiles/cli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/charles/VE482/Labs/l4/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable cli"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cli.dir/build: cli

.PHONY : CMakeFiles/cli.dir/build

CMakeFiles/cli.dir/requires: CMakeFiles/cli.dir/cli.c.o.requires
CMakeFiles/cli.dir/requires: CMakeFiles/cli.dir/interface.c.o.requires
CMakeFiles/cli.dir/requires: CMakeFiles/cli.dir/api.c.o.requires
CMakeFiles/cli.dir/requires: CMakeFiles/cli.dir/list.c.o.requires

.PHONY : CMakeFiles/cli.dir/requires

CMakeFiles/cli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cli.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cli.dir/clean

CMakeFiles/cli.dir/depend:
	cd /home/charles/VE482/Labs/l4/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/charles/VE482/Labs/l4/code /home/charles/VE482/Labs/l4/code /home/charles/VE482/Labs/l4/code/build /home/charles/VE482/Labs/l4/code/build /home/charles/VE482/Labs/l4/code/build/CMakeFiles/cli.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cli.dir/depend

