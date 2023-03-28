#ifndef EXPLORATIONFUNCTION_H
#define EXPLORATIONFUNCTION_H

#include <iostream>

template <class Key>
class ExplorationFunction {
    public:
    virtual unsigned operator()(const Key& key, const unsigned i) const = 0;
};

#include "feLineal.h"
#include "feSquared.h"
#include "feRedispersion.h"
#include "feDoubleDispersion.h"

#endif // EXPLORATIONFUNCTION_H


