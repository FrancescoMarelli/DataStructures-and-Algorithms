#ifndef BIGINT2_CC
#define BIGINT2_CC

#include "bigint2.h"


/*
  Implementación metodos de la clase BigInt2
*/

//Long constructor
BigInt<2>::BigInt(long l_op) {
  bool sign = false;
  if (l_op < 0) {
    sign = true;
    l_op = -l_op;
  }
  // twice because we need the first digit for the sign
  if (l_op == 0) {
    digits.push_back(0);
    digits.push_back(0);
  }

  // Binary Division 
  while (l_op > 0) {
    int dig = l_op % 2;
   
    digits.push_back(dig);
    l_op /= 2;
  }
  if(digits.size() == 0)
  digits.push_back(0);
  
  if (sign) {
    *this = TwoComplement();
    }
}

BigInt<2>::BigInt(std::vector<bool> digits) { this->digits = digits; }

BigInt<2>::BigInt(const BigInt<2> &l_op) { digits = l_op.digits; }

BigInt<2>::BigInt(std::string l_op) {


  if (l_op.size() == 0) {
    digits.push_back(0);
    digits.push_back(0);
  }

  if(l_op[0] == '1' || l_op[0] == '-'){
    l_op.erase(0,1);
    *this = BigInt<2>(l_op);
    *this = TwoComplement();
  }
  // if size is 1, error because the number must be 00 or 01
  if (l_op.size() > 1) {
    for (int i = l_op.size() - 1; i >= 0; i--) {
      digits.push_back(l_op[i] - '0');
    }
  }
  else {
    digits.push_back(0);
    digits.push_back(0);
  }
  
  for(int i = 0; i < digits.size(); i++){
    if(digits[i] != 0 && digits[i] != 1){
      throw BigIntBadDigit();
    } 
  }
}


//Contructor to convert back to Base
BigInt<2>::BigInt(const std::vector<char> &digits_aux,const int &sign ){

}

bool BigInt<2>::operator[](size_t n) const { return digits[n]; }

size_t BigInt<2>::size() const { return digits.size(); }


BigInt<2> BigInt<2>::operator=(const BigInt<2> &other) {
  digits = other.digits;
  return *this;
}

std::string BigInt<2>::to_string() const {
  std::string l_op;
  for (int i = digits.size() - 1; i >= 0; i--) {
    l_op += digits[i] + '0';
  }
  return l_op;
}

std::vector<bool> BigInt<2>::GetDigits() const { return digits; }

BigInt<2> BigInt<2>::SetDigits(std::vector<bool> digits) {
  this->digits = digits;
  return *this;
}

bool operator==(const BigInt<2> &first, const BigInt<2> &other) {
  // If signs are different return false
  
  BigInt<2> l_op;
  BigInt<2> r_op;
  // We need to control 0001 = 01 if size is different fill with sign
  if (first.size() < other.digits.size()) {
    l_op = first.FillSign(other.digits.size() - first.size());
    r_op = other;
  } else if (first.size() > other.digits.size()) {
    l_op = first;
    r_op = other.FillSign(first.size() - other.digits.size());
  }else{
    l_op = first;
    r_op = other;
  }
  for (size_t i = 0; i < l_op.digits.size(); i++) {
    if (l_op.digits[i] != r_op.digits[i]) {
      return false;
    }
  }
  return true;
}

bool BigInt<2>::operator!=(const BigInt<2> &other) const {
  return !(*this == other);
}

bool operator>(const BigInt<2> &first, const BigInt<2> &other) {
  // We need to control 0001 = 01 if size is different fill with zeros
  // Different sign case
  if (first[first.size() - 1] < other.digits[other.digits.size() - 1]) {
    return true;
  } else if (first[first.size() - 1] > other.digits[other.digits.size() - 1]) {
    return false;
  }
  // Same sign case
  bool sign = first[first.size() - 1];
  BigInt<2> l_op;
  BigInt<2> r_op;
  if (sign) {
    l_op = first.Abs();
    r_op = other.Abs();
  } else {
    l_op = first;
    r_op = other;
  }
  if (l_op.digits.size() > r_op.digits.size()) {
    r_op =
        r_op.FillSign(l_op.digits.size() - r_op.digits.size());
  } else if (l_op.digits.size() < r_op.digits.size()) {
    l_op =
        l_op.FillSign(r_op.digits.size() - l_op.digits.size());
  }
  for (long long i = l_op.digits.size() - 1; i >= 0; i--) {
    if (l_op.digits[i] > r_op.digits[i]) {
      return sign ? false : true;
    } else if (l_op.digits[i] < r_op.digits[i]) {
      return sign ? true : false;
    }
  }
  return false;
}

