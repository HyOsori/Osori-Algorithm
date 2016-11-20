CXX = g++

CPPFLAGS += -I include 

CXX_SRCS := src/*.cpp

OBJS := src/*.cpp

TARGET = dynamic_table_exe

$(TARGET) :$(OBJS)
	$(CXX) -o bin/$@ $^ $(CPPFLAGS)
clean :
	rm bin/$(TARGET)
