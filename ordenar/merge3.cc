#include <iostream>
#include <vector>

void merge(std::vector<int>& seq, int low, int mid1, int mid2, int high) {
    std::vector<int> aux(high - low + 1);

    int i = low, j = mid1 + 1, k = mid2 + 1, l = 0; // i, j, k, l son índices

    // Mientras haya elementos en las tres partes
    while (i <= mid1 && j <= mid2 && k <= high) {
        if (seq[i] < seq[j]) {
            if (seq[i] < seq[k]) {
                aux[l] = seq[i];
                ++i;
            } else {
                aux[l] = seq[k];
                ++k;
            }
        } else {
            if (seq[j] < seq[k]) {
                aux[l] = seq[j];
                ++j;
            } else {
                aux[l] = seq[k];
                ++k;
            }
        }
        ++l;
    }

    // Mientras haya elementos en las dos primeras partes
    // (la tercera está vacía)
    // inserto el menor de los dos en aux
    while (i <= mid1 && j <= mid2) {
        if (seq[i] < seq[j]) {
            aux[l] = seq[i];
            ++i;
        } else {
            aux[l] = seq[j];
            ++j;
        }
        ++l;
    }

    // Mientras haya elementos en la primera y la tercera partes
    // (la segunda está vacía)
    // inserto el menor de los dos en aux
    while (i <= mid1 && k <= high) {
        if (seq[i] < seq[k]) {
            aux[l] = seq[i];
            ++i;
        } else {
            aux[l] = seq[k];
            ++k;
        }
        ++l;
    }

    //Mientras haya elementos en la segunda y la tercera partes
    // (la primera está vacía)
    // inserto el menor de los dos en aux
    while (j <= mid2 && k <= high) {
        if (seq[j] < seq[k]) {
            aux[l] = seq[j];
            ++j;
        } else {
            aux[l] = seq[k];
            ++k;
        }
        ++l;
    }

    //copia los elementos restantes de la primera parte
    while (i <= mid1) {
        aux[l] = seq[i];
        ++i;
        ++l;
    }

    //copia los elementos restantes de la segunda parte
    while (j <= mid2) {
        aux[l] = seq[j];
        ++j;
        ++l;
    }
    
    //copia los elementos restantes de la tercera parte
    while (k <= high) {
        aux[l] = seq[k];
        ++k;
        ++l;
    }

    for (l = 0; l < aux.size(); ++l) {
        seq[low + l] = aux[l];
    }
}

void mergeSort(std::vector<int>& seq, int low, int high) {
    if (low < high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = low + 2 * (high - low) / 3;

        mergeSort(seq, low, mid1);
        mergeSort(seq, mid1 + 1, mid2);
        mergeSort(seq, mid2 + 1, high);

        merge(seq, low, mid1, mid2, high);
    }
}

int main() {
    std::vector<int> seq = {10, 89, 9, 4, 15, 67, 72, 81, 49, 101};
    int size = seq.size();

    mergeSort(seq, 0, size - 1);

    std::cout << "El vector ordenado queda así: ";
    for (int i = 0; i < size; ++i)
        std::cout << seq[i] << " ";
    std::cout << std::endl;

    return 0;
}
