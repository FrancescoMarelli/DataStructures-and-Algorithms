#ifndef DISPERSIONFUNCTION_H
#define DISPERSIONFUNCTION_H

#include <iostream>

template <class Key>
class DispersionFunction {
    
    public:
    virtual unsigned operator()(const Key& key) const = 0;
};

#include "fdPseudo.h"
#include "fdSum.h"
#include "fdModule.h"


#endif // DISPERSIONFUNCTION_H