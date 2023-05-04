#makefile
# make: compiles program
# make clean: removes object files
# make run: executes program
# make execute: runs make clean, make, and make run

p6_execute: src/main_p6.cc
	g++ -Wall -o  p6_execute src/main_p6.cc

clean:
	rm -f *.o p6_execute

run:
	./p6_execute

execute: clean ./p6_execute run

.PHONY: clean run execute
