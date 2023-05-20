#ifndef _MERGESORT_H_
#define _MERGESORT_H_


#include "SortMethod.h"

template <class Key>
class MergeSort : public SortMethod<Key> {
    
    public:
    MergeSort(unsigned size, std::vector<Key>& seq, bool trace);
    void Sort() override ;
    void print();
};


template <class Key>
MergeSort<Key>::MergeSort(unsigned size, std::vector<Key>& seq, bool trace) :
    SortMethod<Key>(size, seq, trace) {}

template <class Key>
void MergeSort<Key>::Sort() {
    typename std::vector<Key>::iterator ini = this->seq.begin();
    typename std::vector<Key>::iterator fin = this->seq.end();
    this->seq = MergeSort_algorithm(this->size, this->seq, ini, fin, this->trace);
}



template <class Key>
void MergeSort<Key>::print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->seq[i] << " ";
    }
    std::cout << std::endl;
}

#endif