#pragma once

#include <iostream>
#include <vector>


namespace merging {
    void Merge(std::vector<int>& seq, int ini, int cen, int fin);
    void MSort(std::vector<int>& seq, int ini, int fin);
    void Ordenar(std::vector<int>& sec);
    void select(std::vector<int>& sec);
    void insert(std::vector<int>& sec);
}   // namespace merging

    void merging::Merge(std::vector<int>& seq, int ini, int cen, int fin) {
        int i = cen; //recorre primera mitad de lista (ini a cen)
        int j = cen + 1; //recorre segunda mitad de lista (cen + 1 a fin)
        int k = 0; //mantiene indice actual en la lista auxiliar dnd se combinan elementos 
        std::vector<int> aux(seq.size()); //lista auxiliar para combinar elementos

        //combinar las dos mitades en una lista auxiliar
        //elemento i primera mitad con elemento j segunda mitad
        // si i < j, se copia i en aux y se incrementa i
        // si j < i, se copia j en aux y se incrementa j
        //Hasta que se recorren ambas sublista

        while((i >= 0) && (j <= seq.size() - 1)) {
            if(seq[i] < seq[j]) {
                aux[k] = seq[j];
                j++;
            } else {
                aux[k] = seq[i];
                i--;
            }
            k++;
        }
        // copiar el resto de la primera mitad en la lista auxiliar
            
            if(i < 0) {
                while(j <= seq.size() - 1) {
                aux[k] = seq[j];
                j++;
                k++;
                } 
            } else {
        // copiar el resto de la segunda mitad en la lista auxiliar
            while(i >= 0) {
                aux[k] = seq[i];
                i--;
                k++;
            }
            }
        //copiar la lista auxiliar en la lista original
        for (i = 0; i <= seq.size(); i++) {
            seq[i] = aux[i];
        }
    }

    void merging::MSort(std::vector<int>& seq, int ini, int fin) {
        int cen;
        if (ini < fin) {
            cen = (ini + fin) / 2;
            MSort(seq, ini, cen); //divido
            MSort(seq, cen + 1, fin); //divido
            merging::Merge(seq, ini, cen, fin); // mezclo
        }
    }


    void merging::Ordenar(std::vector<int>& sec) {
        merging::select(sec);
        merging::insert(sec);
       merging::Merge(sec, 0, sec.size() / 2, sec.size() - 1);
    }

    void merging::select(std::vector<int>& sec) {
        int min;
        int half = sec.size() / 2;
        for(int i = 0; i < half; i++) {
            min = i;
            for(int j = i+1; j <= sec.size(); j++) 
                if(sec[j] < sec[min]) 
                    min = j;
            std::swap(sec[i], sec[min]);   
        }
    }

    void merging::insert(std::vector<int>& sec) {
        //con centinela 
        for(int i = 1; i < sec.size(); i++) {
        int x, j;
        x = sec[i];
        j = i;
            while(x < sec[j - 1]) {
                sec[j] = sec[j - 1 ];
                j--;
            }
            sec[j] = x;
        }
    }