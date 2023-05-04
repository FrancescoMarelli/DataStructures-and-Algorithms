#include "SortMethod.h"

template <class Key>
class ShellSort : public SortMethod<Key> {
   
    public:
    ShellSort(unsigned size, std::vector<Key>& seq, bool trace);
    void Sort() override;
    void print();
};

template <class Key>
ShellSort<Key>::ShellSort(unsigned size, std::vector<Key>& seq, bool trace) :
    SortMethod<Key>(size, seq, trace) {}

template <class Key>
void ShellSort<Key>::Sort() {
    this->seq = ShellSort_algorithm(this->size, this->seq, this->trace);
}

template <class Key>
void ShellSort<Key>::print() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->seq[i] << " ";
    }
    std::cout << std::endl;
}