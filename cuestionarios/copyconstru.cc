#include <iostream>


class miclase{
    private:
    int a;
    int b;

    public:
    miclase(){ a = 0; b = 1;}
    miclase(int x, int y);
    void print() { std::cout << a << " " << b << std::endl; }
};

miclase::miclase(int x, int y): a(x), b(y){}

int main(){
    miclase a(10, 20);
    a.print();
    //miclase b(a);
    miclase c;
    a = c;
    a.print();

    miclase *p = new miclase(1, 2);
    *p = a;
    




    return 0;
}

