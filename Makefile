CXXFLAGS = -g -Wall

SOURCES = tests.cpp
HEADERS = DiccString.hpp
OBJS = $(SOURCES:.cpp=.o)

LIBS =

TARGET = tests

$(TARGET): $(OBJS) $(HEADERS)  
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

valgrind: all
	valgrind --leak-check=full ./$(TARGET)
