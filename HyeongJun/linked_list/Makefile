CXX = g++

CPPFLAGS += -I include

CXX_SRCS := src/main.cc src/linked_list.cc

TARGET = bin/exe

debug :
	$(CXX) -g -o $(TARGET) $(CXX_SRCS) $(CPPFLAGS)
$(TARGET) : 
	$(CXX) -o $(TARGET) $(CXX_SRCS) $(CPPFLAGS)

clean :
	rm $(TARGET)
