#make run
#make clean
#make all

# Path: src/Makefile
merge3: merge3.cc
	g++ -std=c++11 -o merge3 merge3.cc

# Path: src/Makefile
#make clean
clean: 
	rm -f *.o merge3

run: merge3
	./merge3

execute: clean merge3 run

.PHONY: clean run execute