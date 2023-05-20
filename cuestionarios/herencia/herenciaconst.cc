#include <iostream>

class Base {
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
    int get() const { return y; }
};

int main() {
    //ptr es un puntero a un objeto de tipo Base que apunta a un objeto de tipo Derivada constante
     const Base *const  ptr  = new Derivada();
    std::cout << ptr->get() << std::endl; 
}