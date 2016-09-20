CXX = g++
CPPFLAGS += -Iinclude
CXXFLAGS += -std=c++11 -g -W -Wall -fPIC

CXX_SRCS := $(wildcard util/*cc)         \
            $(wildcard src/*.cc)
OBJS := $(CXX_SRCS:.cc=.o)
BIN = bin/
LIB = lib/

all: test

test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN)$@ $^ -L $(LIB)

clean:
	rm $(BIN)test $(OBJS)

