#ifndef _SORTMETHOD_H_
#define _SORTMETHOD_H_

#include "Ord_algorithms.cc"

#include <iostream> 
#include <vector>


template <class Key>
class SortMethod {
    protected:
    unsigned size;
    std::vector<Key> seq;
    bool trace;
    
    public: 
    SortMethod(unsigned size, std::vector<Key>& seq, bool trace) : 
                size(size), 
                seq(seq), 
                trace(trace) {}
                
    virtual void Sort() = 0;
    virtual void print() = 0;
};


#include "Insertion.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "ShellSort.h"



#endif 