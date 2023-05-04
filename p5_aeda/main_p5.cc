#include <iostream>
#include <vector>

#include "functions.cc"
#include "SortMethod.h"
int main() {

      int size = which_size();
      int ex_type = exe_type();
      bool trace;

      if(ex_type == 1) trace = false;
      else trace = true;

      std::vector<long> v = gen_seq(ex_type, size);
      menu(size, v, trace);

  return 0;
}



