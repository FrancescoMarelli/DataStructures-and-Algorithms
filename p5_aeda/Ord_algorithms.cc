#include <iostream>

#include "SortMethod.h"


/*
    *  InsertionSort
*/
template <typename Key>
std::vector<Key> InsertionSort(std::vector<Key>& seq, unsigned size, bool trace, int& count) {
    for (int i = 1; i < size; i++) {
        int x = seq[i];
        int j = i - 1;
        if(trace == true) std::cout << "Iteration: " << i <<": ";
        while (seq[j] > x && j >= 0) {
            seq[j + 1] = seq[j];
            j--;
            count++;
        }
        seq[j + 1] = x;
        count++;

        if(trace == true) {
            for (int i = 0; i < size; i++) {
                std::cout << seq[i] << " ";
            }
            std::cout << std::endl;
        }
        
    }
    std::cout << "Numero de movimientos: " << count << std::endl;
    return seq;
}

/*
    *  MergeSort
*/


template <typename Key>
void downheap(std::vector<Key>& sec, int i, int x, bool trace) {
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
    }
    if(trace == true) {
        for (int i = 0; i < sec.size(); i++) {
            std::cout << sec[i] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename Key>
std::vector<Key> HeapSort_algorithm(unsigned size, std::vector<Key>& seq, bool trace) {
    int iterador = 0;
    for (int i = size / 2; i >= 0; i--) {
        if (trace) iterador++;
        std::cout << "Iteration " << iterador <<": ";
        downheap(seq, i, size - 1, trace);
    }
    
    for (int i = size - 1; i >= 1; i--) {
        
        std::swap(seq[0], seq[i]);
        if(trace) {
            iterador++;
            std::cout << "Iteration " << iterador <<": ";
        }
        downheap(seq, 0, i - 1, trace);
    }
    return seq;
}

/*
    * MergeSort.h
    *
    *  Created on: 2019. 4. 10.

*/

template <class Key>
void merge(std::vector<Key>& sec, int left, int middle, int right, bool trace) {
    int l = left;
    int m = middle + 1;
    int n = right - left + 1;
    std::vector<Key> temp(n);
    for (int x = 0; x < n; x++) {
        if (l > middle) {
            temp[x] = sec[m];
            m++;
        }
        else if (m > right) {
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
        sec[left] = temp[x];
        left++;
        
    }
    if(trace == true) {
        for (int i = 0; i < sec.size(); i++) {
            std::cout << sec[i] << " ";
        }
        std::cout << std::endl;
    }

}

template <typename Key>
std::vector<Key> MergeSort_algorithm(unsigned size, std::vector<Key>& seq, bool trace) {
    //int left = 0;
    int middle = 0;
    int right = 0;
    int iterador = 0;
    for (int subArrSize = 1; subArrSize < size; subArrSize = 2 * subArrSize) {
        for (int left = 0; left < size - 1; left += 2 * subArrSize) {
            middle = left + subArrSize - 1;
            right = left + 2 * subArrSize - 1;
            if (right >= size) {
                right = size - 1;
            }
            if(trace) iterador++;
            std::cout << "Iteration " << iterador <<": ";
            merge(seq, left,middle, right, trace);
        }
    }
    return seq;
}

/*  
    RadixSort.h
*/

template <typename Key>
std::vector<Key> RadixSort_algorithm(unsigned size, std::vector<Key> seq, bool trace) {
  int max = seq[0];
  int iterador = 0;
    for (int i = 1; i < size; i++) {
        if (seq[i] > max) {
            max = seq[i];
        }
    }
    int exp = 1;
    while (max / exp > 0) {
        
        int output[size];
        int i, count[10] = {0};
        // Store count of occurrences in count[]
        for (i = 0; i < size; i++) {
            count[(seq[i] / exp) % 10]++;
        }
       
        // Change count[i] so that count[i] now contains actual position of this digit in output[]
        for (i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        // Build the output array by placing the numbers in sorted order
        for (i = size - 1; i >= 0; i--) {
            // output[count[(seq[i] / exp) % 10] - 1] is the number in seq[i] that is being placed in the output array
            output[count[(seq[i] / exp) % 10] - 1] = seq[i];
            // count is decremented because the same digit can appear more than once
            count[(seq[i] / exp) % 10]--;
        }
        // Copy the output array to seq[], so that seq[] now contains sorted numbers according to current digit
        for (i = 0; i < size; i++) {
            seq[i] = output[i];
        }
        exp *= 10;
        if (trace) iterador++;
        if(trace) {
            std::cout << "Iteration " << iterador << ":";
            for(int i = 0; i < size; i++) {
                std::cout << seq[i] << " ";
            }
            std::cout << std::endl;
        }
    }
    return seq;
}

/*  
    ShellSort.h
*/

template <typename Key>
std::vector<Key> ShellSort_algorithm(unsigned size, std::vector<Key> seq, bool trace) {
    std::cout << "Introducir el valor de alfa (entre 0 y 1): ";
    float gap;
    std::cin >> gap;
   int iterador = 0;
   //int contador = 0;
    while (gap > 0) {
        
        for (int i = gap; i < size; i++) {
            int temp = seq[i];
            int j = i;
            while (j >= gap && seq[j - gap] > temp) {
                seq[j] = seq[j - gap];
                j -= gap;
                //contador++;
                if (trace) iterador++;
                std::cout << "Iteration " << iterador << " : ";
                if(trace == true) {
                    for(int i = 0; i < size; i++) {
                        std::cout << seq[i] << " ";
                    }
                    std::cout << std::endl;
                 }
            }
            seq[j] = temp;
            //contador++;
        }
        gap /= 2;
        //contador++;
    }
    
            
       
    //std::cout << "Contador " << contador << std::endl;
    
    return seq;
}
