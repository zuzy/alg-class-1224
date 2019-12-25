# # at := @
# CC := gcc
# LD := $(CC)

# CURRENT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

# APP_NAME := $(notdir $(CURRENT_DIR))
# MAKE_TARGET = $(APP_NAME)

# ROOT := $(CURRENT_DIR)../
# OBJS_ROOT = $(CURRENT_DIR)/obj


# # Strip sources.
# SOURCES += $(CURRENT_DIR)/test.c


# SOURCES := $(strip $(SOURCES))

# # Convert sources list to absolute paths and root-relative paths.
# SOURCES_ABS := $(foreach s,$(SOURCES),$(abspath $(s)))
# SOURCES_REL := $(subst $(CURRENT_DIR)/,,$(SOURCES_ABS))


# C_SOURCES = $(filter %.c,$(SOURCES_REL))
# OBJECTS_C := $(addprefix $(OBJS_ROOT)/,$(C_SOURCES:.c=.o))



# CFLAGS += -std=gnu11 -D LINUX -D _GNU_SOURCE -Werror
# CFLAGS += -g3 -O0 -DDEBUG -DYYDEBUG=1


# $(OBJS_ROOT)/%.o: $(CURRENT_DIR)/%.c
# 	echo  $@ $#
# 	# @$(call printmessage,c,Compiling, $(subst $(CURRENT_DIR)/,,$<))
# 	$(at)$(CC) $(CFLAGS) $(SYSTEM_INC) $(INCLUDES) $(DEFINES) -MMD -MF $(basename $@).d -MP -o $@ -c $<


# all:  $(OBJS_ROOT) $(MAKE_TARGET) 

# $(OBJS_ROOT) :
# 	$(at) mkdir -p $@

# $(OBJECTS_C): $(C_SOURCES)

# $(MAKE_TARGET): $(OBJECTS_C)
# 	$(at)$(LD) $(LDFLAGS) \
#           $(OBJECTS_C) \
#           -o $@

# .PHONY: clean
# clean:
# 	$(at) -rm -rf $(OBJS_ROOT) $(CURRENT_DIR)/$(MAKE_TARGET)

CURRENT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

APP_NAME := $(notdir $(CURRENT_DIR))
MAKE_TARGET = $(APP_NAME)

include ../Makefile

# .PHONY: all server
# all:
# server: 
# 	@$(call printmessage,build,Building, $(CUR_DIR) $@ ,gray,,,\n)
# 	@make -r -f ../Makefile TEST_NAME=$(CUR_DIR) TYPE=SERVER TRANSPORT=tcp