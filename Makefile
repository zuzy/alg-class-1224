at := @
CC := gcc
LD := $(CC)

# CURRENT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

APP_NAME := $(notdir $(CURRENT_DIR))
MAKE_TARGET = $(APP_NAME)

ROOT := $(CURRENT_DIR)../
OBJS_ROOT = $(CURRENT_DIR)/obj


# Strip sources.
SOURCES += $(CURRENT_DIR)/test.c


SOURCES := $(strip $(SOURCES))

# Convert sources list to absolute paths and root-relative paths.
SOURCES_ABS := $(foreach s,$(SOURCES),$(abspath $(s)))
SOURCES_REL := $(subst $(CURRENT_DIR)/,,$(SOURCES_ABS))


C_SOURCES = $(filter %.c,$(SOURCES_REL))
OBJECTS_C := $(addprefix $(OBJS_ROOT)/,$(C_SOURCES:.c=.o))



CFLAGS += -std=gnu11 -D LINUX -D _GNU_SOURCE -Werror
CFLAGS += -g3 -O0 -DDEBUG -DYYDEBUG=1


$(OBJS_ROOT)/%.o: $(CURRENT_DIR)/%.c
	$(at)$(CC) $(CFLAGS) $(SYSTEM_INC) $(INCLUDES) $(DEFINES) -MMD -MF $(basename $@).d -MP -o $@ -c $<


all:  $(OBJS_ROOT) $(MAKE_TARGET) 

$(OBJS_ROOT) :
	$(at) mkdir -p $@

$(OBJECTS_C): $(C_SOURCES)

$(MAKE_TARGET): $(OBJECTS_C)
	$(at)$(LD) $(LDFLAGS) \
          $(OBJECTS_C) \
          -o $@

.PHONY: clean
clean:
	$(at) -rm -rf $(OBJS_ROOT) $(CURRENT_DIR)/$(MAKE_TARGET)

.PHONY: test
test:
	$(at)echo Testing $(MAKE_TARGET)
	$(at)$(CURRENT_DIR)/$(MAKE_TARGET) &

.PHONY: kill
kill:
	ps -ef | grep '$(MAKE_TARGET)' | awk '{print $$2}' | xargs kill -9


