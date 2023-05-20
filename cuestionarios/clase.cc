#include <iostream>

class clase {
    public:
    static void f()  { std::cout << "const" << std::endl; }
    void g() { f(); }

};

int main() {
    clase c;
    clase::f();
  

    return 0;
}