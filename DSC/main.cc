#include "dsc_base.h"
#include "dsc_array.h"

#include <iostream>

int main() {
    dsc_array<int, 3> array;
    array.insert((int)1);
    array.insert((int)3);
    std::cout << array << std::endl;

    /*dsc_base<int> *base = new dsc_array<int,3>();
    base->insert((int)1);
    std::cout << *base << std::endl;*/
   


 
}