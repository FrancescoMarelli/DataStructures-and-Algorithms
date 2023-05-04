#ifndef BIGINTEXCEPTION_H
#define BIGINTEXCEPTION_H

#include <iostream>

class BigIntException : public std::exception {
 public:
  BigIntException(const std::string& message) : message_(message) {}
  const char* what() const noexcept override { return message_.c_str(); }

 private:
  std::string message_;

};
#include "bigintbaddigit.h"
#include "bigintbasenotimplemented.h"
#include "bigintdivisionbyzero.h"

#endif  // BIGINTEXCEPTION_H