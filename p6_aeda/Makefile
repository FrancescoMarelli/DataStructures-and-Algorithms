#makefile
# make: compiles program
# make clean: removes object files
# make run: executes program
# make execute: runs make clean, make, and make run
# make trace: allow to make execute but with trace

p6_execute: src/main_p6.cc
	g++ -Wall -o  p6_execute src/main_p6.cc

p6_trace_execute: src/main_p6.cc
	g++ -DTRAZA -Wall -o  p6_trace_execute src/main_p6.cc

clean:
	rm -f *.o p6_execute

run:
	./p6_execute

run_trace:
	./p6_trace_execute

execute: clean ./p6_execute run

trace: clean ./p6_trace_execute run_trace

.PHONY: clean run execute
