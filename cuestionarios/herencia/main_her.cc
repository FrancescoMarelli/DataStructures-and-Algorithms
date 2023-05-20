#include <iostream>

#include "C.cc"

int main(){
    A a(2);
    B b;
    C c(2);

    std::cout << a.f(3) << std::endl;
    std::cout << b.f(3) << std::endl;
    std::cout << c.f(3) << std::endl;
    return 0;
}