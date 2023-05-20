#include <iostream>

class A {
    private:
        int _a;
    public:
    A(int x = 2): _a(2*x+1) {}
    int f(int x) const { return g(x*x); }
    virtual int g(int x) const { return x % _a; }
};

