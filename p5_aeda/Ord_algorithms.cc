#include <iostream>

#include "SortMethod.h"




/*
    SelectionSort
*/

template <typename Key>
std::vector<Key> SelectionSort(std::vector<Key>& seq, unsigned size, bool trace, int& count) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        if(trace == true) std::cout << "Iteration: " << i <<": ";
        for (int j = i + 1; j < size; j++) {
            if (seq[j] < seq[min]) {
                min = j;
            }
            count++;
        }
        std::swap(seq[min], seq[i]);

        //print
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
    *  InsertionSort
*/
template <typename Key>
std::vector<Key> InsertionSort(std::vector<Key>& seq, unsigned size, bool trace, int& count) {
    for (int i = 1; i < size; i++) {
        int x = seq[i];
        int j = i;
        if(trace == true) std::cout << "Iteration: " << i <<": ";
        while (seq[j-1] > x && j > 0) {
            seq[j] = seq[j-1];
            j--;
            count++;
        }
        seq[j] = x;


        //print
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
std::vector<Key> merge(std::vector<Key>& sec,
                     typename std::vector<Key>::iterator ini, 
                     typename std::vector<Key>::iterator cen, 
                     typename std::vector<Key>::iterator fin, 
                     bool trace) {

    typename std::vector<Key>::iterator i = ini;
    typename std::vector<Key>::iterator j = cen + 1;
    typename std::vector<Key>::iterator k = ini;
    std::vector<Key> aux;
    
    while((i <= cen) && (j <= fin)) {
        if(*i < *j) {
            aux.push_back(*i);
            i++;
        } else {
            aux.push_back(*j);
            j++;
        }
        k++;
    }

    while(i <= cen) {
            aux.push_back(*i);
            i++;
            k++;
    }
    while(j <= fin) {
            aux.push_back(*j);
           j++;
           k++;
    }

    std::copy(aux.begin(), aux.end(), sec.begin() + (ini - sec.begin()));
    if(trace) {
        for (int i = 0; i < sec.size(); i++) {
            std::cout << sec[i] << " ";
        }
        std::cout << std::endl;
    }
    return sec;
}

template <typename Key>
std::vector<Key> MergeSort_algorithm(unsigned size, std::vector<Key>& seq,  typename std::vector<Key>::iterator ini, typename std::vector<Key>::iterator fin, bool trace) {
    if (ini < fin) {
        typename std::vector<Key>::iterator middle =  ini + (fin - ini) / 2;
        MergeSort_algorithm(size, seq, ini, middle, trace);
        MergeSort_algorithm(size, seq, middle + 1, fin, trace);
        seq = merge(seq, ini, middle, fin, trace);
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
    while (gap > 1) {
            std::cout << "Delta = " << gap << std::endl;
        for (int i = gap; i < size; i++) {
            int temp = seq[i];
            int j = i;
            while (j >= gap && seq[j - gap] > temp) {
                seq[j] = seq[j - gap];
                j -= gap;
                seq[j] = temp;
                // print
                    if(trace) iterador++;
                    std::cout << "Iteration " << iterador-1 << " : ";
                    for (int k = 0; k < size; k++) 
                        std::cout << seq[k] << " ";
                    std::cout << std::endl;
            }
            
        }
        gap /= 2;
    }

    return seq;
}


/*
    QuickSort.h
*/
template <typename Key> 
std::vector<Key> QuickSort_alg(std::vector<Key>& sec, int ini, int fin, bool trace) {
    int i = ini;
    int j = fin;
    Key pivot = sec[(i + j) / 2];
    std::cout << "Pivot: " << pivot << std::endl;
    while (i <= j) {
        while (sec[i] < pivot)  i++;
        while (sec[j] > pivot) j--;
        if (i <= j) {
            std::swap(sec[i], sec[j]);
            i++;
            j--;
        }

        if(sec[i] != sec[j]) {
                for (int i = 0; i < sec.size(); i++) 
                    std::cout << sec[i] << " ";
                std::cout << std::endl;
        }
    }

    if (ini < j)  QuickSort_alg(sec, ini, j, trace);
    if (i < fin)  QuickSort_alg(sec, i, fin, trace);
   
    return sec;
}

