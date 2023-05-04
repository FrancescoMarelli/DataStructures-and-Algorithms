#include "SortMethod.h"

template <class Key>
class ShellSort : public SortMethod<Key> {
    private:
    unsigned size;
    std::vector<Key> seq;

    public:
    ShellSort(unsigned size, std::vector<Key>& seq) : size(size), seq(seq) {}
    void Sort() override;
    void print();
};

template <class Key>
void ShellSort<Key>::Sort() {
    int gap = size / 2;
    while (gap > 0) {
        for (int i = gap; i < size; i++) {
            int temp = seq[i];
            int j = i;
            while (j >= gap && seq[j - gap] > temp) {
                seq[j] = seq[j - gap];
                j -= gap;
            }
            seq[j] = temp;
        }
        gap /= 2;
        std::cout << "Iteration: ";
        print();
    }
}

template <class Key>
void ShellSort<Key>::print() {
    for (int i = 0; i < size; i++) {
        std::cout << seq[i] << " ";
    }
    std::cout << std::endl;
}