bool operator<(const BigInt<2> &first, const BigInt<2> &other) {
  return !(first > other || first == other);
}

bool BigInt<2>::operator>=(const BigInt<2> &other) const {
  return !(*this < other);
}

bool BigInt<2>::operator<=(const BigInt<2> &other) const {
  return !(*this > other);
}

void BigInt<2>::operator<<(size_t n) {
  std::vector<bool> aux;
  aux.insert(aux.begin(), digits.begin(), digits.end() - n);
  aux.insert(aux.end(), n, digits[digits.size() - 1]);
  digits = aux;
}

void BigInt<2>::operator>>(size_t n) {
  if (n > digits.size()) {
    digits.clear();
    digits.push_back(0);
    return;
  }
  std::vector<bool> aux;
  aux.insert(aux.begin(), n, digits[digits.size() - 1]);
  aux.insert(aux.end(), digits.begin() + n, digits.end());
  digits = aux;
}

BigInt<2> operator+(const BigInt<2> &first, const BigInt<2> &other) {
  std::vector<bool> l_op = first.digits;
  std::vector<bool> r_op = other.digits;
  bool carry = false;
  bool sum;
  if (l_op.size() > r_op.size()) {
    r_op = other.FillSign(l_op.size() - r_op.size()).digits;
  } else if (l_op.size() < r_op.size()) {
    l_op = first.FillSign(r_op.size() - l_op.size()).digits;
  }

  std::vector<bool> aux;
  for (size_t i = 0; i < l_op.size(); i++) {
    sum = l_op[i] ^ r_op[i] ^ carry;
    carry = (l_op[i] & r_op[i]) | (l_op[i] & carry) |
            (r_op[i] & carry);
    aux.push_back(sum);
  }
  // Overflow case, we need to add one more bit
 
  if (!(first[first.size() - 1] != other[other.size() - 1])) {
    if (aux[aux.size() - 1] != first[first.size() - 1]) {
      aux.push_back(first[first.size() - 1]);
    }
  }

  BigInt<2> result(aux);
  return result;
}

BigInt<2> BigInt<2>::sum_overflow(const BigInt<2> &first, const BigInt<2> &other) const {
  std::vector<bool> l_op = first.digits;
  std::vector<bool> r_op = other.digits;
  bool carry = false;
  bool sum;
  // asd zeros if overflow
  if (l_op.size() > r_op.size()) {
    r_op = other.FillSign(l_op.size() - r_op.size()).digits;
  } else if (l_op.size() < r_op.size()) {
    l_op = first.FillSign(r_op.size() - l_op.size()).digits;
  }

  std::vector<bool> aux;
  for (size_t i = 0; i < l_op.size(); i++) {
    sum = l_op[i] ^ r_op[i] ^ carry;
    carry = (l_op[i] & r_op[i]) | (l_op[i] & carry) |
            (r_op[i] & carry);
    aux.push_back(sum);
  }
  BigInt<2> result(aux);
  return result;
}

BigInt<2> BigInt<2>::operator-(const BigInt<2> &other) const {
  BigInt<2> r_op = other.TwoComplement();
  BigInt<2> result = *this + r_op;
  return result;
}

void BigInt<2>::operator>>(BigInt<2> &other) {
  // Example 0001 >> 1001 = 0100 1100
  std::vector<bool> aux;
  aux.insert(aux.end(), digits.begin(), digits.end() - 1);
  aux.insert(aux.begin(), digits[0]);
  std::vector<bool> aux2;
  aux2.insert(aux2.end(), other.digits.begin(), other.digits.end() - 1);
  aux2.insert(aux2.begin(), digits[digits.size() - 1]);
  this->SetDigits(aux);
  other.SetDigits(aux2);
}

void BigInt<2>::operator<<(BigInt<2> &other) {
  // Example 0110 << 0100 = 1100 1000
  std::vector<bool> aux;
  aux.insert(aux.end(), digits.begin() + 1, digits.end());
  aux.push_back(other.digits[0]);
  std::vector<bool> aux2;
  aux2.insert(aux2.end(), other.digits.begin() + 1, other.digits.end());
  aux2.push_back(other.digits[other.digits.size() - 1]);
  this->SetDigits(aux);
  other.SetDigits(aux2);
}

BigInt<2> BigInt<2>::operator*(const BigInt<2> &other) const {
  // multiply each bit and store the results in a vector
    std::vector<bool> result(digits.size() + other.size(), false);
    for (size_t i = 0; i < digits.size(); i++) {
        for (size_t j = 0; j < other.size(); j++) {
          // xor
          if(digits[i] && other[j]) {
            result[i + j] =  !result[i + j];
          } else if (!(digits[i] || other[j])) {
            result[i + j] =  false;
          }
        }
      }
      BigInt<2> res(result);
      if(this->digits[digits.size() - 1] != other.digits[other.size() - 1]) {
        res = -res;
      }

    // convert the vector of bits into a BigInt<2>
    return BigInt<2>(result);
}

