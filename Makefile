CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11

EXEC = main

all: $(EXEC)

main: main.cpp DigitStringDiv1.o
	$(CXX) $(CXXFLAGS) -o $@ $^

run: main
	for i in $$(seq 0 13); do \
		./main $$i;							\
	done

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf $(EXEC) *.o
