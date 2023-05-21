#include <iostream>

int main(){

    char* const s1 = "ABC";
    *s1 = 'a';
    std::cout << *s1 << std::endl;
    return 0;
}