#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <string>

template <size_t Base> class BigInt; 
template <> class BigInt<2>;

class Number {

    public:
    //Arithmetic Operations
    virtual Number* add(Number* ) const = 0;
    virtual Number* sub(Number* ) const = 0;
    virtual Number* mul(Number* ) const = 0;
    virtual Number* div(Number* ) const = 0;
    virtual Number* mod(Number* ) const = 0;
    virtual Number* pow2(Number* ) const = 0;

        virtual ~Number() {}


    //Converson Operators
    virtual operator BigInt<2>() const = 0;
    virtual operator BigInt<8>() const = 0;
    virtual operator BigInt<10>() const = 0;
    virtual operator BigInt<16>() const = 0;

    virtual Number& operator=(const Number& ) = 0;

    //Flow Operations
    friend std::ostream& operator<<(std::ostream& os, const Number& c);
    virtual std::ostream& write(std::ostream& os) const = 0;
    friend std::istream& operator>>(std::istream& is, Number& c);
    virtual std::istream& read(std::istream& is)  = 0;

    virtual size_t get_base() const = 0;
    
    static Number* createNumber(size_t base, const std::string&);

    private:
    //size_t base;
    
};

#endif // NUMBER_H


