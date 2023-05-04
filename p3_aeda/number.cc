#ifndef NUMBER_CC
#define NUMBER_CC

#include "number.h"
#include "bigint.h"


std::ostream& operator<<(std::ostream& os, const Number& c) {
    return c.write(os);
}

std::istream& operator>>(std::istream& is, Number& c) {
    return c.read(is);
}

Number* Number::createNumber(size_t base, const std::string& str) {
    switch (base) {
        case 2: 
            return new BigInt<2>(str);
        case 8:
            return new BigInt<8>(str);
        case 10:
            return new BigInt<10>(str);
        case 16: 
            return new BigInt<16>(str);
        default:
        throw BigIntBaseNotImplemented();
    }
}



#endif // _NUMBER_CC