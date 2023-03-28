#ifndef FDSUM_H
#define FDSUM_H

#include "dispersionFunction.h"

template <class Key>
class FdSum : public DispersionFunction<Key> {
    private:
    unsigned tableSize; // Number of positions in the table

    public:
    FdSum(const unsigned n) : tableSize(n) {}
    unsigned operator()(const Key& key) const;
};


template <class Key>
unsigned FdSum<Key>::operator()(const Key& key) const {
    Key d = 0;
    Key x = key;
    while (x > 0) {
        Key y = x % 10;
        d += y;
        x /= 10;
    }
    return d % tableSize;
}

#endif // FDSUM_H