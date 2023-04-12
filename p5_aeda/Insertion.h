#ifndef _INSERTION_H_
#define _INSERTION_H_

#include "SortMethod.h"

template <class Key>
class Insertion : public SortMethod<Key> {
    private:
    unsigned size;
    std::vector<Key> seq;

    public:
    Insertion(unsigned size, std::vector<Key>& seq);
    void Sort() override ;
    void print();
};


template <class Key>
Insertion<Key>::Insertion(unsigned size, std::vector<Key>& seq) {
    this->size = size;
    this->seq = seq;
}

template <class Key>
void Insertion<Key>::Sort() {
    for (int i = 1; i < size; i++) {
        int x = seq[i];
        int j = i - 1;
        std::cout << "Iteration: " << i <<": ";
        while (seq[j] > x && j >= 0) {
            seq[j + 1] = seq[j];
            j--;
        }
        seq[j + 1] = x;
        print();
    }
}

template <class Key>
void Insertion<Key>::print() {
    for (int i = 0; i < size; i++) {
        std::cout << seq[i] << " ";
    }
    std::cout << std::endl;
}


#endif