pdf = comparison.pdf vary_x.pdf vary_s.pdf
ps = comparison.ps vary_x.ps vary_s.ps

all: $(pdf) $(ps)

comparison.ps: comparison.jgr
	jgraph $^ > $@

vary_x.ps: vary_x.jgr
	jgraph $^ > $@

vary_s.ps: vary_s.jgr
	jgraph  $^ > $@

comparison.pdf: comparison.jgr
	jgraph -P $^ | ps2pdf - > $@

vary_x.pdf: vary_x.jgr
	jgraph -P $^ | ps2pdf - > $@

vary_s.pdf: vary_s.jgr
	jgraph -P $^ | ps2pdf - > $@

clean:
	rm -rf *.pdf *.ps
