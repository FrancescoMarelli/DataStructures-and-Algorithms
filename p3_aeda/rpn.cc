#include "rpn.h"

template <class T>
Rpn<T>::Rpn(const std::vector<std::vector<std::string>>& tokens) {
  OpStore();
  this->tokens = tokens;
}

template <class T>
void Rpn<T>::OpStore() {
  // Operations
  operations["+"] = [](T a, T b) { return a -> add(b); };
  operations["-"] = [](T a, T b) { return a->sub(b); };
  operations["*"] = [](T a, T b) { return a->mul(b); };
  operations["/"] = [](T a, T b) { return a->div(b); };
  operations["%"] = [](T a, T b) { return a->mod(b); };
  operations["^"] = [](T a, T b) { return a->pow2(b); };
}


template <class T>
T Rpn<T>::evaluateRPNExpression(std::vector<std::string> expressionTokens) {

    // Clear stack before evaluation
    while (!operandStack.empty()) {
        operandStack.pop();
    }

    // Iterate over expression tokens and evaluate
    try {
        for (auto& token : expressionTokens) {
            if (operations.count(token) == 1 && operandStack.size() >= 2) {
                T operandA = operandStack.top();
                operandStack.pop();
                T operandB = operandStack.top();
                operandStack.pop();
                operandStack.push(operations[token](operandB, operandA));
            } else if (variables.count(token) == 1) {
                operandStack.push(variables[token]);
            } else {
                // Invalid token, clear stack and return error
                while (!operandStack.empty()) {
                    operandStack.pop();
                }
                return Number::createNumber(10, "0");
            }
        }
    } catch (std::exception& e) {
        // Exception caught, print error message and clear stack
        std::cerr << e.what() << std::endl;
        while (!operandStack.empty()) {
            operandStack.pop();
        }
        return Number::createNumber(10, "0");
    }

    // Check stack size after evaluation
    if (operandStack.size() != 1) {
        // Invalid stack size, print error message and clear stack
        std::cerr << "Error: Stack size != 1 :";
        for (auto& token : expressionTokens) {
            std::cerr << token << " ";
        }
        std::cerr << std::endl;
        while (!operandStack.empty()) {
            operandStack.pop();
        }
        return Number::createNumber(10, "0");
    }

    // Return result
    T result = operandStack.top();
    operandStack.pop();
    return result;
}
template <class T>
bool Rpn<T>::isOperand(const std::vector<std::string>& s) {
    bool isOperand = false;
   if(s.size() == 4 && ((s[1] == "=")) ) {
    for(auto& c : s[4]) {
        if((c >= '0' && c <= '9') ||  (c >= 'A' && c <= 'F') || (c == ',')) {
            return isOperand = true;
        }
    }
   } else if (s.size() == 4 && ((s[1] == "?"))) {
    return isOperand = false;
   } else {
    std::cout << "Reading line error" << std::endl;
    exit(1);
   }
   return isOperand;
}

template <class T>
void Rpn<T>::Process() {
  for (const auto& line : tokens) {
    if (line.size() == 4 && line[1] == "=") {
      // Process variable assignment
      const std::string& tag = line[0];
      const std::string& value = line[3];

      try {
        // Check if value is a number
        const int base = std::stoi(line[2]);
        variables[tag] = Number::createNumber(base, value);
      } catch (std::invalid_argument& e) {
        std::cerr << "Failed to create number: " << e.what() << std::endl;
      } catch (BigIntBadDigit& e) {
        std::cerr << "Failed to create number: " << e.what() << std::endl;
      } catch (BigIntBaseNotImplemented& e) {
        std::cerr << "Failed to create number: " << e.what() << std::endl;
      } 
    } else if (line.size() > 3 && line[1] == "?") {
      // Process RPN expression
      const std::string& tag = line[0];
      const std::vector<std::string> rpn_tokens(line.begin() + 2, line.end());

      try {
        variables[tag] = evaluateRPNExpression(rpn_tokens);
      } catch (std::exception& e) {
        std::cerr << "Error evaluating RPN expression: " << e.what() << std::endl;
      }
    }
  }
}

template <class C>
std::ostream& operator<<(std::ostream& os, const Rpn<C>& c) {
  for (auto& var : c.variables) 
      os << var.first << " = " << *(var.second) << std::endl;

  return os;
}

