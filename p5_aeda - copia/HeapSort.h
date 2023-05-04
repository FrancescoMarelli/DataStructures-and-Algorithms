#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_


#include "SortMethod.h"

template <class Key>
class HeapSort : public SortMethod<Key> {
    private:
    unsigned size;
    std::vector<Key> seq;

    public:
    HeapSort(unsigned size, std::vector<Key>& seq) : size(size), seq(seq) {}
    void Sort() override;
    void downheap(std::vector<Key>& sec, int i, int x);
    void print();
};

template <class Key>
void HeapSort<Key>::Sort() {
    for (int i = size / 2; i >= 0; i--) {
        downheap(seq, i, size - 1);
    }
    for (int i = size - 1; i >= 1; i--) {
        std::swap(seq[0], seq[i]);
        downheap(seq, 0, i - 1);
    }
}

template <class Key>
void HeapSort<Key>::downheap(std::vector<Key>& sec, int i, int x) {
    int j = 2 * i;
    while (j <= x) {
        if (j < x && sec[j] < sec[j + 1]) {
            j++;
        }
        if (sec[i] >= sec[j]) {
            break;
        }
        std::swap(sec[i], sec[j]);
        i = j;
        j = 2 * i;
        std::cout << "Iteration: ";
        print();
    }
    
}

template <class Key>
void HeapSort<Key>::print() {
    for (int i = 0; i < size; i++) {
        std::cout << seq[i] << " ";
    }
    std::cout << std::endl;
}

#endif