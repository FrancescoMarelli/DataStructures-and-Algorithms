#include <iostream>

void f(int &param) {
    param = 10;
}

int main() {
    int arg = 1;
    f(&arg); 
std::cout << arg << std::endl;
}