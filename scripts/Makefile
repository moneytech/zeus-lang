####################
# Zeus - A general purpose programming language
####################
PROJECT			=	zeus
# System tools
AR					= ar
CC					= gcc
AR_FLAGS		=	rcs
CC_FLAGS		= -g -Wall -pedantic -pedantic-errors -std=c99
CC_LIB			= -lm
# Top level directories
DIR_ROOT 		= ..
DIR_SRC 		= $(DIR_ROOT)/src
DIR_SCRIPTS = $(DIR_ROOT)/scripts
DIR_BUILD 	= $(DIR_ROOT)/build
DIR_DIST		= $(DIR_ROOT)/distributable
# Source subdirectories
DIR_LIB_SRC			= $(DIR_SRC)/language
DIR_TARGET_SRC	= $(DIR_SRC)/zeus
# Build subdirectories
DIR_OBJ			= $(DIR_BUILD)/obj
DIR_BIN			= $(DIR_BUILD)/bin
DIR_LIB			= $(DIR_BUILD)/lib
# File paths
LIB_TARGET_SRC			= $(wildcard $(DIR_LIB_SRC)/**/**/**/**/**/*.c)
TARGET_SRC					= $(wildcard $(DIR_SRC)/**/*.c)
LIB_TARGET_HEADERS	= $(wildcard $(DIR_LIB_SRC)/**/**/**/**/**/*.h)
TARGET_HEADERS			= $(wildcard $(DIR_SRC)/**/**/**/**/**/*.h)
HEADERS							= $(LIB_TARGET_HEADERS) $(TARGET_HEADERS)
# Artifact patterns
LIB_TARGET_OBJ	= $(patsubst $(DIR_LIB_SRC)/%.c,$(DIR_OBJ)/%.o,$(LIB_TARGET_SRC))
TARGET_OBJ			= $(patsubst $(DIR_SRC)/%.c,$(DIR_OBJ)/%.o,$(TARGET_SRC))
OBJ							= $(LIB_TARGET_OBJ) $(TARGET_OBJ)
# Targets
LIB_TARGET	= $(DIR_LIB)/lib$(PROJECT).a
TARGET			= $(DIR_BIN)/$(PROJECT)
####################
# Build rules
####################
.PHONY: default clean all library executable
build_dirs:
	-mkdir -p $(DIR_BUILD)
	-mkdir -p $(DIR_OBJ)
	-mkdir -p $(DIR_BIN)
	-mkdir -p $(DIR_LIB)
# Build zeus.exe linking libzeus.a to it
$(TARGET): $(TARGET_OBJ) $(LIB_TARGET)
	-mkdir -p $(@D)
	$(CC) $(CC_FLAGS) $(TARGET_OBJ) -o $@ -L$(DIR_LIB) -l$(PROJECT) -I$(DIR_SRC) $(HEADERS)
# Build libzeus.a
$(LIB_TARGET): $(LIB_TARGET_OBJ)
	-mkdir -p $(@D)
	$(AR) $(AR_FLAGS) $@ $?
# Build .o files
$(OBJ): $(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADERS)
	-mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -c $< -o $@ -I$(DIR_LIB_SRC)

all: clean $(build_dirs) $(LIB_TARGET) $(TARGET)
library: $(LIB_TARGET)
executable: $(TARGET)
clean:
	-rm -r $(DIR_BUILD)
