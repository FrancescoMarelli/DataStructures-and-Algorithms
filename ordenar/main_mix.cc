#include <iostream>
#include <vector>

#include "mix.cc"
#include "merge.cc"

int main() {

    std::vector<int> seq = {212, 237, 342, 132, 368, 347, 174, 672, 230, 154};
    merging::MSort(seq, 0, seq.size() - 1);
    std::cout << "MergeSort: "<< std::endl;

    for (int i = 0; i < seq.size(); i++) 
        std::cout << seq[i] << " ";
    std::cout << std::endl;

    std::cout << "MixSort: "<< std::endl;
    merging::Ordenar(seq);
    for (int i = 0; i < seq.size(); i++) 
        std::cout << seq[i] << " ";
    std::cout << std::endl;

return 0;
}
