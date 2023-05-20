#include <iostream>

class A{
    private:
    int a;

};

class B: protected A{
    
    int get() { return a;}
};


