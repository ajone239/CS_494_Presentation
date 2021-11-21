CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11

EXEC = main
REPORT = report/prezzie.pdf
FIGURES = figures/comparison.pdf figures/vary_s.pdf figures/vary_x.pdf
FIGURES_src = figures/comparison.jgr figures/vary_s.jgr figures/vary_x.jgr

all: $(EXEC) $(REPORT) $(FIGURES)

main: main.cpp DigitStringDiv1.o
	$(CXX) $(CXXFLAGS) -o $@ $^

run: main
	for i in $$(seq 0 13); do \
		echo $$i;		 						\
		./main $$i;							\
	done

$(FIGURES): $(FIGURES_src)
	$(MAKE) -C ./figures/


$(REPORT): $(FIGURES) report/prezzie.tex
	$(MAKE) -C ./report/

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf $(EXEC) *.o
	$(MAKE) clean -C report
	$(MAKE) clean -C figures
