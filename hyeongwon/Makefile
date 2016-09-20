CXX = g++
CPPFLAGS += -Iinclude
CXXFLAGS += -std=c++11 -g -W -Wall -fPIC

CXX_SRCS := $(wildcard util/*cc)         \
            $(wildcard src/*.cc)
OBJS := $(CXX_SRCS:.cc=.o)
BIN = bin/
LIBNAME = -lpthread 

all: test

test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN)$@ $^ $(LIBNAME)

clean:
	rm $(BIN)test $(OBJS)

