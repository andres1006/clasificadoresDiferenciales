# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS

# Include any dependencies generated for this target.
include src/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/main.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/main.dir/main.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/main.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/main.c

src/CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/main.c > CMakeFiles/main.dir/main.c.i

src/CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/main.c -o CMakeFiles/main.dir/main.c.s

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.o: src/Clasificador_diferencial_EP_vs_PKS.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS.c

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS.c > CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.i

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS.c -o CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.s

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.o: src/Clasificador_diferencial_EP_vs_PKS_emxAPI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_emxAPI.c

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_emxAPI.c > CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.i

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_emxAPI.c -o CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.s

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.o: src/Clasificador_diferencial_EP_vs_PKS_emxutil.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_emxutil.c

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_emxutil.c > CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.i

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_emxutil.c -o CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.s

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.o: src/Clasificador_diferencial_EP_vs_PKS_initialize.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_initialize.c

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_initialize.c > CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.i

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_initialize.c -o CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.s

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.o: src/Clasificador_diferencial_EP_vs_PKS_terminate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_terminate.c

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_terminate.c > CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.i

src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Clasificador_diferencial_EP_vs_PKS_terminate.c -o CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.s

src/CMakeFiles/main.dir/CompactSVM.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/CompactSVM.c.o: src/CompactSVM.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/main.dir/CompactSVM.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/CompactSVM.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/CompactSVM.c

src/CMakeFiles/main.dir/CompactSVM.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/CompactSVM.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/CompactSVM.c > CMakeFiles/main.dir/CompactSVM.c.i

src/CMakeFiles/main.dir/CompactSVM.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/CompactSVM.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/CompactSVM.c -o CMakeFiles/main.dir/CompactSVM.c.s

src/CMakeFiles/main.dir/Linear.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/Linear.c.o: src/Linear.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/CMakeFiles/main.dir/Linear.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/Linear.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Linear.c

src/CMakeFiles/main.dir/Linear.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/Linear.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Linear.c > CMakeFiles/main.dir/Linear.c.i

src/CMakeFiles/main.dir/Linear.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/Linear.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/Linear.c -o CMakeFiles/main.dir/Linear.c.s

src/CMakeFiles/main.dir/rtGetInf.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/rtGetInf.c.o: src/rtGetInf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/CMakeFiles/main.dir/rtGetInf.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/rtGetInf.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/rtGetInf.c

src/CMakeFiles/main.dir/rtGetInf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/rtGetInf.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/rtGetInf.c > CMakeFiles/main.dir/rtGetInf.c.i

src/CMakeFiles/main.dir/rtGetInf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/rtGetInf.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/rtGetInf.c -o CMakeFiles/main.dir/rtGetInf.c.s

src/CMakeFiles/main.dir/rtGetNaN.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/rtGetNaN.c.o: src/rtGetNaN.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/CMakeFiles/main.dir/rtGetNaN.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/rtGetNaN.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/rtGetNaN.c

src/CMakeFiles/main.dir/rtGetNaN.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/rtGetNaN.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/rtGetNaN.c > CMakeFiles/main.dir/rtGetNaN.c.i

src/CMakeFiles/main.dir/rtGetNaN.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/rtGetNaN.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/rtGetNaN.c -o CMakeFiles/main.dir/rtGetNaN.c.s

src/CMakeFiles/main.dir/rt_nonfinite.c.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/rt_nonfinite.c.o: src/rt_nonfinite.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/CMakeFiles/main.dir/rt_nonfinite.c.o"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/rt_nonfinite.c.o   -c /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/rt_nonfinite.c

src/CMakeFiles/main.dir/rt_nonfinite.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/rt_nonfinite.c.i"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/rt_nonfinite.c > CMakeFiles/main.dir/rt_nonfinite.c.i

src/CMakeFiles/main.dir/rt_nonfinite.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/rt_nonfinite.c.s"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/rt_nonfinite.c -o CMakeFiles/main.dir/rt_nonfinite.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.c.o" \
"CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.o" \
"CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.o" \
"CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.o" \
"CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.o" \
"CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.o" \
"CMakeFiles/main.dir/CompactSVM.c.o" \
"CMakeFiles/main.dir/Linear.c.o" \
"CMakeFiles/main.dir/rtGetInf.c.o" \
"CMakeFiles/main.dir/rtGetNaN.c.o" \
"CMakeFiles/main.dir/rt_nonfinite.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

src/main: src/CMakeFiles/main.dir/main.c.o
src/main: src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS.c.o
src/main: src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxAPI.c.o
src/main: src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_emxutil.c.o
src/main: src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_initialize.c.o
src/main: src/CMakeFiles/main.dir/Clasificador_diferencial_EP_vs_PKS_terminate.c.o
src/main: src/CMakeFiles/main.dir/CompactSVM.c.o
src/main: src/CMakeFiles/main.dir/Linear.c.o
src/main: src/CMakeFiles/main.dir/rtGetInf.c.o
src/main: src/CMakeFiles/main.dir/rtGetNaN.c.o
src/main: src/CMakeFiles/main.dir/rt_nonfinite.c.o
src/main: src/CMakeFiles/main.dir/build.make
src/main: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable main"
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: src/main

.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/clean:
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src /Users/andresagudelo/Documents/aura/clasificadoresDiferenciales/Clasificador_diferencial_EP_vs_PKS/src/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/main.dir/depend

