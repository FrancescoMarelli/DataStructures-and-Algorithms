#include <iostream>
#include <vector>

int main() {

    std::vector<int> seq = {10,89,9,4,15,67,72,81,49,101};
    int size = seq.size();
    int half = size/2;

    //insertion sort
    for(int i = 1; i <= half; ++i) {
        int x = seq[i];
        int j = i;
        while((j > 0) && (x < seq[j-1])) {
            seq[j] = seq[j-1];
            --j;
        }
        seq[j] = x; //actualizo el valor de elemento en la posicion j
    }

    //selection sort
    for(int i = half+1 ; i <= size; ++i){
        int min = i;
        for(int j = i+1; j <= size; ++j) {
            if(seq[j] < seq[min])
                min = j;
        }
        std::swap(seq[i], seq[min]);
    }

    //print
    std::cout << "El vector antes de mezclarlo queda asi: ";
    for(int i = 0; i < size; ++i)
        std::cout << seq[i] << " ";
    std::cout << std::endl;


    //merge
    std::vector<int> aux(size);
    int i = 0;
    int j = half+1;
    int k = 0;
    while((i <= half) && (j <= size)) {
        if(seq[i] < seq[j]) {
            aux[k] = seq[i];
            ++i;
        }
        else {
            aux[k] = seq[j];
            ++j;
        }
        ++k;
    }
    if(i > half) {
        while(j <= size) {
            aux[k] = seq[j];
            ++j;
            ++k;
        }
    }
    else {
        while(i <= half) {
            aux[k] = seq[i];
            ++i;
            ++k;
        }
    }
  
    //print
    std::cout << "El vector ordenado queda asi: ";
    for(int i = 0; i < size; ++i)
        std::cout << aux[i] << " ";
    std::cout << std::endl;


    return 0;
}


