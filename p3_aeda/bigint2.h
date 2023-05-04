#ifndef BIGINT2_H
#define BIGINT2_H

#include <vector>
#include "bigint.h"


template <>
class BigInt<2> : public Number {
 public:
  BigInt(long l_op = 0);
  BigInt(const BigInt<2> &other);
  BigInt(std::vector<bool> digits);
  BigInt(const std::vector<char> &, const int & );
  BigInt(const std::string l_op);

  ~BigInt() override {}

  // Assignment
  BigInt operator=(const BigInt<2> &other);
  Number& operator=(const Number&) override;

  // Conversion
  template <size_t base>
   BigInt<base> ConvBase() const;

  // Getters and Setters
  std::vector<bool> GetDigits() const;
  BigInt<2> SetDigits(std::vector<bool> digits);
  bool operator[](size_t) const;
  size_t size() const;
  size_t get_base() const { return 2;};

  // Modifications or checks
  bool IsZero() const;
  BigInt<2> Abs() const;
  std::string to_string() const;

  friend bool operator==(const BigInt<2> &, const BigInt<2> &);
  // Comparison operators
  bool operator!=(const BigInt<2> &other) const;
  friend bool operator>(const BigInt<2> &, const BigInt<2> &);
  bool operator>=(const BigInt<2> &other) const;
  friend bool operator<(const BigInt<2> &, const BigInt<2> &);
  bool operator<=(const BigInt<2> &other) const;

  // Increment/Decrement
  BigInt<2> &operator++();    // pre-increment
  BigInt<2> operator++(int);  // post-increment
  BigInt<2> &operator--();    // pre-decrement
  BigInt<2> operator--(int);  // post-decrement

  // arithmetic operators
  friend BigInt<2> operator+(const BigInt<2> &first, const BigInt<2> &other);
  BigInt<2> sum_overflow(const BigInt<2> &first, const BigInt<2> &other) const; //*
  BigInt<2> operator-() const;
  BigInt<2> operator-(const BigInt<2> &other) const;
  BigInt<2> operator*(const BigInt<2> &other) const;
  friend BigInt<2> operator/(const BigInt<2> &first, const BigInt<2> &other);
  BigInt<2> operator%(const BigInt<2> &other) const;

  friend BigInt<2> pow(const BigInt<2> &first, const BigInt<2> &other);
  BigInt<2> operator^(const BigInt<2> &other) const;
  BigInt<2> square() const;

  // Displacement operators
  void operator<<(size_t n);
  void operator>>(size_t n);

  BigInt<2> FillSign(size_t n) const;
  BigInt<2> TwoComplement() const;

  // Input/Output
  friend std::ostream &operator<<(std::ostream &os, const BigInt<2> &l_op);
   std::ostream& write(std::ostream&) const override;
   std::istream& read(std::istream&) override;
   friend std::istream &operator>>(std::istream &is, BigInt<2> &l_op);
/*
  Práctica 3
*/ 
 Number* add(Number* ) const override;
 Number* sub(Number* ) const override;
 Number* mul(Number* ) const override;
 Number* div(Number* ) const override; 
 Number* mod(Number* ) const override;
 Number* pow2(Number* ) const override;

   operator BigInt<2>() const override;
   operator BigInt<8>() const override;
   operator BigInt<10>() const  override;
   operator BigInt<16>() const override;


 private:
  void operator<<(BigInt<2> &other);
  void operator>>(BigInt<2> &other);

  std::vector<bool> digits;
};

#include "bigint2.cc"

#endif  // BIGINT2_H