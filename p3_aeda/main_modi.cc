#include <iostream>
#include "bigint.h"
int main() {
    //Mostrar la cantidad de bytes de un numero en complemento a 2 considerando vectores

    BigInt<2> c(1011101101);
    BigInt<8> b(1011101101);  
    BigInt<10> a(1222323345);
    
    std::vector<bool> v = c.GetDigits();
    std::vector<char> v2 = b.GetDigits();
    std::vector<char> v3 = a.GetDigits();

    std::cout << "Caso BigInt<2> " << std::endl;
    std::cout << "El tamaño del vector v (<bool>) es: ";
    std::cout << sizeof(v) << std::endl;
    std::cout << "tamaño del primer elemento de v: " << sizeof(v[0]) << std::endl;
    std::cout << "sizeof GetDigits: " << sizeof(c.GetDigits()) << std::endl;
    std::cout << v[0]*v.size() << std::endl;
    std::cout << std::endl;
    std::cout << "Caso BigInt<8> " << std::endl;
    std::cout << "El tamaño del vector v2 (<char>) es: ";
    std::cout << sizeof(v2) << std::endl;
    std::cout << "tamaño del primer elemento de v2: " << sizeof(v2[0]) << std::endl;
    std::cout << "sizeof GetDigits: " << sizeof(b.GetDigits()) << std::endl;
    std::cout << v2[0]*b.size() << std::endl;
    std::cout << std::endl;
    std::cout << "Caso BigInt<10> " << std::endl;
    std::cout << "El tamaño del vector v3 (<char>) es: ";
    std::cout << sizeof(v3) << std::endl;
    std::cout << "tamaño del primer elemento de v3: " << sizeof(v3[0]) << std::endl;
    std::cout << "sizeof GetDigits: " << sizeof(a.GetDigits()) << std::endl;
    std::cout << v3[0]*a.size() << std::endl;

    return 0;
}