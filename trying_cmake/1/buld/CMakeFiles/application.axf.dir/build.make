# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/abdu/Study/FreeRTOS/trying_cmake/1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abdu/Study/FreeRTOS/trying_cmake/1/buld

# Include any dependencies generated for this target.
include CMakeFiles/application.axf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/application.axf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/application.axf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/application.axf.dir/flags.make

CMakeFiles/application.axf.dir/main.c.o: CMakeFiles/application.axf.dir/flags.make
CMakeFiles/application.axf.dir/main.c.o: /home/abdu/Study/FreeRTOS/trying_cmake/1/main.c
CMakeFiles/application.axf.dir/main.c.o: CMakeFiles/application.axf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abdu/Study/FreeRTOS/trying_cmake/1/buld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/application.axf.dir/main.c.o"
	/home/abdu/Downloads/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/application.axf.dir/main.c.o -MF CMakeFiles/application.axf.dir/main.c.o.d -o CMakeFiles/application.axf.dir/main.c.o -c /home/abdu/Study/FreeRTOS/trying_cmake/1/main.c

CMakeFiles/application.axf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/application.axf.dir/main.c.i"
	/home/abdu/Downloads/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/abdu/Study/FreeRTOS/trying_cmake/1/main.c > CMakeFiles/application.axf.dir/main.c.i

CMakeFiles/application.axf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/application.axf.dir/main.c.s"
	/home/abdu/Downloads/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/abdu/Study/FreeRTOS/trying_cmake/1/main.c -o CMakeFiles/application.axf.dir/main.c.s

CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.o: CMakeFiles/application.axf.dir/flags.make
CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.o: /home/abdu/Study/FreeRTOS/trying_cmake/1/tm4c123gh6pm_startup_ccs_gcc.c
CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.o: CMakeFiles/application.axf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abdu/Study/FreeRTOS/trying_cmake/1/buld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.o"
	/home/abdu/Downloads/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.o -MF CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.o.d -o CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.o -c /home/abdu/Study/FreeRTOS/trying_cmake/1/tm4c123gh6pm_startup_ccs_gcc.c

CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.i"
	/home/abdu/Downloads/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/abdu/Study/FreeRTOS/trying_cmake/1/tm4c123gh6pm_startup_ccs_gcc.c > CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.i

CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.s"
	/home/abdu/Downloads/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/abdu/Study/FreeRTOS/trying_cmake/1/tm4c123gh6pm_startup_ccs_gcc.c -o CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.s

# Object files for target application.axf
application_axf_OBJECTS = \
"CMakeFiles/application.axf.dir/main.c.o" \
"CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.o"

# External object files for target application.axf
application_axf_EXTERNAL_OBJECTS =

application.axf: CMakeFiles/application.axf.dir/main.c.o
application.axf: CMakeFiles/application.axf.dir/tm4c123gh6pm_startup_ccs_gcc.c.o
application.axf: CMakeFiles/application.axf.dir/build.make
application.axf: CMakeFiles/application.axf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/abdu/Study/FreeRTOS/trying_cmake/1/buld/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable application.axf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/application.axf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/application.axf.dir/build: application.axf
.PHONY : CMakeFiles/application.axf.dir/build

CMakeFiles/application.axf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/application.axf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/application.axf.dir/clean

CMakeFiles/application.axf.dir/depend:
	cd /home/abdu/Study/FreeRTOS/trying_cmake/1/buld && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abdu/Study/FreeRTOS/trying_cmake/1 /home/abdu/Study/FreeRTOS/trying_cmake/1 /home/abdu/Study/FreeRTOS/trying_cmake/1/buld /home/abdu/Study/FreeRTOS/trying_cmake/1/buld /home/abdu/Study/FreeRTOS/trying_cmake/1/buld/CMakeFiles/application.axf.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/application.axf.dir/depend

