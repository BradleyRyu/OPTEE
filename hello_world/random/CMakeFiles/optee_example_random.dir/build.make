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
CMAKE_SOURCE_DIR = /home/minho/optee_qemu/optee_examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/minho/optee_qemu/optee_examples/hello_world

# Include any dependencies generated for this target.
include random/CMakeFiles/optee_example_random.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include random/CMakeFiles/optee_example_random.dir/compiler_depend.make

# Include the progress variables for this target.
include random/CMakeFiles/optee_example_random.dir/progress.make

# Include the compile flags for this target's objects.
include random/CMakeFiles/optee_example_random.dir/flags.make

random/CMakeFiles/optee_example_random.dir/host/main.c.o: random/CMakeFiles/optee_example_random.dir/flags.make
random/CMakeFiles/optee_example_random.dir/host/main.c.o: ../random/host/main.c
random/CMakeFiles/optee_example_random.dir/host/main.c.o: random/CMakeFiles/optee_example_random.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/minho/optee_qemu/optee_examples/hello_world/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object random/CMakeFiles/optee_example_random.dir/host/main.c.o"
	cd /home/minho/optee_qemu/optee_examples/hello_world/random && ccache /usr/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT random/CMakeFiles/optee_example_random.dir/host/main.c.o -MF CMakeFiles/optee_example_random.dir/host/main.c.o.d -o CMakeFiles/optee_example_random.dir/host/main.c.o -c /home/minho/optee_qemu/optee_examples/random/host/main.c

random/CMakeFiles/optee_example_random.dir/host/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/optee_example_random.dir/host/main.c.i"
	cd /home/minho/optee_qemu/optee_examples/hello_world/random && /usr/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/minho/optee_qemu/optee_examples/random/host/main.c > CMakeFiles/optee_example_random.dir/host/main.c.i

random/CMakeFiles/optee_example_random.dir/host/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/optee_example_random.dir/host/main.c.s"
	cd /home/minho/optee_qemu/optee_examples/hello_world/random && /usr/bin/aarch64-linux-gnu-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/minho/optee_qemu/optee_examples/random/host/main.c -o CMakeFiles/optee_example_random.dir/host/main.c.s

# Object files for target optee_example_random
optee_example_random_OBJECTS = \
"CMakeFiles/optee_example_random.dir/host/main.c.o"

# External object files for target optee_example_random
optee_example_random_EXTERNAL_OBJECTS =

random/optee_example_random: random/CMakeFiles/optee_example_random.dir/host/main.c.o
random/optee_example_random: random/CMakeFiles/optee_example_random.dir/build.make
random/optee_example_random: random/CMakeFiles/optee_example_random.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/minho/optee_qemu/optee_examples/hello_world/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable optee_example_random"
	cd /home/minho/optee_qemu/optee_examples/hello_world/random && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/optee_example_random.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
random/CMakeFiles/optee_example_random.dir/build: random/optee_example_random
.PHONY : random/CMakeFiles/optee_example_random.dir/build

random/CMakeFiles/optee_example_random.dir/clean:
	cd /home/minho/optee_qemu/optee_examples/hello_world/random && $(CMAKE_COMMAND) -P CMakeFiles/optee_example_random.dir/cmake_clean.cmake
.PHONY : random/CMakeFiles/optee_example_random.dir/clean

random/CMakeFiles/optee_example_random.dir/depend:
	cd /home/minho/optee_qemu/optee_examples/hello_world && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/minho/optee_qemu/optee_examples /home/minho/optee_qemu/optee_examples/random /home/minho/optee_qemu/optee_examples/hello_world /home/minho/optee_qemu/optee_examples/hello_world/random /home/minho/optee_qemu/optee_examples/hello_world/random/CMakeFiles/optee_example_random.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : random/CMakeFiles/optee_example_random.dir/depend

