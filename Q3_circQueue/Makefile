CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXX = g++
LXXFLAGS = -std=c++17

OBJECTS = main.o queue.o
TARGET = exe

$(TARGET) : $(OBJECTS)
	$(LXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
queue.o: queue.cpp
	$(CXX) $(CXXFLAGS) queue.cpp
main.o: main.cpp Queue.h
	$(CXX) $(CXXFLAGS) main.cpp

clean:
	rm -f $(OBJECTS) $(TARGET)
