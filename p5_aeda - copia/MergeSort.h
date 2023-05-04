#ifndef _MERGESORT_H_
#define _MERGESORT_H_


#include "SortMethod.h"

template <class Key>
class MergeSort : public SortMethod<Key> {
    private:
    unsigned size;
    std::vector<Key> seq;

    public:
    MergeSort(unsigned size, std::vector<Key>& seq);
    void Sort() override ;
    void merge(std::vector<Key>& sec, int i, int j, int k);
    void print();
};


template <class Key>
MergeSort<Key>::MergeSort(unsigned size, std::vector<Key>& seq) {
    this->size = size;
    this->seq = seq;
}

template <class Key>
void MergeSort<Key>::Sort() {
    int i = 0;
    int j = 0;
    int k = 0;
    for (int x = 1; x < size; x = 2 * x) {
        for (int i = 0; i < size - 1; i += 2 * x) {
            j = i + x - 1;
            k = i + 2 * x - 1;
            if (k >= size) {
                k = size - 1;
            }
            merge(seq, i, j, k);
        }
    }
}

template <class Key>
void MergeSort<Key>::merge(std::vector<Key>& sec, int i, int j, int k) {
    int l = i;
    int m = j + 1;
    int n = k - i + 1;
    std::vector<Key> temp(n);
    for (int x = 0; x < n; x++) {
        if (l > j) {
            temp[x] = sec[m];
            m++;
        }
        else if (m > k) {
            temp[x] = sec[l];
            l++;
        }
        else if (sec[l] < sec[m]) {
            temp[x] = sec[l];
            l++;
        }
        else {
            temp[x] = sec[m];
            m++;
        }
    }
    for (int x = 0; x < n; x++) {
        sec[i] = temp[x];
        i++;
    }
}

template <class Key>
void MergeSort<Key>::print() {
    for (int i = 0; i < size; i++) {
        std::cout << seq[i] << " ";
    }
    std::cout << std::endl;
}

#endif