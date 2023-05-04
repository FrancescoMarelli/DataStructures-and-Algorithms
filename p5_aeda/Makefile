#makefile
# make: compiles program
# make clean: removes object files
# make run: executes program
# make execute: runs make clean, make, and make run

p5_execute: main_p5.cc
	g++ -Wall -Wno-sign-compare -g -o  p5_execute main_p5.cc

clean:
	rm -f *.o p5_execute

run:
	./p5_execute

execute: clean ./p5_execute run

.PHONY: clean run execute
