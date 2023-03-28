#ifndef BLOCK_H
#define BLOCK_H

#include "sequence.h"
#include <vector>

template <class Key>
class Block : public Sequence<Key> {
    private:
    std::vector<Key> block;
    unsigned size;
    unsigned flag;
    
    public:
    Block(const unsigned size);  
    bool insert(const Key& key);
    bool search(const Key& key) const;
    bool isFull() const;
    void print() const;
    void write(std::ostream& os) const;

};

template <class Key>
Block<Key>::Block(const unsigned size) {
    this->size = size;
    this->flag = 0;
    for(unsigned i = 0; i < size; i++)
        block.push_back(0);
    
}

template <class Key>
bool Block<Key>::isFull() const {
    return flag == size;
}

template <class Key>
bool Block<Key>::insert(const Key& key) {
    if (isFull()) {
        return false;
    } else {
        block[flag] = key;
        flag++;
        return true;
    }
}

template <class Key>
bool Block<Key>::search(const Key& key) const {
    int iter = 0;
    bool found = false;
    for(unsigned i = 0; i < size; i++) {
        iter++;
        if (block[i] == key) {
            found = true;
            std::cout << "Iteraciones: " << iter << std::endl;
            return found;
        }
    }
    return found;
}

template <class Key>
void Block<Key>::print() const {
    for(unsigned i = 0; i < size; i++) {
        std::cout << block[i] << " ";
    }
    std::cout << std::endl;
}


template <class Key>
void Block<Key>::write(std::ostream& os) const {

    for(unsigned i = 0; i < size; i++) {
        os << block[i] << " ";
    }
    
}


#endif // BLOCK_H