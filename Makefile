CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11

EXEC = main
REPORT = report/prezzie.pdf

all: $(EXEC) $(REPORT)

main: main.cpp DigitStringDiv1.o
	$(CXX) $(CXXFLAGS) -o $@ $^

run: main
	for i in $$(seq 0 13); do \
		./main $$i;							\
	done

$(REPORT): report/prezzie.tex
	$(MAKE) -C ./report/

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf $(EXEC) *.o
	$(MAKE) clean -C report
