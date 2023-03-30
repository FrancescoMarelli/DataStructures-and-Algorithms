# makefile for p4
# make : compiles the program
# make clean : removes all .o files
# make run : runs the program
# make execute : cleans the directory, compiles the program, and runs the program

p4_exe: src/p4_main.cc
	g++ -g -o p4_exe src/p4_main.cc

clean:
	rm -f *.o *.txt p4_exe

run: 
	./p4_exe

execute: clean ./p4_exe run

.PHONY: clean run execute
