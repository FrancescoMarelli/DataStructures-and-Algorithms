#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include "SortMethod.h"

template <class Key>
class QuickSort : public SortMethod<Key> {

    private:
    int count = 0;

    public:
    QuickSort(unsigned size, std::vector<Key>& seq, bool trace);
    void Sort() override ;
    void print();
    //getter
    int getCount() { return count; }
};

template <class Key>
QuickSort<Key>::QuickSort(unsigned size, std::vector<Key>& seq, bool trace): 
    SortMethod<Key>(size, seq, trace) {}

template <class Key>
void QuickSort<Key>::Sort(){
    this -> seq = QuickSort_alg(this -> seq, 0,(this -> size - 1), this -> trace);
}

template <class Key>
void QuickSort<Key>::print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->seq[i] << " ";
    }
    std::cout << std::endl;
}

#endif