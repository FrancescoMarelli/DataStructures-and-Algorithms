#ifndef BIGINTDIVISIONBYZERO_H
#define BIGINTDIVISIONBYZERO_H

#include <iostream>
#include "bigintexception.h"

class BigIntDivisionByZero : public BigIntException {
 public:
  BigIntDivisionByZero() : BigIntException("Division By Zero") {}
};

#endif  // BIGINTDIVISIONBYZERO_H