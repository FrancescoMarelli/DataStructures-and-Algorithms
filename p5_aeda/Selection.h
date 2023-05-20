#ifndef _SELECTION_H_
#define _SELECTION_H_

#include "SortMethod.h"

template <class Key>
class Selection : public SortMethod<Key> {

    private:
    int count = 0;

    public:
    Selection(unsigned size, std::vector<Key>& seq, bool trace);
    void Sort() override ;
    void print();
    //getter
    int getCount() { return count; }
};

template <class Key>
Selection<Key>::Selection(unsigned size, std::vector<Key>& seq, bool trace): 
    SortMethod<Key>(size, seq, trace) {}

template <class Key>
void Selection<Key>::Sort(){
    this -> seq = SelectionSort(this -> seq, this -> size, this -> trace, count);
}

template <class Key>
void Selection<Key>::print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->seq[i] << " ";
    }
    std::cout << std::endl;
}

#endif