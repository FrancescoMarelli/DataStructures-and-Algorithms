#include <iostream>

#include "A.cc"

class B : public A {
    private:
        int _b;
        
    public:
       B(int x = 5) : A(x), _b(x+1) {}
       virtual int f(int x) const {return g(x + _b); }
};