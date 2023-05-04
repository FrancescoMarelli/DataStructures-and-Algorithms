#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <map>
#include <stack>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <typeinfo>

#include "number.h"
#include "bigint.h"
#include "number.cc"
#include "bigintexception.h"



template <class T>
class Rpn {
 public:
 // Constructor
  Rpn(const std::vector<std::vector<std::string>>&);
  void OpStore();
  //stack operating
  T evaluateRPNExpression(std::vector<std::string> expressionTokens);
  // Process
  void Process();
  // Print
  template <class C>
  friend std::ostream& operator<<(std::ostream& os, const Rpn<C>& c);

  //Auxiliary
  std::map<std::string, T> getVariables() const { return variables; }
  void Operation(std::string op);
  bool isOperand(const std::vector<std::string>& s);

 private:
  std::vector<std::vector<std::string>> tokens;
  std::stack<T> operandStack;
  std::map<std::string, T> variables;
  std::map<std::string, std::function<T(T, T)>> operations;

};

#include "rpn.cc"

#endif  // RPN_H