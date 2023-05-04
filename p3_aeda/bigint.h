#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unistd.h>

#include "number.h"
#include "bigintexception.h"

/*

    Header file for the BigInt class

*/
template <size_t Base>
class BigInt : public Number {
 public:
  // Constructor
  BigInt(long n = 0);
  BigInt(const std::string &);
  BigInt(const std::vector<char> &,const int & );
  BigInt(const char *);
  BigInt(const BigInt<Base> &);
  ~BigInt() override {}


  // Assignment
  Number& operator=(const Number&) override; 
  BigInt<Base> &operator=(const BigInt<Base> &);



  // Input/Output
  template <size_t Base_t>
  friend std::ostream &operator<<(std::ostream &, const BigInt<Base_t> &);
  template <size_t Base_t>
  friend std::istream& operator>>(std::istream&, BigInt<Base_t>&);
  //p3
  std::ostream& write(std::ostream&) const override;
  std::istream& read(std::istream&) override;

  // Getters and Setters
  BigInt<Base> SetDigits(std::vector<char>);
  BigInt<Base> SetSign(int);
  int sign() const;
  size_t size() const;
  char operator[](size_t) const;
  size_t get_base() const ;
  std::vector<char> GetDigits() const;


  //Auxilliary methods
  BigInt<Base> Abs() const;
  BigInt<Base> FillZeros(unsigned) const ;
  bool IsZero() const;
  std::string to_string() const;


  // Comparison
  template <size_t Base_t>
  friend bool operator==(const BigInt<Base> &, const BigInt<Base> &);
  bool operator!=(const BigInt<Base> &) const;
  template <size_t Base_t>
  friend bool operator>(const BigInt<Base> &, const BigInt<Base> &);
  bool operator>=(const BigInt<Base> &) const;
  template <size_t Base_t>
  friend bool operator<(const BigInt<Base> &, const BigInt<Base> &);
  bool operator<=(const BigInt<Base> &) const;

  // Increment/Decrement
  BigInt<Base> &operator++();    // pre-increment
  BigInt<Base> operator++(int);  // post-increment

  BigInt<Base> &operator--();    // pre-decrement
  BigInt<Base> operator--(int);  // post-decrement

  // Arithmetic operators
  template <size_t Base_t>
  friend BigInt<Base_t> operator+(const BigInt<Base_t> &, const BigInt<Base_t> &);
  BigInt<Base> operator-(const BigInt<Base> &) const;
  BigInt<Base> operator-() const;
  BigInt<Base> operator*(const BigInt<Base> &) const;
  template <size_t Base_t>
  friend BigInt<Base> operator/(const BigInt<Base> &, const BigInt<Base> &);
  BigInt<Base> operator%(const BigInt<Base> &) const;
  template <size_t Base_t>
  friend BigInt<Base> pow(const BigInt<Base> &, const BigInt<Base> &);
  BigInt<Base> operator^(const BigInt<Base> &) const;


  // Herency methods
  Number* add(Number* ) const override;
  Number* sub(Number* ) const override;
  Number* mul(Number* ) const override;
  Number* div(Number* ) const override;
  Number* mod(Number* ) const override;
  Number* pow2(Number* ) const override;
   
   operator BigInt<2>() const override;
   operator BigInt<8>() const override;
   operator BigInt<10>() const override;
   operator BigInt<16>() const override;

 private:
  std::vector<char> digits_;
  int sign_;  // 1: positive, -1: negative
};

#include "bigint2.h"
#include "bigint.cc"

#endif  // BIGINT_H