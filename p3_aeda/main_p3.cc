#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "bigint.h"
#include "rpn.h"
#include "number.cc"
#include "number.h"


int main(int argc, char* argv[]) {

  if(argc < 3) {
    std::cerr << "Usage: " << argv[0] << " input_file output_file" << std::endl;
    exit(1);
  }
  
  std::ifstream input(argv[1]);
  std::ofstream output(argv[2]);

  if (!input.is_open()) {
    std::cerr << "Error opening input file " << std::endl;
    exit(1);
  }
  if (!output.is_open()) {
    std::cerr << "Error opening output file " << std::endl;
    exit(1);
  }

  try {
  // Reading Tokens from file into a vector of vectors of strings
  std::vector<std::vector<std::string>> tokens;
  std::string line;
  while (std::getline(input, line)) {
    std::istringstream iss(line);
    std::vector<std::string> line_tokens;
    std::string token;
    while (iss >> token) {
      line_tokens.push_back(token);
    }
    tokens.push_back(line_tokens);
  }
  // Creating RPN object and processing the tokens
   Rpn<Number *> rpn(tokens);
    rpn.Process();
    output << rpn;

  } catch (BigIntBadDigit& e) {
    std::cout << e.what() << std::endl;
  } catch (BigIntBaseNotImplemented& e) {
    std::cout << e.what() << std::endl;
  } catch (BigIntException& e) {
    std::cout << e.what() << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  } catch (...) {
    std::cout << "Unknown error" << std::endl;
  }

  return 0;
}

