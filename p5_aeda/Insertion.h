#ifndef _INSERTION_H_
#define _INSERTION_H_

#include "SortMethod.h"

template <class Key>
class Insertion : public SortMethod<Key> {

    private:
    int count = 0;

    public:
    Insertion(unsigned size, std::vector<Key>& seq, bool trace);
    void Sort() override ;
    void print();
    //getter
    int getCount() { return count; }
};


template <class Key>
Insertion<Key>::Insertion(unsigned size, std::vector<Key>& seq, bool trace): 
    SortMethod<Key>(size, seq, trace) {}


template <class Key>
void Insertion<Key>::Sort() {
   this->seq = InsertionSort(this->seq, this->size, this->trace, count);
}

template <class Key>
void Insertion<Key>::print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->seq[i] << " ";
    }
    std::cout << std::endl;
}


#endif