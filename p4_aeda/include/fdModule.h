#include "dispersionFunction.h"

template <class Key>
class FdModule : public DispersionFunction<Key> {
    private:
    size_t tableSize; // Number of positions in the table

    public:
    FdModule(const unsigned n) : tableSize(n) {}
    unsigned operator()(const Key& key) const;
};

template <class Key>
unsigned FdModule<Key>::operator()(const Key& key) const {
    return key % tableSize;
}