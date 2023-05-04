
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <functional>
#include <typeinfo>


template <class T>
class Rpn {
 public:
  Rpn(const std::vector<std::vector<std::string>>&);
  void OpStore();
  T Operate(std::vector<std::string> tokens_line);
  void Process();
  void Operation(std::string op);

  bool isOperand(const std::vector<std::string>& s);

  template <class U>
  friend std::ostream& operator<<(std::ostream& os, const Rpn<U>& c);

  std::map<std::string, T> getVariables() const { return variables; }

 private:
  std::vector<std::vector<std::string>> tokens;
  std::stack<T> stack;
  std::map<std::string, T> variables;
  std::map<std::string, std::function<T(T, T)>> operations;
  std::map<std::string, std::function<T(T)>> unary_operations;

};


template <class T>
Rpn<T>::Rpn(const std::vector<std::vector<std::string>>& tokens) {
  OpStore();
  this->tokens = tokens;
}

template <class T>
void Rpn<T>::OpStore() {
  // Operations
  operations["+"] = [](T a, T b) { return a.add(b); };
  operations["-"] = [](T a, T b) { return a.sub(b); };
  operations["*"] = [](T a, T b) { return a.mul(b); };
  operations["/"] = [](T a, T b) { return a.div(b); };
  operations["%"] = [](T a, T b) { return a.mod(b); };
  operations["^"] = [](T a, T b) { return a.pow2(b); };
  operations["=="] = [](T a, T b) { return a == b; };
  operations["!="] = [](T a, T b) { return a != b; };
  operations["<"] = [](T a, T b) { return a < b; };
  operations["<="] = [](T a, T b) { return a <= b; };
  operations[">"] = [](T a, T b) { return a > b; };
  operations[">="] = [](T a, T b) { return a >= b; };
  operations["="] = [](T a, T b) { return a = b; };

  // Unary operations
  unary_operations["++"] = [](T a) { return ++a; };
  unary_operations["--"] = [](T a) { return --a; };
  unary_operations["-"] = [](T a) { return -a; };
}


template <class T>
T Rpn<T>::Operate(std::vector<std::string> tokens_line) {
  for (auto& token : tokens_line) {
    if (operations.count(token) == 1) {
      if (stack.size() < 2) {
        goto error;
      }
      T a = stack.top();
      stack.pop();
      T b = stack.top();
      stack.pop();
      stack.push(operations[token](b, a));
    } else if (unary_operations.count(token) == 1) {
      if (stack.size() < 1) {
        goto error;
      }
      T a = stack.top();
      stack.pop();
      stack.push(unary_operations[token](a));
    } else if (variables.count(token) == 1) {
      stack.push(variables[token]);
    } else {
    error:
      // Error clear stack and return 0
      while (!stack.empty()) {
        stack.pop();
      }
      std::cerr << "Error in line: " << std::endl;
      T a;
      return a;
    }
  }
  return stack.top();
}

template <class T>
bool Rpn<T>::isOperand(const std::vector<std::string>& s) {
    bool isOperand = false;
   if(s.size() == 3 && ((s[1] == "="))) {
    for(auto& c : s[2]) {
        if((c >= '0' && c <= '9') ||  (c >= 'A' && c <= 'F')) {
            return isOperand = true;
        }
    }
   } else if (s.size() > 3) {
    return isOperand = false;
   } else {
    std::cout << "Error en la linea de lectura" << std::endl;
    exit(1);
   }
   return isOperand;
}


template <class T>
void Rpn<T>::Process() {
  // Process tokens
 
  for (auto& line : tokens) {
      // Check if is a number or a variable
      if(isOperand(line)) {
            // Create a BigInt<2> and store it in the map
            BigInt<2> aux(line[2]);
            variables[line[0]] = aux;
   } else if (!isOperand(line)) {
     //
      if ((line[1] != "?") && (line[1] != "=" )) {
        std::cout << "Error in line: ";
        for (auto& token : line) {
          std::cout << token << " ";
        }
        std::cout << std::endl;
        continue;
      }
      std::vector<std::string> tokens_line(line.begin() + 2, line.end());
      variables[line[0]] = Operate(tokens_line);
    } else {
      // Print error in line and continue
      std::cout << "Error in line: ";
      for (auto& token : line) {
        std::cout << token << " ";
      }
    }
  }
}

template <class C>
std::ostream& operator<<(std::ostream& os, const Rpn<C>& c) {
  for (auto& var : c.variables) {
      BigInt<2> aux = var.second;
      os << var.first << " = " << aux << std::endl;
  }

  return os;
}

