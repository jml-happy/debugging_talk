
# SET to C for the C language and CPP for the C++ language
C_OR_CPP = $(C)

# THERE ARE THREE WAYS TO USE THIS MAKE FILE:
# 1) Set up a "project": set the PROJECT_NAME, list the files it needs in PROJECT_O_FILES
#   > make project

# 2) Set up a "multi-source file test": set the TEST_NAME, list the files it needs in TEST_O_FILES
#   > make test

# 3) Compile a single source file to a program: great for unit tests!
#   > make test_dog.out

################################ TARGET NAMES #####################################
################################################################################### 

# use for a "project"
PROJECT_NAME = some_project

# use for a "test" ... this way we don't have to include all files in a test
TEST_NAME = unit_test_something

################################# FILE LISTS ######################################
################################################################################### 

# use for a "project"
PROJECT_O_FILES =
# PROJECT_O_FILES = main.o fileb.o filec.o blah.o // if you have main.c fileb.c filec.c blah.c

# use for a "test" ... this way we don't have to include all files in a test
TEST_O_FILES =
# TEST_O_FILES = test_dog.o dog.o leash.o treats.o

# ONE NICE TRICK IS TO DEFINE A NEW TEST EACH TIME, e.g.

# TEST_O_FILES = FIRST_TEST_O_FILES
# FIRST_TEST_O_FILES = test_this.o this.o that.o

# This is really nice because then you can just keep adding tests and you only have to change TEST_O_FILES to your new list
# or define them in Tests.mak
-include tests.mak

###################################################################################
################################# BACK END ########################################
###################################################################################


############################## SETUP COMPILER #####################################
###################################################################################

### NOTE: the @ symbol at beginning of something stops make from 'echo-ing', so it can be used to make the temrinal output tidier

C_OR_CPP = $(C)
C = $(COMPILE_C)
CPP = $(COMPILE_CPP)

# C compilation
CC_V = gcc
CC_S = @gcc
CC = $(CC_V)

# Various C/C++ standards (language versions) can be specified.  gnu also enables gnu extensions - helpful bits you probably don't need
# so for example there's -std=c99 and -std=gnu99.  There's a lot of different options here.  11 seems to be a good choice.
# you can do gcc --version to find the gcc version, and then look up what language standards it supports.  https://gcc.gnu.org/releases.html
# For example, Delmar and Hoare have gcc 4.8.5 which is laughably out of date.

C_STD = -std=gnu11
CPP_STD = -std=gnu++11

# C++ compilation
CPP_V = g++
CPP_S = @g++
CPP = $(CC_V)

# Compilation flags shared for both languages.   -g is for debugging
COMP_FLAGS = -g

# Optimization flags shared for both languages.  -o3 is a nice place to be
OPT_FLAGS = -o3

# Flags just for C
C_FLAGS = 

# Flags just for C++
CPP_FLAGS =

COMPILE_C = $(CC) $(C_STD) $(COMP_FLAGS) $(C_FLAGS) $(OPT_FLAGS)
COMPILE_CPP = $(CPP) $(CPP_STD) $(COMP_FLAGS) $(CPP_FLAGS) $(OPT_FLAGS)

all :

# See: http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/#tldr

### EXPERIMENTAL ###
# grab all the c files in this folder
#ALL_SRCS = $(wildcard *.c)
# list them as o files
#ALL_O := ($ALL_SRCS:%.c=%.o)


################################# GENERIC RULES ###################################
################################################################################### 

DEL = -@rm -rf

.PHONY : project

# OUT FILES:  Make a .out file from any SINGLE .o file
# NOTE: used for test programs.

%.out : %.o
	@echo "Making executable $@..."
	$(C_OR_CPP) $(C_FLAGS) $(OPT_FLAGS) $< -o $@

# PROJECT

project :
	@echo "Making Executable: $(PROJECT_NAME)"
	@echo "-----------------------"
	$(C_OR_CPP) $(PROJECT_O_FILES) -o $(PROJECT_NAME)

# PROJECT

test :
	@echo "Making Test Executable: $(TEST_NAME)"
	@echo "-----------------------"
	$(C_OR_CPP) $(TEST_O_FILES) -o $(PROJECT_NAME)

# OBJECTS:  Make a .o file from any .c file  NOTE: that's what the -c flag does

%.o : %.c
	@echo "Making object $@..."
	$(C_OR_CPP) -c $< -o $@


################################# CLEANING RULES #################################
##################################################################################

.PHONY : clean clean_o clean_out clean_project

clean : clean_o clean_out clean_project

clean_o :
	@echo "Cleaning up .o files ..."
	$(DEL) */*.o
	$(DEL) *.o

clean_out :
	@echo "Cleaning up .out files ..."
	$(DEL) */*.out
	$(DEL) *.out

clean_test :
	@echo "Cleaning up test output ..."
	$(DEL) */*.out
	$(DEL) $(TEST_NAME)

clean_project :
	@echo "Cleaning up project output ..."
	$(DEL) */*.out
	$(DEL) $(PROJECT_NAME)

