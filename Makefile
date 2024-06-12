# Define compiler and flags
CC = gcc
CFLAGS = -I/opt/homebrew/include -I/opt/homebrew/include/list
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit

# Define the source directory and find all source files
SRCDIR = src
SRCFILES = $(shell find $(SRCDIR) -name '*.c')

# Define the object directory and object files
OBJDIR = obj
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCFILES))

# Define the target executable
TARGET = main

rebuild: clean all

# Default target
all: $(TARGET)

# Compile the source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link the object files into the target executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Clean up the build files
clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean

