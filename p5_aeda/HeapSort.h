#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_


#include "SortMethod.h"

template <class Key>
class HeapSort : public SortMethod<Key> {
    
    public:
    HeapSort(unsigned size, std::vector<Key>& seq, bool trace);

    void Sort() override;
    void print();
};

template <class Key>
HeapSort<Key>::HeapSort(unsigned size, std::vector<Key>& seq, bool trace): 
    SortMethod<Key>(size, seq, trace) {}

template <class Key>
void HeapSort<Key>::Sort() {
    this-> seq = HeapSort_algorithm(this->size, this->seq, this->trace);
    this->size = this->seq.size();
}


template <class Key>
void HeapSort<Key>::print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->seq[i] << " ";
    }
    std::cout << std::endl;
}

#endif