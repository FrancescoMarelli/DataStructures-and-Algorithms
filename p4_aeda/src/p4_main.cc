#include <iostream>
#include <unistd.h>
#include <fstream>

#include "../include/hashTable.h"
#include "functions.cc"
#include "../include/vehicle.h"

int main() {

   unsigned blockSize;
   unsigned tableSize;
   ExplorationFunction<long>* fe = nullptr;
   DispersionFunction<long>* fd; 
   int dispersionType = 0;
   

   try {
    tableSize = functions::selectTableSize(tableSize);
    fd = functions::selectDispersionFunction(fd, tableSize);
    dispersionType = functions::selectDispersionType();

    if(dispersionType == 2) {
        blockSize = functions::selectBlock(blockSize);
        fe = functions::selectExplorationFunction(fe, fd);
    }

    HashTable<long> hashTable(tableSize, fd, blockSize, fe);
    functions::Menu(hashTable);

    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit(-1);
    }
    
    delete fd;
    delete fe;

  return 0;
}



