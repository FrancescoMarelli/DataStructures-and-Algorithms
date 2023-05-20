#ifndef DSC_ARRAY_H
#define DSC_ARRAY_H

#include "dsc_base.h"
#include <iostream>

template <class T, int N = 10>
class dsc_array : public dsc_base<T>{
    public:
    bool empty() const override;
    void insert(const T& item) override;
    T retrieve() const override;
    std::ostream& write(std::ostream& os) const;

    private:
    T array[N];
};

template <class T, int N>
bool dsc_array<T, N>::empty() const{
    return N == 0;
}

template <class T, int N>
void dsc_array<T,N>::insert(const T& item) {
    if(N == 0){
        int size = N;
        array[0] = item;
        size++;
   }else{
        T* aux = new T(item);
        int size = N;
        array[size] = *aux;
        size++;
        delete aux;
    }
}
template <class T, int N>
T dsc_array<T,N>::retrieve() const{
    T aux = array[N];
    return aux;
}

template <class T, int N>
 std::ostream& dsc_array<T,N>::write(std::ostream& os) const {
    for(int i = 0; i < N; i++)
        os << array[i] << std::endl;
    return os;
}

#endif // DSC_ARRAY_H