BigInt<2> operator/(const BigInt<2> &first, const BigInt<2> &other) {
  // same size
  BigInt<2> dividend = first;
  BigInt<2> divisor = other;
  if (dividend.digits.size() > divisor.digits.size()) {
    divisor = other.FillSign(dividend.digits.size() - divisor.digits.size());
  } else if (dividend.digits.size() < divisor.digits.size()) {
    dividend = first.FillSign(divisor.digits.size() - dividend.digits.size());
  }
  //
  BigInt<2> divisor_abs = divisor.Abs();
  std::vector<bool> dividend_dig = dividend.Abs().digits;
  dividend_dig.erase(dividend_dig.end() - 1);
  BigInt<2> remainder(dividend_dig);
  std::vector<bool> temp(divisor_abs.digits.size(), false);
  BigInt<2> sub(temp);

  for (size_t i = 0; i < remainder.digits.size(); i++) {
    remainder >> sub;
    sub = sub.sum_overflow(sub, -divisor_abs);
    if (sub.digits[sub.size() - 1]) {
      remainder.digits[0] = false;
      sub = sub + divisor_abs;
    } else {
      remainder.digits[0] = true;
    }
  }
  // Only Cocient
  std::vector<bool> result;
  result.insert(result.begin(), remainder.digits.begin(), remainder.digits.end());
  // Clear the sign bit
  while ( result.size() > 2 && (result.back() == *(result.end() - 2)) && result.back() == 0) {
    result.erase(result.end() - 1);
  }
  // Change the sign if first and second are different
  BigInt<2> Quotient(result);
  if (first.digits[first.digits.size() - 1] !=
      other.digits[other.digits.size() - 1]) {
    Quotient = Quotient.TwoComplement();
  }
  return Quotient;
}

BigInt<2> &BigInt<2>::operator++() {
  *this = *this + BigInt<2>("01");
  return *this;
}

BigInt<2> BigInt<2>::operator++(int) {
  BigInt<2> aux = *this;
  (*this) = (*this) + BigInt<2>("01");
  return aux;
}

BigInt<2> &BigInt<2>::operator--() {
  *this = *this - BigInt<2>("01");
  return *this;
}

BigInt<2> BigInt<2>::operator--(int) {
  BigInt<2> aux = *this;
  (*this) = (*this) - BigInt<2>("01");
  return aux;
}

BigInt<2> BigInt<2>::FillSign(size_t n) const {
  std::string aux = this->to_string();
  char sign = aux[0];
  aux.insert(0, n, sign);
  BigInt<2> result(aux);
  return result;
}

BigInt<2> BigInt<2>::Abs() const {
  if (digits[digits.size() - 1]) {
    return this->TwoComplement();
  }
  return *this;
}

BigInt<2> BigInt<2>::TwoComplement() const {
  bool is_zero = true;
  for(int i = 0; i < digits.size(); i++){
    if(digits[i]){
      is_zero = false;
      break;
    }
  }

  if(is_zero) return *this;

  // Find the complement of the current value by flipping all bits
    std::vector<bool> complement(digits.size());
    for (size_t i = 0; i < digits.size(); i++)
        complement[i] = !digits[i];

    // Add one to the complement to get the two's complement
    bool carry = true;
    for(int i = 0; i < complement.size(); i++) {
      if(carry) {
        complement[i] = !complement[i];
        carry = !complement[i];
      }
    }
    if (carry) complement.push_back(true);

    return BigInt<2>(complement);
}

BigInt<2> BigInt<2>::operator%(const BigInt<2> &other) const {

  BigInt<2> dividend = *this;
  BigInt<2> divisor = other;

  if (dividend.digits.size() > divisor.digits.size()) {
    divisor = other.FillSign(dividend.digits.size() - divisor.digits.size());
  } else if (dividend.digits.size() < divisor.digits.size()) {
    dividend = this->FillSign(divisor.digits.size() - dividend.digits.size());
  }
  
  BigInt<2> divisor_abs = divisor.Abs();
  std::vector<bool> dividend_dig = dividend.Abs().digits;
  dividend_dig.erase(dividend_dig.end() - 1);
  BigInt<2> remainder(dividend_dig);
  std::vector<bool> temp(divisor_abs.digits.size(), false);
  BigInt<2> sub(temp);

  for (size_t i = 0; i < remainder.digits.size(); i++) {
    remainder >> sub;
    sub = sub - divisor_abs;
    if (sub.digits[sub.size() - 1]) {
      remainder.digits[0] = false;
      sub = sub + divisor_abs;
    } else {
      remainder.digits[0] = true;
    }
  }
  
  std::vector<bool> result;
  result.insert(result.begin(), sub.digits.begin(), sub.digits.end() - 1);
  BigInt<2> Quotient(result);
  return Quotient;
}

