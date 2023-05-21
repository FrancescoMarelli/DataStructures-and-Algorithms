#include <iostream>

int main(){
    //
    char* const s1 = "ABC";
    //s++; error de comp
    *s1 = 'a'; // da error por compilador pero si deja porque contenido no const
    std::cout << *s1 << std::endl;

    const char* s2 = "ABC";
    s2++;
    //*s2 = 'a'; contenido constante no puedo modificar

    
    return 0;
}