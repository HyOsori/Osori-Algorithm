CXX = g++
INCLUDE = -I../include/
LIBNAME = -lpthread -lrt

CPPFLAGS += $(INCLUDE)
CXXFLAGS = -std=c++11 -g -W -Wall

all: test_list

test_list: ./test_list.cc ../util/*.cc
	$(CXX) $(INCLUDE) $(CXXFLAGS) -o $@ $^ $(LIBNAME)

clean:
	rm test_list
