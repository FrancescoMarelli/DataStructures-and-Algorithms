#include <iostream>

//el parametro es un puntero a un entero constante, no puedo cambiarlo
void f(const int * param)   {
    *param = 10; //read-only location
    std::cout << *param << std::endl;
}

int main() {
    int arg = 1;
    f(&arg);
}