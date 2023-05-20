#include <iostream>

class base {
    public:
    int hola;
};
 
class derivada : public base {
    public:
    void f() { this->hola = 1; }

};

int main() {
    derivada d;
    d.f();
    std::cout << d.hola << std::endl;
    return 0;
}