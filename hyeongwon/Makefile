CXX = g++   # Compiler

CPPFLAGS += -I include
CXXFLAGS += -std=c++11 -g -W -Wall -fPIC

CXX_SRCS := $(wildcard util/*cc)         \
            $(wildcard src/*.cc)
OBJS := $(CXX_SRCS:.cc=.o)
BIN = bin/
LIB = lib/

all: test

test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN)$@ $(OBJS) -L $(LIB)

clean:
	rm $(BIN)test $(OBJS)

