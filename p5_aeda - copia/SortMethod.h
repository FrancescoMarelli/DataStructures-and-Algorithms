#ifndef _SORTMETHOD_H_
#define _SORTMETHOD_H_

#include <iostream> 
#include <vector>


template <class Key>
class SortMethod {
    
    public: 
    virtual void Sort() = 0;
    virtual void print() = 0;
};


#include "Insertion.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "ShellSort.h"

#endif 