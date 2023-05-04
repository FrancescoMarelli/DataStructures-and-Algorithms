#include <iostream>
#include <unistd.h>
#include <fstream>

#include "../include/hashTable.h"
#include  "../include/Libro.h"
#include "../include/Libro.h"


int main() {

   unsigned blockSize;
   unsigned tableSize;
   ExplorationFunction<Libro>* fe = nullptr;
   DispersionFunction<Libro>* fd; 
   int dispersionType = 0;
   

   tableSize = 10;
   fd = new FdModule<Libro>(tableSize);
 
   HashTable<Libro> ht(tableSize, fd, blockSize, fe);
   ht.insert(Libro("1234567890"));
   ht.print();
    
    delete fd;
    delete fe;

  return 0;
}

