#ifndef BIGINTBADDIGIT_H
#define BIGINTBADDIGIT_H

#include <iostream>
#include "bigintexception.h"

class BigIntBadDigit : public BigIntException {
 public:
  BigIntBadDigit() : BigIntException("Invalid Digit") {}
};

#endif  // BIGINTBADDIGIT_H	

