#ifndef BIGINT_CC
#define BIGINT_CC

#include "bigint.h"


/**********************************************************************************************************************************
 * 
 * 
  Implementation methods of BigInt class


***********************************************************************************************************************************/

//Constructors

template <size_t Base>
BigInt<Base>::BigInt(long n) {
  if (n == 0) {
    sign_ = 1;
    digits_.push_back(0);
    return;
  }
  if (n < 0) {
    sign_ = -1;
    n = -n;
  } else {
    sign_ = 1;
  }
  while (n > 0) {
    digits_.push_back(n % Base);
    n /= Base;
  }
}

template <size_t Base>
BigInt<Base>::BigInt(const std::string &number_str) {
  // Si es vacio
  if (number_str.empty()) {
    sign_ = 1;
    digits_.push_back(0);
    return;
  }
  std::string number_big = number_str;
  digits_.clear();
  if (number_big[0] == '-') {
    sign_ = -1;
    number_big.erase(0, 1);
  } else {
    sign_ = 1;
  }
  
  for (int i = number_big.size() - 1; i >= 0; i--) {
    if (isdigit(number_big[i])) {
      digits_.push_back(number_big[i] - '0');
    } else if (number_big[i] >= 'A' && number_big[i] <= 'F') {
      digits_.push_back(number_big[i] - 'A' + 10);
    } else {
          digits_.push_back(0);
           throw BigIntBadDigit();
    }
  }
}

template <size_t Base>
BigInt<Base>::BigInt(const char *aux_ptr) {
  size_t size_ptr = std::char_traits<char>::length(aux_ptr);
  // Si es vacio
  if (size_ptr == 0) {
    sign_ = 1;
    digits_.push_back(0);
    return;
  }
  digits_.clear();
  if (aux_ptr[0] == '-') {
    sign_ = -1;
    aux_ptr++;
    size_ptr--;
  } else {
    sign_ = 1;
  }
  for (int i = size_ptr - 1; i >= 0; --i) {
    if (isdigit(aux_ptr[i])) {
      digits_.push_back(aux_ptr[i] - '0');
    } else if (aux_ptr[i] >= 'A' && aux_ptr[i] <= 'F') {
      digits_.push_back(aux_ptr[i] - 'A' + 10);
    } else {
      std::cout << (int)aux_ptr[i] << std::endl;
      digits_.push_back(0);
      throw BigIntBadDigit();
    }
  }
}

template <size_t Base>
BigInt<Base>::BigInt(const std::vector<char> &digits_aux, const int &sign_aux) {
  char max_digit = static_cast<char>(Base);
  for (size_t i = 0; i < digits_aux.size(); i++) {
    if (digits_aux[i] >= max_digit) {
      digits_.push_back(0);
      throw BigIntBadDigit();
    }
  }
  digits_ = digits_aux;
  sign_ = sign_aux;
}

template <size_t Base>
BigInt<Base>::BigInt(const BigInt<Base> &number_big) {
  sign_ = number_big.sign_;
  digits_ = number_big.digits_;
}


// Operators
template <size_t Base>
BigInt<Base> &BigInt<Base>::operator=(const BigInt<Base> &number_big) {
  sign_ = number_big.sign_;
  digits_ = number_big.digits_;
  return *this;
}

