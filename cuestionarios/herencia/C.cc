#include "B.cc"

class C : public B {
    private: 
    int _c;

    public:
    C(int x=3): _c(x*x){}
    virtual int g(int x = 2) const {return x/_c;}
};