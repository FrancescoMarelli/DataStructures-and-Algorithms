#ifndef FE_REDISPERSION_H
#define FE_REDISPERSION_H

#include "explorationFunction.h"
#include "fdPseudo.h"

template <class Key>
class FeRedispersion : public ExplorationFunction<Key> {

    private:
    DispersionFunction<Key>* df;

    public:
    FeRedispersion( DispersionFunction<Key>* d1): df(d1) { }

    unsigned operator()(const Key& key, const unsigned i) const {
        int value = 0;
        srand(key);
        for (int j = 0; j < i; ++j) {
            value = rand();
        }
        return value;
    }
};

#endif // FE_REDISPERSION_H