#include <iostream>

class Base{
    private:
    int x;
    public:
    Base() { x = 5;}
    virtual int get() const { return 0; }
    virtual int get(){ return x; }
};

class Derivada : public Base {
    protected:
    int y;
    public:
    Derivada() { y = 10;}
    int get() const { return y;}
    void print() const { std::cout << "Derivada" << std::endl; }
};

int main() {
    //ptr es un puntero  constante  a clase base
     Base * const  ptr  = new Derivada(); // coge la x porque es const y no puede cambiar de tipo  
    std::cout << ptr->get() << std::endl; //imprime 10
}