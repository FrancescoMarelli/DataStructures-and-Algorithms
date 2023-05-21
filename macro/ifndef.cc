#include <iostream>
#define TRAZA(t) std::cout << (#t) << "=" << (t) << std::endl;

int main() {
    int a = 1;
    TRAZA(a)

    return 0;
}