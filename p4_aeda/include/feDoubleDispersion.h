#ifndef FE_DOUBLE_DISPERSION_H
#define FE_DOUBLE_DISPERSION_H

#include "explorationFunction.h"
#include "dispersionFunction.h"

template <class Key>
class FeDoubleDispersion : public ExplorationFunction<Key> {

    private:
    DispersionFunction<Key>* df;

    public:
    FeDoubleDispersion( DispersionFunction<Key>* d1): df(d1) {}  
    
    unsigned operator()(const Key& key, const unsigned i) const {
        return i * df->operator()(key);
    }
};



#endif // FE_DOUBLE_DISPERSION_H