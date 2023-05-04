#include "SortMethod.h"

template <class Key>
class RadixSort : public SortMethod<Key> {

    public:
    RadixSort(unsigned size, std::vector<Key>& seq, bool trace);
    void Sort() override;
    void print();

    
};

template <class Key>
RadixSort<Key>::RadixSort(unsigned size, std::vector<Key>& seq, bool trace) : 
    SortMethod<Key>(size, seq, trace) {}

template <class Key>
void RadixSort<Key>::Sort() {
    this->seq = RadixSort_algorithm(this->size, this->seq, this->trace);
  
}

template <class Key>
void RadixSort<Key>::print() {
    for (int i = 0; i < this-> size; i++) {
        std::cout << this->seq[i] << " ";
    }
    std::cout << std::endl;
}
