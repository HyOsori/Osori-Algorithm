CXX = g++

CPPFLAGS += -I include

CXX_SRCS := src/main.cc

TARGET = linked_list_exe

$(TARGET) : 
	$(CXX) -o bin/$(TARGET) -g $(CXX_SRCS) $(CPPFLAGS)

clean :
	rm bin/$(TARGET)
