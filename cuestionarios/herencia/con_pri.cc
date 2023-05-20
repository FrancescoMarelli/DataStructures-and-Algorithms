#include <iostream>


class miclase {
    public:
    static miclase* getinstance() {
        miclase* instance = new miclase();
        return instance;
    }

    virtual void display() {
        std::cout << x << std::endl;
    }

    int x;
    miclase(){  x = 5;}

    friend class derivada;
};

class derivada : public miclase {

    public:
    derivada() { miclase();}

    void display() {
        std::cout << "Hola"<< std::endl;
    } 
};

int main(){

    miclase* ptr = new derivada;
    ptr->display();

    return 0;
}