#include <iostream>

#include "SortMethod.h"

template <class Key>
Insertion<Key> InsertionSort() {
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


