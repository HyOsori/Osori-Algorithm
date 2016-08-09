CXX = g++
CPPFLAGS += -Iinclude
CXXFLAGS += -std=c++11 -pg -g -W -Wall

CXX_SRCS := $(wildcard util/*cc)         \
            $(wildcard src/*.cc)
OBJS := $(CXX_SRCS:.cc=.o)
BIN = bin/
LIBNAME = -lpthread -lrt

all: test

test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN)$@ $^ $(LIBNAME)

clean:
	rm $(BIN)test $(OBJS) *.txt *.txt.swp

