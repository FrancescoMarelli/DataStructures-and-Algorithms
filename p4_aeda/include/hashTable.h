#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>


#include "sequence.h"
#include "dispersionFunction.h"
#include "block.h"
#include "explorationFunction.h"

template <class Key>
class HashTable {
    private:
    unsigned tableSize; // Number of positions in the table
    std::vector<Sequence<Key>*> table;
    DispersionFunction<Key> *fd;
    int blockSize;  
    ExplorationFunction<Key> *fe;

    public:
    HashTable(unsigned , DispersionFunction<Key>*, int blockSize = 0, ExplorationFunction<Key> *fe = nullptr);
    ~HashTable(){}

    bool search(const Key& key) const;
    bool insert(const Key& key);

    unsigned getTableSize() const { return tableSize; }
    std::vector<Sequence<Key>*> getTable() const { return table; }
    DispersionFunction<Key>* getFd() const { return fd; }
    int getBlockSize() const { return blockSize; }
    ExplorationFunction<Key>* getFe() const { return fe; }
    void print() const;
    template<class Key_t>
    friend std::ostream& operator<<(std::ostream& os, const HashTable<Key_t>& ht);
   
};

template <class Key>
HashTable<Key>::HashTable(unsigned tableSize, DispersionFunction<Key> *fd, int blockSize , ExplorationFunction<Key> *fe) {
    this->tableSize = tableSize;
    this->fd = fd;
    this->blockSize = blockSize;
    this->fe = fe;
    bool isOpen = (fe == nullptr);

    for(unsigned i = 0; i < tableSize; i++) {
        Sequence<Key>* seq;
        if(isOpen) {
            seq = new List<Key>;
        } else {
            seq = new Block<Key>(blockSize);
        }
        table.push_back(seq);
    }
}

template <class Key>
bool HashTable<Key>::search(const Key& key) const {
    unsigned i = 0;
    unsigned pos = (*fd)(key); 
    
    if (fe == nullptr) {
        return (table[pos]->search(key));
    } else {
        while (i < tableSize) {
            int explore = ((pos + fe->operator()(key, i)) % tableSize); // Se calcula la posición a explorar
            if (table[explore]->search(key)) { // Si se encuentra la clave en la posición explorada, se devuelve true
                return true;
            }
            i++;
        }
    }
    return false;
}

template <class Key>
bool HashTable<Key>::insert(const Key& key) {
  
  int pos = (*fd)(key);
  int exploration = 0;
  
  // Si no hay función de exploración, se inserta en la posición que devuelve la función de dispersión
  if (fe == nullptr) {
    bool isCollided = table[pos]->search(key);
    if (isCollided) {
      std::cout << "La clave ya se encuentra en la tabla" << std::endl;
      std::cout << std::endl;
      return false;
    } 
    // Se inserta
    table[pos]->insert(key);
    std::cout << "La clave se ha insertado en la posición: " << pos << std::endl;
    std::cout << std::endl;
    return true;
  } else {
    for (int i = 0; i < tableSize; ++i) {    
      // Se calcula la posición a explorar 
      int exploration = (pos + (*fe)(key, i)) % tableSize;  
      bool isCollided = table[exploration]->search(key);    
      if (isCollided) {
        std::cout << "La clave ya se encuentra en la tabla" << std::endl;
        std::cout << std::endl;
        return false;
      }      
      bool isInserted = table[exploration]->insert(key);
      if (isInserted) {
        std::cout << "La clave se ha insertado en la posición: " << exploration << std::endl;
        std::cout << std::endl;
        return true;
      }
    }    
  }
  return false;
}

template <class Key>
void HashTable<Key>::print() const {
    for(unsigned i = 0; i < tableSize; i++) {
        std::cout << "Posición " << i << ": ";
        table[i]->print();
    }
    std::cout << std::endl;
}

template <class Key_t>
std::ostream& operator<<(std::ostream& os, const HashTable<Key_t>& ht) {
  for(unsigned i = 0; i < ht.tableSize; i++) {
    os << "Posición " << i << ": ";
    ht.table[i] -> write(os);
    os << std::endl;
  }
    return os;
}


#endif // HASHTABLE_H