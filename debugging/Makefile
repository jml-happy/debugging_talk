CC_V = gcc
CC_S = @gcc
CC = $(CC_S) -std=gnu11

C_FLAGS = -g
OPT_FLAGS = -o3

DEL = -@rm -rf

all :

# See: http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/#tldr

SRCS = $(wildcard *.c)

DEP_DIR := .deps
DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

COMPILE.c = $(CC) $(DEP_FLAGS) $(C_FLAGS) $(OPT_FLAGS) -c
#%.o : %.c
#	@echo "Making object $@..."
#	$(CC) -c $(C_FLAGS) $(OPT_FLAGS) $< -o $@

%.o : %.c
%.o : %.c $(DEP_DIR)/%.d | $(DEP_DIR)
	$(COMPILE.c) $(OPT_FLAGS) $<

$(DEPDIR): ; @mkdir -p $@

DEPFILES := $(SRCS:%.c=$(DEP_DIR)/%.d)
$(DEPFILES):

-include $(wildcard $(DEPFILES))

################################# DEPENDENCIES ###################################
##################################################################################
%.out : %.o
	@echo "Making executable $@..."
	$(CC) $(DEP_FLAGS) $(C_FLAGS) $(OPT_FLAGS) $< -o $@



################################# CLEANING RULES #################################
##################################################################################

.PHONY : clean clean_o clean_a clean_d clean_gch clean_out clean_project

clean : clean_o clean_a clean_d clean_gch clean_out clean_project

clean_o :
	@echo "Cleaning up .o files ..."
	$(DEL) */*.o
	$(DEL) *.o

clean_d :
	@echo "Cleaning up .d files ..."
	$(DEL) */*.d
	$(DEL) *.d

clean_out :
	@echo "Cleaning up .out files ..."
	$(DEL) */*.out
	$(DEL) *.out
