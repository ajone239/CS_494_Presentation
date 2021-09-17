CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11

EXEC = main

all: $(EXEC)

main: main.cpp DigitStringDiv1.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf $(EXEC) *.o
