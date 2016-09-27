CXX = g++

CPPFLAGS += -I include

CXX_SRCS := src/main.c

TARGET = sorting_exe

$(TARGET) : 
	$(CXX) -o bin/$(TARGET) $(CXX_SRCS) $(CPPFLAGS)

clean :
	rm bin/$(TARGET)
