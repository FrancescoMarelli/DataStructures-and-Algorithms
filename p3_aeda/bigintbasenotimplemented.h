#ifndef BIGINTBASENOTIMPLEMENTED_H
#define BIGINTBASENOTIMPLEMENTED_H

#include "bigintexception.h"

class BigIntBaseNotImplemented : public BigIntException {
 public:
  BigIntBaseNotImplemented() : BigIntException("Invalid Base") {}
};

#endif  // BIGINTBASENOTIMPLEMENTED_H