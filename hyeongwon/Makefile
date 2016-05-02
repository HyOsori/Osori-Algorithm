.SUFFIXES : .c .cpp .o
CC = g++

CFLAGS = -g -Wall
 all : hw

OBJS = ./src/main.o
SRCS = ./src/$(OBJS:.o=.cpp)
BIN = ./bin/
LIB = ./lib
INCLUDE = ./include
LIBNAME = -lpthread -lrt

CFLAGS += -I$(INCLUDE)

hw: $(OBJS)
	$(CC) -std=c++11 -g -o $(BIN)main $(OBJS) $(LIBNAME) -L$(LIB) -O3

clean:
	rm -rf $(OBJS)

allclean:
	rm -rf $(OBJS) $(BIN)*
