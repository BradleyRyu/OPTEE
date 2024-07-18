# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_BINARY_DIR = /home/minho/optee_qemu/optee_examples

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/minho/optee_qemu/optee_examples/CMakeFiles /home/minho/optee_qemu/optee_examples//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/minho/optee_qemu/optee_examples/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named optee_example_acipher

# Build rule for target.
optee_example_acipher: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_example_acipher
.PHONY : optee_example_acipher

# fast build rule for target.
optee_example_acipher/fast:
	$(MAKE) $(MAKESILENT) -f acipher/CMakeFiles/optee_example_acipher.dir/build.make acipher/CMakeFiles/optee_example_acipher.dir/build
.PHONY : optee_example_acipher/fast

#=============================================================================
# Target rules for targets named optee_example_aes

# Build rule for target.
optee_example_aes: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_example_aes
.PHONY : optee_example_aes

# fast build rule for target.
optee_example_aes/fast:
	$(MAKE) $(MAKESILENT) -f aes/CMakeFiles/optee_example_aes.dir/build.make aes/CMakeFiles/optee_example_aes.dir/build
.PHONY : optee_example_aes/fast

#=============================================================================
# Target rules for targets named optee_example_hello_world

# Build rule for target.
optee_example_hello_world: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_example_hello_world
.PHONY : optee_example_hello_world

# fast build rule for target.
optee_example_hello_world/fast:
	$(MAKE) $(MAKESILENT) -f hello_world/CMakeFiles/optee_example_hello_world.dir/build.make hello_world/CMakeFiles/optee_example_hello_world.dir/build
.PHONY : optee_example_hello_world/fast

#=============================================================================
# Target rules for targets named optee_example_hotp

# Build rule for target.
optee_example_hotp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_example_hotp
.PHONY : optee_example_hotp

# fast build rule for target.
optee_example_hotp/fast:
	$(MAKE) $(MAKESILENT) -f hotp/CMakeFiles/optee_example_hotp.dir/build.make hotp/CMakeFiles/optee_example_hotp.dir/build
.PHONY : optee_example_hotp/fast

#=============================================================================
# Target rules for targets named optee_lwip_client

# Build rule for target.
optee_lwip_client: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_lwip_client
.PHONY : optee_lwip_client

# fast build rule for target.
optee_lwip_client/fast:
	$(MAKE) $(MAKESILENT) -f lwip_client/CMakeFiles/optee_lwip_client.dir/build.make lwip_client/CMakeFiles/optee_lwip_client.dir/build
.PHONY : optee_lwip_client/fast

#=============================================================================
# Target rules for targets named optee_lwip_test

# Build rule for target.
optee_lwip_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_lwip_test
.PHONY : optee_lwip_test

# fast build rule for target.
optee_lwip_test/fast:
	$(MAKE) $(MAKESILENT) -f lwip_test/CMakeFiles/optee_lwip_test.dir/build.make lwip_test/CMakeFiles/optee_lwip_test.dir/build
.PHONY : optee_lwip_test/fast

#=============================================================================
# Target rules for targets named optee_ping

# Build rule for target.
optee_ping: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_ping
.PHONY : optee_ping

# fast build rule for target.
optee_ping/fast:
	$(MAKE) $(MAKESILENT) -f ping/CMakeFiles/optee_ping.dir/build.make ping/CMakeFiles/optee_ping.dir/build
.PHONY : optee_ping/fast

#=============================================================================
# Target rules for targets named optee_example_plugins

# Build rule for target.
optee_example_plugins: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_example_plugins
.PHONY : optee_example_plugins

# fast build rule for target.
optee_example_plugins/fast:
	$(MAKE) $(MAKESILENT) -f plugins/CMakeFiles/optee_example_plugins.dir/build.make plugins/CMakeFiles/optee_example_plugins.dir/build
.PHONY : optee_example_plugins/fast

#=============================================================================
# Target rules for targets named 96bcf744-4f72-4866-bf1d-8634fd9c65e5.plugin

# Build rule for target.
96bcf744-4f72-4866-bf1d-8634fd9c65e5.plugin: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 96bcf744-4f72-4866-bf1d-8634fd9c65e5.plugin
.PHONY : 96bcf744-4f72-4866-bf1d-8634fd9c65e5.plugin

# fast build rule for target.
96bcf744-4f72-4866-bf1d-8634fd9c65e5.plugin/fast:
	$(MAKE) $(MAKESILENT) -f plugins/syslog/CMakeFiles/96bcf744-4f72-4866-bf1d-8634fd9c65e5.plugin.dir/build.make plugins/syslog/CMakeFiles/96bcf744-4f72-4866-bf1d-8634fd9c65e5.plugin.dir/build
.PHONY : 96bcf744-4f72-4866-bf1d-8634fd9c65e5.plugin/fast

#=============================================================================
# Target rules for targets named optee_example_random

# Build rule for target.
optee_example_random: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_example_random
.PHONY : optee_example_random

# fast build rule for target.
optee_example_random/fast:
	$(MAKE) $(MAKESILENT) -f random/CMakeFiles/optee_example_random.dir/build.make random/CMakeFiles/optee_example_random.dir/build
.PHONY : optee_example_random/fast

#=============================================================================
# Target rules for targets named optee_example_secure_storage

# Build rule for target.
optee_example_secure_storage: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_example_secure_storage
.PHONY : optee_example_secure_storage

# fast build rule for target.
optee_example_secure_storage/fast:
	$(MAKE) $(MAKESILENT) -f secure_storage/CMakeFiles/optee_example_secure_storage.dir/build.make secure_storage/CMakeFiles/optee_example_secure_storage.dir/build
.PHONY : optee_example_secure_storage/fast

#=============================================================================
# Target rules for targets named optee_ta2ta_test

# Build rule for target.
optee_ta2ta_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 optee_ta2ta_test
.PHONY : optee_ta2ta_test

# fast build rule for target.
optee_ta2ta_test/fast:
	$(MAKE) $(MAKESILENT) -f ta2ta_test/CMakeFiles/optee_ta2ta_test.dir/build.make ta2ta_test/CMakeFiles/optee_ta2ta_test.dir/build
.PHONY : optee_ta2ta_test/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... 96bcf744-4f72-4866-bf1d-8634fd9c65e5.plugin"
	@echo "... optee_example_acipher"
	@echo "... optee_example_aes"
	@echo "... optee_example_hello_world"
	@echo "... optee_example_hotp"
	@echo "... optee_example_plugins"
	@echo "... optee_example_random"
	@echo "... optee_example_secure_storage"
	@echo "... optee_lwip_client"
	@echo "... optee_lwip_test"
	@echo "... optee_ping"
	@echo "... optee_ta2ta_test"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

