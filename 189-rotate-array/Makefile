CC = gcc

VPATH = ../func

INCLUDES += -I../func
LOADLIB += -L../func
LDLIB += -lfunc

CFLAGS += $(INCLUDES)

CURRENT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

APP_NAME := $(notdir $(CURRENT_DIR))
MAKE_TARGET = $(APP_NAME)

.PHONY: all

all: $(APP_NAME)

%.d: %.c 
	@set -e; rm -f $@; \
    $(CC) $(CPPFLAGS) $(INCLUDES) -MM $< > $@.$$$$; \
    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

# include ../Makefile



sources = $(wildcard *.c)

objs = $(patsubst %.c, %.o, $(sources))
# $(objs): %.o: %.c
# 	gcc -c $< -o $@

include $(sources:.c=.d)


$(APP_NAME): $(objs)
	gcc $(INCLUDES) -o $(APP_NAME) $? $(LOADLIB) $(LDLIB)

.PHONY: clean
clean:
	@-rm -rf obj $(APP_NAME) *.d.* *.o *.d