TARGET := libfunc.a
all: $(TARGET)
# $(TARGET)($(TARGET:a=o)): $(patsubst %.o, %c, $(wildcard *.c))

# $(TARGET): $(patsubst %.o, %c, $(wildcard *.c))
$(TARGET) : $(basename $(wildcard *.c)).o
	$(AR) $(ARFLAGS) $@ $?

.PHONY: clean
clean:
	-rm -rf *.o *.a
