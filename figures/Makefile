all: comparison.pdf vary_x.pdf vary_s.pdf

comparison.pdf: comparison.jgr
	jgraph -P $^ | ps2pdf - > $@

vary_x.pdf: vary_x.jgr
	jgraph -P $^ | ps2pdf - > $@

vary_s.pdf: vary_s.jgr
	jgraph -P $^ | ps2pdf - > $@

clean:
	rm -rf *.pdf
