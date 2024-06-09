# Define compiler and flags
CC = gcc
CFLAGS = -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit

# Define the source directory and source files
SRCDIR = src
SRCS = $(wildcard $(SRCDIR)/*.c)

# Define the object directory and object files
OBJDIR = obj
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Define the target executable
TARGET = main

# Default target
all: $(TARGET)

# Compile the source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link the object files into the target executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Clean up the build files
clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean

