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
CMAKE_SOURCE_DIR = /home/charles/VE482/Projects/p2/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/charles/VE482/Projects/p2/src/build

# Include any dependencies generated for this target.
include CMakeFiles/lemondb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lemondb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lemondb.dir/flags.make

CMakeFiles/lemondb.dir/main.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lemondb.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/main.cpp.o -c /home/charles/VE482/Projects/p2/src/main.cpp

CMakeFiles/lemondb.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/main.cpp > CMakeFiles/lemondb.dir/main.cpp.i

CMakeFiles/lemondb.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/main.cpp -o CMakeFiles/lemondb.dir/main.cpp.s

CMakeFiles/lemondb.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/main.cpp.o.requires

CMakeFiles/lemondb.dir/main.cpp.o.provides: CMakeFiles/lemondb.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/main.cpp.o.provides

CMakeFiles/lemondb.dir/main.cpp.o.provides.build: CMakeFiles/lemondb.dir/main.cpp.o


CMakeFiles/lemondb.dir/db/Database.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/db/Database.cpp.o: ../db/Database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lemondb.dir/db/Database.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/db/Database.cpp.o -c /home/charles/VE482/Projects/p2/src/db/Database.cpp

CMakeFiles/lemondb.dir/db/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/db/Database.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/db/Database.cpp > CMakeFiles/lemondb.dir/db/Database.cpp.i

CMakeFiles/lemondb.dir/db/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/db/Database.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/db/Database.cpp -o CMakeFiles/lemondb.dir/db/Database.cpp.s

CMakeFiles/lemondb.dir/db/Database.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/db/Database.cpp.o.requires

CMakeFiles/lemondb.dir/db/Database.cpp.o.provides: CMakeFiles/lemondb.dir/db/Database.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/db/Database.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/db/Database.cpp.o.provides

CMakeFiles/lemondb.dir/db/Database.cpp.o.provides.build: CMakeFiles/lemondb.dir/db/Database.cpp.o


CMakeFiles/lemondb.dir/db/Table.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/db/Table.cpp.o: ../db/Table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lemondb.dir/db/Table.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/db/Table.cpp.o -c /home/charles/VE482/Projects/p2/src/db/Table.cpp

CMakeFiles/lemondb.dir/db/Table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/db/Table.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/db/Table.cpp > CMakeFiles/lemondb.dir/db/Table.cpp.i

CMakeFiles/lemondb.dir/db/Table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/db/Table.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/db/Table.cpp -o CMakeFiles/lemondb.dir/db/Table.cpp.s

CMakeFiles/lemondb.dir/db/Table.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/db/Table.cpp.o.requires

CMakeFiles/lemondb.dir/db/Table.cpp.o.provides: CMakeFiles/lemondb.dir/db/Table.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/db/Table.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/db/Table.cpp.o.provides

CMakeFiles/lemondb.dir/db/Table.cpp.o.provides.build: CMakeFiles/lemondb.dir/db/Table.cpp.o


CMakeFiles/lemondb.dir/query/Query.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/Query.cpp.o: ../query/Query.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lemondb.dir/query/Query.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/Query.cpp.o -c /home/charles/VE482/Projects/p2/src/query/Query.cpp

CMakeFiles/lemondb.dir/query/Query.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/Query.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/Query.cpp > CMakeFiles/lemondb.dir/query/Query.cpp.i

CMakeFiles/lemondb.dir/query/Query.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/Query.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/Query.cpp -o CMakeFiles/lemondb.dir/query/Query.cpp.s

CMakeFiles/lemondb.dir/query/Query.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/Query.cpp.o.requires

CMakeFiles/lemondb.dir/query/Query.cpp.o.provides: CMakeFiles/lemondb.dir/query/Query.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/Query.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/Query.cpp.o.provides

CMakeFiles/lemondb.dir/query/Query.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/Query.cpp.o


CMakeFiles/lemondb.dir/query/QueryParser.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/QueryParser.cpp.o: ../query/QueryParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lemondb.dir/query/QueryParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/QueryParser.cpp.o -c /home/charles/VE482/Projects/p2/src/query/QueryParser.cpp

CMakeFiles/lemondb.dir/query/QueryParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/QueryParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/QueryParser.cpp > CMakeFiles/lemondb.dir/query/QueryParser.cpp.i

CMakeFiles/lemondb.dir/query/QueryParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/QueryParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/QueryParser.cpp -o CMakeFiles/lemondb.dir/query/QueryParser.cpp.s

CMakeFiles/lemondb.dir/query/QueryParser.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/QueryParser.cpp.o.requires

CMakeFiles/lemondb.dir/query/QueryParser.cpp.o.provides: CMakeFiles/lemondb.dir/query/QueryParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/QueryParser.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/QueryParser.cpp.o.provides

CMakeFiles/lemondb.dir/query/QueryParser.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/QueryParser.cpp.o


CMakeFiles/lemondb.dir/query/QueryResult.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/QueryResult.cpp.o: ../query/QueryResult.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lemondb.dir/query/QueryResult.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/QueryResult.cpp.o -c /home/charles/VE482/Projects/p2/src/query/QueryResult.cpp

CMakeFiles/lemondb.dir/query/QueryResult.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/QueryResult.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/QueryResult.cpp > CMakeFiles/lemondb.dir/query/QueryResult.cpp.i

CMakeFiles/lemondb.dir/query/QueryResult.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/QueryResult.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/QueryResult.cpp -o CMakeFiles/lemondb.dir/query/QueryResult.cpp.s

CMakeFiles/lemondb.dir/query/QueryResult.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/QueryResult.cpp.o.requires

CMakeFiles/lemondb.dir/query/QueryResult.cpp.o.provides: CMakeFiles/lemondb.dir/query/QueryResult.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/QueryResult.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/QueryResult.cpp.o.provides

CMakeFiles/lemondb.dir/query/QueryResult.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/QueryResult.cpp.o


CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o: ../query/QueryBuilders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o -c /home/charles/VE482/Projects/p2/src/query/QueryBuilders.cpp

CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/QueryBuilders.cpp > CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.i

CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/QueryBuilders.cpp -o CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.s

CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o.requires

CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o.provides: CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o.provides

CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o


CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o: ../query/management/LoadTableQuery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o -c /home/charles/VE482/Projects/p2/src/query/management/LoadTableQuery.cpp

CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/management/LoadTableQuery.cpp > CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.i

CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/management/LoadTableQuery.cpp -o CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.s

CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o.requires

CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o.provides: CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o.provides

CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o


CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o: ../query/management/DropTableQuery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o -c /home/charles/VE482/Projects/p2/src/query/management/DropTableQuery.cpp

CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/management/DropTableQuery.cpp > CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.i

CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/management/DropTableQuery.cpp -o CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.s

CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o.requires

CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o.provides: CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o.provides

CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o


CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o: ../query/management/DumpTableQuery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o -c /home/charles/VE482/Projects/p2/src/query/management/DumpTableQuery.cpp

CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/management/DumpTableQuery.cpp > CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.i

CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/management/DumpTableQuery.cpp -o CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.s

CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o.requires

CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o.provides: CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o.provides

CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o


CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o: ../query/management/ListTableQuery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o -c /home/charles/VE482/Projects/p2/src/query/management/ListTableQuery.cpp

CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/management/ListTableQuery.cpp > CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.i

CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/management/ListTableQuery.cpp -o CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.s

CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o.requires

CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o.provides: CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o.provides

CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o


CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o: ../query/management/QuitQuery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o -c /home/charles/VE482/Projects/p2/src/query/management/QuitQuery.cpp

CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/management/QuitQuery.cpp > CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.i

CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/management/QuitQuery.cpp -o CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.s

CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o.requires

CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o.provides: CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o.provides

CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o


CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o: ../query/management/PrintTableQuery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o -c /home/charles/VE482/Projects/p2/src/query/management/PrintTableQuery.cpp

CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/management/PrintTableQuery.cpp > CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.i

CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/management/PrintTableQuery.cpp -o CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.s

CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o.requires

CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o.provides: CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o.provides

CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o


CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o: ../query/data/InsertQuery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o -c /home/charles/VE482/Projects/p2/src/query/data/InsertQuery.cpp

CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/data/InsertQuery.cpp > CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.i

CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/data/InsertQuery.cpp -o CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.s

CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o.requires

CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o.provides: CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o.provides

CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o


CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o: CMakeFiles/lemondb.dir/flags.make
CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o: ../query/data/UpdateQuery.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o -c /home/charles/VE482/Projects/p2/src/query/data/UpdateQuery.cpp

CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charles/VE482/Projects/p2/src/query/data/UpdateQuery.cpp > CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.i

CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charles/VE482/Projects/p2/src/query/data/UpdateQuery.cpp -o CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.s

CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o.requires:

.PHONY : CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o.requires

CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o.provides: CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o.requires
	$(MAKE) -f CMakeFiles/lemondb.dir/build.make CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o.provides.build
.PHONY : CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o.provides

CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o.provides.build: CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o


# Object files for target lemondb
lemondb_OBJECTS = \
"CMakeFiles/lemondb.dir/main.cpp.o" \
"CMakeFiles/lemondb.dir/db/Database.cpp.o" \
"CMakeFiles/lemondb.dir/db/Table.cpp.o" \
"CMakeFiles/lemondb.dir/query/Query.cpp.o" \
"CMakeFiles/lemondb.dir/query/QueryParser.cpp.o" \
"CMakeFiles/lemondb.dir/query/QueryResult.cpp.o" \
"CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o" \
"CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o" \
"CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o" \
"CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o" \
"CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o" \
"CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o" \
"CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o" \
"CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o" \
"CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o"

# External object files for target lemondb
lemondb_EXTERNAL_OBJECTS =

lemondb: CMakeFiles/lemondb.dir/main.cpp.o
lemondb: CMakeFiles/lemondb.dir/db/Database.cpp.o
lemondb: CMakeFiles/lemondb.dir/db/Table.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/Query.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/QueryParser.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/QueryResult.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o
lemondb: CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o
lemondb: CMakeFiles/lemondb.dir/build.make
lemondb: CMakeFiles/lemondb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/charles/VE482/Projects/p2/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable lemondb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lemondb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lemondb.dir/build: lemondb

.PHONY : CMakeFiles/lemondb.dir/build

CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/main.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/db/Database.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/db/Table.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/Query.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/QueryParser.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/QueryResult.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/QueryBuilders.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/management/LoadTableQuery.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/management/DropTableQuery.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/management/DumpTableQuery.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/management/ListTableQuery.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/management/QuitQuery.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/management/PrintTableQuery.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/data/InsertQuery.cpp.o.requires
CMakeFiles/lemondb.dir/requires: CMakeFiles/lemondb.dir/query/data/UpdateQuery.cpp.o.requires

.PHONY : CMakeFiles/lemondb.dir/requires

CMakeFiles/lemondb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lemondb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lemondb.dir/clean

CMakeFiles/lemondb.dir/depend:
	cd /home/charles/VE482/Projects/p2/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/charles/VE482/Projects/p2/src /home/charles/VE482/Projects/p2/src /home/charles/VE482/Projects/p2/src/build /home/charles/VE482/Projects/p2/src/build /home/charles/VE482/Projects/p2/src/build/CMakeFiles/lemondb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lemondb.dir/depend
