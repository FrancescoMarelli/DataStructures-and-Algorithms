#include <iostream>

template <class T, int N>
class mivector{
    private:
    T v[N];
    public:
    mivector(int n); 
};

template <class T, int N>
mivector<T,N>::mivector(int n){
    v = new T[n]; // asi puedo 
}

template <class T, int N>
mivector<T,N>::mivector(int n = N){ // asi no puedo 
    v = new T[n]; 
}