// SetterGetter
template <size_t Base>
BigInt<Base> BigInt<Base>::SetSign(int sign_aux) {
  sign_ = sign_aux;
  return *this;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::SetDigits(std::vector<char> digits_aux) {
  digits_ = digits_aux;
  return *this;
}

//Getters
template <size_t Base>
std::vector<char> BigInt<Base>::GetDigits() const {
  return digits_;
}

template <size_t Base>
int BigInt<Base>::sign() const {
  return sign_;
}

template <size_t Base>
size_t BigInt<Base>::size() const {
  return digits_.size();
}


//Accessors
template <size_t Base>
char BigInt<Base>::operator[](size_t position) const {
  if (position < 0 || position >= digits_.size()) {
    std::cout << "position: " << position << " Size " << digits_.size() << std::endl;
    throw std::out_of_range("operator[]: Invalid position");
  }
  return digits_[position];
}


//Operators == != < > <= >=
template <size_t Base_t>
bool operator==(const BigInt<Base_t> &l_op, const BigInt<Base_t> &r_op) {
  BigInt<Base_t> l_op_aux = l_op;
  BigInt<Base_t> r_op_aux = r_op;
  if (l_op_aux.IsZero() && r_op_aux.IsZero()) {
    return true;
  }
  if (l_op.sign() != r_op.sign()) {
    return false;
  }
  if (l_op.size() != r_op.size()) {
    // fill with zeros
    size_t size_difference =
        std::abs(static_cast<int>(l_op.size()) -
                 static_cast<int>(r_op.size()));
    if (l_op.size() > r_op.size()) {
      r_op_aux = r_op_aux.FillZeros(size_difference);
    } else if (l_op.size() < r_op.size()) {
      l_op_aux = l_op_aux.FillZeros(size_difference);
    }
  }

  for (size_t i = 0; i < l_op_aux.size(); i++) {
    if (l_op_aux[i] != r_op_aux[i]) {
      return false;
    }
  }
  return true;
}

template <size_t Base>
bool BigInt<Base>::operator!=(const BigInt<Base> &r_op) const {
  return !(*this == r_op);
}

template <size_t Base_t>
bool operator>(const BigInt<Base_t> &l_op, const BigInt<Base_t> &r_op) {
  if (l_op.sign() > r_op.sign()) {
    return true;
  } else if (l_op.sign() < r_op.sign()) {
    return false;
  }
  size_t delta =
      abs(l_op.size() - r_op.size());
  BigInt<Base_t> r_op_aux;
  BigInt<Base_t> l_op_aux;
  if (l_op.size() > r_op.size()) {
    r_op_aux = r_op.FillZeros(delta);
    l_op_aux = l_op;
  } else if (l_op.size() < r_op.size()) {
    l_op_aux = l_op.FillZeros(delta);
    r_op_aux = r_op;
  } else {
    l_op_aux = l_op;
    r_op_aux = r_op;
  }

  for (int i = l_op_aux.size() - 1; i >= 0; i--) {
    if (l_op_aux.GetDigits()[i] > r_op_aux.GetDigits()[i]) {
      return l_op_aux.sign() == 1 ? true : false;
    } else if (l_op_aux.GetDigits()[i] < r_op_aux.GetDigits()[i]) {
      return l_op_aux.sign() == 1 ? false : true;
    }
  }
  return false;
}

template <size_t Base>
bool BigInt<Base>::operator>=(const BigInt<Base> &r_op) const {
  return (*this > r_op || *this == r_op);
}

template <size_t Base_t>
bool operator<(const BigInt<Base_t> &l_op, const BigInt<Base_t> &r_op) {
  return !(l_op >= r_op);
}

template <size_t Base>
bool BigInt<Base>::operator<=(const BigInt<Base> &r_op) const {
  return !(*this > r_op);
}

template <size_t Base>
bool BigInt<Base>::IsZero() const {
  // Check if the number is zero or not
  for (size_t i = 0; i < digits_.size(); i++) {
    if (digits_[i] != 0) {
      return false;
    }
  }
  return true;
}


template <size_t Base>
BigInt<Base> BigInt<Base>::FillZeros(unsigned number_zero) const {
  std::string number_str = this->to_string();
  number_str.insert(number_str.begin(), number_zero, '0');
  return BigInt<Base>(number_str);
}


template <size_t Base>
BigInt<Base> BigInt<Base>::Abs() const {
  BigInt<Base> number_aux = *this;
  number_aux.SetSign(1);
  return number_aux;
}

template <size_t Base>
std::string BigInt<Base>::to_string() const {
  std::string number_str;
  if (sign_ == -1) {
    number_str += '-';
  }
  for (int i = digits_.size() - 1; i >= 0; i--) {
    if (digits_[i] < 10) {
      number_str += digits_[i] + '0';
    } else {
      number_str += digits_[i] - 10 + 'A';
    }
  }
  return number_str;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator-() const {
  BigInt<Base> number_aux = *this;
  number_aux.SetSign(-number_aux.sign());
  return number_aux;
}

template <size_t Base_t>
BigInt<Base_t> operator+(const BigInt<Base_t> &l_op, const BigInt<Base_t> &r_op) {
  int carry = 0;
  size_t delta = abs(l_op.size() - r_op.size());
  BigInt<Base_t> r_op_aux;
  BigInt<Base_t> l_op_aux;
  if (l_op.size() > r_op.size()) {
    r_op_aux = r_op.FillZeros(delta);
    l_op_aux = l_op;
  } else if (l_op.size() < r_op.size()) {
    l_op_aux = l_op.FillZeros(delta);
    r_op_aux = r_op;
  } else {
    l_op_aux = l_op;
    r_op_aux = r_op;
  }
  
  if (l_op_aux.sign() != r_op_aux.sign()) {
    if (l_op_aux.sign() == -1) {
      return r_op_aux - (-l_op_aux);
    } else {
      return l_op_aux - (-r_op_aux);
    }
  }

  std::vector<char> digits_sum;
  for (size_t i = 0; i < l_op_aux.size(); i++) {
    int sum = l_op_aux[i] + r_op_aux[i] + carry;
    digits_sum.push_back(sum % Base_t);
    carry = sum / Base_t;
  }
  if (carry != 0) {
    digits_sum.push_back(carry);
  }
  return BigInt<Base_t>(digits_sum, l_op_aux.sign());
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator-(const BigInt<Base> &r_op) const {
  size_t delta =
      abs(this->size() - r_op.size());
  BigInt<Base> r_op_aux;
  BigInt<Base> l_op_aux;
  if (this->size() > r_op.size()) {
    r_op_aux = r_op.FillZeros(delta);
    l_op_aux = *this;
  } else if (this->size() < r_op.size()) {
    l_op_aux = this->FillZeros(delta);
    r_op_aux = r_op;
  } else {
    l_op_aux = *this;
    r_op_aux = r_op;
  }
  // Only for positive numbers and l_op_aux > r_op_aux we can control
  // this situation always

  if (l_op_aux < r_op_aux) {
    return BigInt<Base>(r_op_aux - l_op_aux).SetSign(-1);
  }
  if (l_op_aux.sign() == 1 && r_op_aux.sign() == -1) {
    return BigInt<Base>(l_op_aux + (-r_op_aux));
  } else if (l_op_aux.sign() == -1 && r_op_aux.sign() == 1) {
    return BigInt<Base>((-l_op_aux) + r_op_aux);
  } else if (l_op_aux.sign() == -1 && r_op_aux.sign() == -1) {
    return BigInt<Base>(l_op_aux + (-r_op_aux));
  }

  std::vector<char> digits_sub;
  int carry = 0;
  for (size_t i = 0; i < l_op_aux.size(); i++) {
    int sub = l_op_aux[i] - r_op_aux[i] - carry;
    if (sub < 0) {
      sub += Base;
      carry = 1;
    } else {
      carry = 0;
    }
    digits_sub.push_back(sub);
  }

  return BigInt<Base>(digits_sub, l_op_aux.sign());
}

template <size_t Base>
BigInt<Base> &BigInt<Base>::operator++() {
  BigInt<Base> One(1);
  *this = *this + One;
  return *this;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator++(int) {
  BigInt<Base> One(1);
  BigInt<Base> number_aux = *this;
  *this = *this + One;
  return number_aux;
}

template <size_t Base>
BigInt<Base> &BigInt<Base>::operator--() {
  BigInt<Base> One(1);
  *this = *this - One;
  return *this;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator--(int) {
  BigInt<Base> number_aux = *this;
  BigInt<Base> One(1);

  *this = *this - One;
  return number_aux;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator*(const BigInt<Base> &other) const {
  // If one of the numbers is zero, the result is zero
  if(this->IsZero() || other.IsZero()) return BigInt<Base>(0L);
  //size of result
  std::vector<char> aux(this->size() + other.size(), 0);

  int sum;
  for(size_t i = 0; i < this-> size(); i++){
    int carry = 0;
    for(size_t j = 0; j < other.size(); j++){
      sum = this->digits_[i] * other.digits_[j] + aux[i+j] + carry;
      carry = sum / Base;
      sum %= Base;
      aux[i+j] = sum;
    }
    aux[i + other.size()] = carry;
  }

  //remove leading zeros
  while(aux.back() == 0 && aux.size() > 1) aux.pop_back();

  BigInt<Base> result(aux, this->sign() * other.sign());
  return result;
}

template <size_t Base>
BigInt<Base> operator/(const BigInt<Base> &l_op, const BigInt<Base> &r_op) {
   BigInt<Base> a = l_op;
    BigInt<Base> b = r_op;

    if(b.IsZero()) {
      throw BigIntDivisionByZero();
      return BigInt<Base>(); 
    }
  
    if(a < b)  return BigInt<Base>();
    if(a == b) return BigInt<Base>(1);
    
    long i, lgcat = 0, cc;
    long n = a.size();
    std::vector<char> cat(n, 0);
    BigInt<Base> t;
    BigInt<Base> aux_base(Base);
    for (i = n - 1; i >= 0 && (t * aux_base) + BigInt<Base>(a[i])  < b; i--){
        t = t * aux_base;
        t = t + BigInt<Base>((int)a[i]);
    }
    for (; i >= 0; i--){
        t = (t * Base) + BigInt<Base>((int)a[i]);
        for (cc = Base-1; b * cc > t;cc--);
        t = t - (b * cc) ;
        cat[lgcat++] = cc;
    }

    std::vector<char> result(cat.size(), 0);

    for (i = 0; i < lgcat;i++)
        result[i] = cat[lgcat - i - 1];
    int sign = (a.sign() == b.sign()) ? 1 : -1;

  //Clean the result
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();


    BigInt<Base> r(result, sign);
    return r;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator%(const BigInt<Base> &r_op) const {
  return *this - (((*this / r_op).Abs()) * r_op);
}

template <size_t Base>
BigInt<Base> pow(const BigInt<Base> &l_op, const BigInt<Base> &r_op) {
static  BigInt<Base> zero;
  static  BigInt<Base> one (1);
  static  BigInt<Base> two (2);
  if (r_op < zero) {
    return zero;
  }
  if (r_op == zero) {
    return one;
  } else if (r_op % two == zero) {
    BigInt<Base> half = pow(l_op, r_op / two);
    return half * half;
  } else {
    BigInt<Base> half = pow(l_op, (r_op - one) / two);
    return half * half * l_op;
  }
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator^(const BigInt<Base> &r_op) const {
  return pow(*this, r_op);
}

template <size_t Base_aux>
std::ostream &operator<<(std::ostream &os, const BigInt<Base_aux> &number_aux) {
  std::string number_str = number_aux.to_string();
  os << number_str;
  return os;
}

template <size_t Base_t>
std::istream &operator>>(std::istream &input, BigInt<Base_t> &l_op){
  std::string number_str;
  input  >> number_str;
  l_op = BigInt<Base_t>(number_str);
  return input;
}

template <size_t Base>
 BigInt<Base>::operator BigInt<2>() const {
  BigInt<Base> number_aux = this->Abs();
  BigInt<Base> zero;
  BigInt<Base> two(2);
  std::vector<bool> result;
  if (number_aux == zero) {
    result.push_back(false);
    result.push_back(0);
    return BigInt<2>(result);
  }
  while (number_aux != zero) {
    result.push_back(number_aux % two == zero ? false : true);
    number_aux = number_aux / two;
  }
  // put the sign
  result.push_back(0);
  if (this->sign() == -1) {
    BigInt<2> aux(result);
    return -aux;
  }

  BigInt<2> aux(result);
  return aux;
}

/*
  3rd Practice Methods implementation
*/
template <size_t Base>
Number* BigInt<Base>::add(Number* other) const {
 const BigInt *aux_other = dynamic_cast<const BigInt *>(other);
 if(aux_other == nullptr){
    aux_other = new BigInt<Base>(*other);
    return new BigInt<Base>(*this + *aux_other);
 }
 BigInt<Base> *result = new BigInt<Base>(*this + *aux_other);
 return result;
}

template <size_t Base>
Number* BigInt<Base>::sub(Number* other) const {
  const BigInt *aux_other = dynamic_cast<const BigInt *>(other);
  if(aux_other == nullptr){
      aux_other = new BigInt<Base>(*other);
      return new BigInt<Base>(*this - *aux_other);
  }
  BigInt<Base> *result = new BigInt<Base>(*this - *aux_other);
  return result;
}

template <size_t Base>
Number* BigInt<Base>::mul(Number* other) const {
  const BigInt *aux_other = dynamic_cast<const BigInt *>(other);
  if(aux_other == nullptr){
      aux_other = new BigInt<Base>(*other);
      return new BigInt<Base>(*this * *aux_other);
  }
  BigInt<Base> *result = new BigInt<Base>(*this * *aux_other);
  return result;
}

template <size_t Base>
Number* BigInt<Base>::div(Number* other) const {
  const BigInt *aux_other = dynamic_cast<const BigInt *>(other);
  if(aux_other == nullptr){
      aux_other = new BigInt<Base>(*other);
      return new BigInt<Base>(*this / *aux_other);
  }
  BigInt<Base> *result = new BigInt<Base>(*this / *aux_other);
  return result;
}

template <size_t Base>
Number* BigInt<Base>::mod(Number* other) const {
  const BigInt *aux_other = dynamic_cast<const BigInt *>(other);
  if(aux_other == nullptr){
      aux_other = new BigInt<Base>(*other);
      return new BigInt<Base>(*this % *aux_other);
  }
  BigInt<Base> *result = new BigInt<Base>(*this % *aux_other);
  return result;
}


template <size_t Base>
Number* BigInt<Base>::pow2(Number* other) const {
  const BigInt *aux_other = dynamic_cast<const BigInt *>(other);
  if(aux_other == nullptr){
      aux_other = new BigInt<Base>(*other);
      return new BigInt<Base>(*this ^ *aux_other);
  }
  BigInt<Base> *result = new BigInt<Base>(*this ^ *aux_other);
  return result;
}

template <size_t Base>
std::ostream& BigInt<Base>::write(std::ostream& os) const {
  std::string number_str = this->to_string();
  os << number_str;
  return os;
}

template <size_t Base>
std::istream& BigInt<Base>::read(std::istream& is)  {
  is >> *this;
  return is;
}

template <size_t Base>
BigInt<Base>::operator BigInt<8>() const {
  BigInt<Base> aux_n = *this;
  BigInt<2> binary_n = aux_n.operator BigInt<2>();
  BigInt<8> octal_n = binary_n.ConvBase<8>();
  return octal_n;
}

template <size_t Base>
BigInt<Base>::operator BigInt<16>() const {
  BigInt<Base> aux_n = *this;
  BigInt<2> binary_n = aux_n.operator BigInt<2>();
  BigInt<16> hex_n = binary_n.ConvBase<16>();
  return hex_n;
}

template <size_t Base>
BigInt<Base>::operator BigInt<10>() const {
  BigInt<Base> aux_n = *this;
  BigInt<2> binary_n = aux_n.operator BigInt<2>();
  BigInt<10> dec_n = binary_n.ConvBase<10>();
  return dec_n;
}

template <size_t Base>
size_t BigInt<Base>::get_base() const {
  switch (Base) {
    case 2:
    return 2;
    case 8:
    return 8;
    case 10:
    return 10;
    case 16:
    return 16;
    default:
    return 0;
  }
}

template <size_t Base>
Number& BigInt<Base>::operator=(const Number& other) {
  const BigInt* aux_other = dynamic_cast<const BigInt*>(&other);
  if(aux_other == nullptr){
    aux_other = new BigInt<Base>(other);
    *this = *aux_other;
  } else {
    *this = *aux_other;
  }
  return *this;
}

#endif // BIGINT_CC