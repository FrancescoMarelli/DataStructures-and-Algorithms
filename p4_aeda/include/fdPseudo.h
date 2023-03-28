#ifndef FDPSEUDO_H
#define FDPSEUDO_H

#include <stdlib.h>

#include "dispersionFunction.h"

template <class Key>
class FdPseudo : public DispersionFunction<Key> {
    private:
    unsigned tableSize; // Number of positions in the table

    public:
    FdPseudo(const unsigned n) : tableSize(n) {}
    unsigned operator()(const Key& key) const;
};

template <class Key>
unsigned FdPseudo<Key>::operator()(const Key& key) const {
    srand(key);
    return rand() % tableSize;
}

#endif // FDPSEUDO_H