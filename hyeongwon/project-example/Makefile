# Compiler and Compile options.
CC = g++
CXXFLAGS = -std=c++11 -g -Wall -fPIC -O3

# Macros specifying path for compile.
BIN = bin
SRCDIR = src
BUILDDIR = build
INC = include

SRCS := $(shell find $(SRCDIR) -type f -name *.cc)
OBJS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRCS:.cc=.o))
#SRCS := $(wildcard $(SRCDIR)/*.cc)
#OBJS := $(SRCS:.cc=.o)

# Pre-Processor.
CPPFLAGS += -I $(INC)

# Target program
TARGET := print_hello

# Compile command.
$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) $(CPPFLAGS) -o $(BIN)/$(TARGET) $(OBJS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cc
	$(CC) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

# Delete binary & object files.
clean:
	rm $(BIN)/$(TARGET) $(OBJS)


