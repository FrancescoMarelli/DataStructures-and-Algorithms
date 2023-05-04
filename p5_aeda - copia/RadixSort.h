#include "SortMethod.h"

template <class Key>
class RadixSort : public SortMethod<Key> {
    private:
    unsigned size;
    std::vector<Key> seq;

    public:
    RadixSort(unsigned size, std::vector<Key>& seq) : size(size), seq(seq) {}
    void Sort() override;
    void print();

    
};

template <class Key>
void RadixSort<Key>::Sort() {
    int max = seq[0];
    for (int i = 1; i < size; i++) {
        if (seq[i] > max) {
            max = seq[i];
        }
    }
    int exp = 1;
    while (max / exp > 0) {
        int output[size];
        int i, count[10] = {0};
        for (i = 0; i < size; i++) {
            count[(seq[i] / exp) % 10]++;
        }
        for (i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (i = size - 1; i >= 0; i--) {
            output[count[(seq[i] / exp) % 10] - 1] = seq[i];
            count[(seq[i] / exp) % 10]--;
        }
        for (i = 0; i < size; i++) {
            seq[i] = output[i];
        }
        exp *= 10;
        std::cout << "Iteration: ";
        print();
    }
}

template <class Key>
void RadixSort<Key>::print() {
    for (int i = 0; i < size; i++) {
        std::cout << seq[i] << " ";
    }
    std::cout << std::endl;
}
