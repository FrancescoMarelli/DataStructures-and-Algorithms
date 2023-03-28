#ifndef FE_SQUARED_H
#define FE_SQUARED_H

#include "explorationFunction.h"

template <class Key>
class FeSquared : public ExplorationFunction<Key> {

    public:
    unsigned operator()(const Key& key, const unsigned i) const {
        return i*i;
    }
};

#endif // FE_SQUARED_H