BigInt<2> pow(const BigInt<2> &first, const BigInt<2> &other) {
  static  BigInt<2> zero ("00");
  static  BigInt<2> one ("01");
  static  BigInt<2> two ("010");
  if (other < zero) {
    return zero;
  }
  if (other == zero) {
    return one;
  } else if (other % two == zero) {
    BigInt<2> recPower = pow(first, other / two);
    return recPower.square();
  } else {
    BigInt<2> recPower = pow(first, (other - one) / two);
    return recPower.square() * first;
  }
}

BigInt<2> BigInt<2>::square() const {
  BigInt<2> result = *this;
  result = result * result;
  return result;
}

BigInt<2> BigInt<2>::operator^(const BigInt<2> &other) const {
  return pow(*this, other);
}


BigInt<2> BigInt<2>::operator-() const{
  return this->TwoComplement();
}

/*
  2nd Practice Methods

*/

template <size_t base>
BigInt<base> BigInt<2>::ConvBase() const{
  BigInt<2> aux(*this);
  BigInt<base> result;
  int aux_sign;

  if (aux.digits[aux.digits.size() - 1]) {
    aux_sign = 1;
    aux = aux.TwoComplement();
  } 
  for(int i = 0; i < aux.digits.size(); i++){
    if(aux.digits[i]){
      result = result + BigInt<base>(pow(2, i));
    }
  }

  if(aux_sign == 1){
    result = -result;
  }
  return result;
}

std::ostream &operator<<(std::ostream &os, const BigInt<2> &l_op) {

  for (int i = l_op.digits.size() - 1; i >= 0; i--) {
    os << l_op.digits[i];
  }
  return os;
}

/*
  Implmentation of 3rd Practice

*/


Number* BigInt<2>::add(Number* other) const {
  BigInt<2> *other2 = dynamic_cast<BigInt<2>*>(other);
  if (other2 == nullptr) {
    return nullptr;
  }
  return new BigInt<2>(*this + *other2);
}

Number* BigInt<2>::sub(Number* other) const {
  BigInt<2> *other2 = dynamic_cast<BigInt<2>*>(other);
  if (other2 == nullptr) {
    return nullptr;
  }
  return new BigInt<2>(*this - *other2);
}

Number* BigInt<2>::mul(Number* other) const {
  BigInt<2> *other2 = dynamic_cast<BigInt<2>*>(other);
  if (other2 == nullptr) {
    return nullptr;
  }
  return new BigInt<2>(*this * *other2);
}

Number* BigInt<2>::div(Number* other) const {
  BigInt<2> *other2 = dynamic_cast<BigInt<2>*>(other);
  if (other2 == nullptr) {
    return nullptr;
  }
  return new BigInt<2>(*this / *other2);
}

Number* BigInt<2>::mod(Number* other) const {
  BigInt<2> *other2 = dynamic_cast<BigInt<2>*>(other);
  if (other2 == nullptr) {
    return nullptr;
  }
  return new BigInt<2>(*this % *other2);
}

Number* BigInt<2>::pow2(Number* other) const {
  BigInt<2> *other2 = dynamic_cast<BigInt<2>*>(other);
  if (other2 == nullptr) {
    return nullptr;
  }
  return new BigInt<2>(*this ^ *other2);
}

std::ostream& BigInt<2>::write(std::ostream& os) const {
  os << *this;
  return os;
}

std::istream& BigInt<2>::read(std::istream& is) {
  is >> *this;
  return is;
}

BigInt<2>::operator BigInt<2>() const {
  return *this;
}

BigInt<2>::operator BigInt<10>() const {
  return this->ConvBase<10>();
}

BigInt<2>::operator BigInt<16>() const {
  return this->ConvBase<16>();
}

BigInt<2>::operator BigInt<8>() const {
  return this->ConvBase<8>();
}


Number& BigInt<2>::operator=(const Number& other) {
  const BigInt<2>* other2 = dynamic_cast<const BigInt<2>*>(&other);
  if (other2 == nullptr) {
    other2 = new BigInt<2>(other);
    *this = *other2;
  }
  else {
    *this = *other2;
  }
  return *this;
}

std::istream &operator>>(std::istream &is, BigInt<2> &aux) {
  std::string aux_s;
  is >> aux_s;
  aux = BigInt<2>(aux_s);
  return is;
}

#endif  // BIGINT_H_