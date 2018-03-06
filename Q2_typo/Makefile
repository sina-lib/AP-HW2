CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXX = g++
LXXFLAGS = -std=c++17

OBJECTS = main.o
TARGET = findTypo

$(TARGET): $(OBJECTS)
	$(LXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

clean:
	rm -f $(OBJECTS) $(TARGET)
