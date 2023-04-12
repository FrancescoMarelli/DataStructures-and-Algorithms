#include <iostream>

#include "SortMethod.h"

int which_algorithm() {
    std::cout << "Which algorithm would you like to use?" << std::endl;
    std::cout << "1. Insertion Sort" << std::endl;
    std::cout << "2. Heap Sort" << std::endl;
    std::cout << "3. Merge Sort" << std::endl;
    std::cout << "4. Quit" << std::endl;
    int choice;
    std::cin >> choice;
    return choice;
}

int which_size() {
    std::cout << "Which is the size of the sequence to ordenate" << std::endl;
    int size;
    std::cin >> size;
    return size;
}

int exe_type() {
    std::cout << "Are you going to insert manually all the elements or do you want to generate a random sequence?" << std::endl;
    std::cout << "1. Manual" << std::endl;
    std::cout << "2. Random" << std::endl;
    int type;
    std::cin >> type;
    return type;
}

std::vector<long> gen_seq(int choice, int size) {
    std::vector<long> v;
    v.resize(size);
    if(choice == 1) {
        for(int i = 0; i < size; i++) {
            std::cout << "Insert the element number " << i << std::endl;
            std::cin >> v[i];
        }
    } else if(choice == 2) {        
        for(int i = 0; i < size; i++) 
            //generare numero random entre 1000 y 9999
            v[i] = rand() % 9000 + 1000;
    } else {
        std::cout << "Invalid choice" << std::endl;
    }
    return v;
}

void menu( int size, std::vector<long> v) {
    int choice;
    do {
        choice = which_algorithm();

        switch (choice)
        {
        case 1:{
            Insertion<long> insert(size, v);
            insert.Sort();
            insert.print();
            break;
            }
        case 2: {
            HeapSort<long> heap(size, v);
            heap.Sort();
            heap.print();
            break;
            }   
        case 3: {
            MergeSort<long> merge(size, v);
            merge.Sort();
            merge.print();
            break;
        }    
        case 4:
            break;
        
        default:
            break;
        }
    } while(choice != 4);

}