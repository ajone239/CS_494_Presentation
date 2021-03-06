CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11

EXEC = main
REPORT = report/prezzie.pdf
FIGURES = figures/comparison.ps figures/vary_s.ps figures/vary_x.ps
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


$(REPORT): $(FIGURES) $(FIGURES_src) report/prezzie.tex
	$(MAKE) -C ./report/

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -rf $(EXEC) *.o
	$(MAKE) clean -C report
	$(MAKE) clean -C figures
