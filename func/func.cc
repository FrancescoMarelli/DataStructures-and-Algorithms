#include <iostream>

void f(int a, int *b, int &c) { 
  a = 3;   // no tiene efecto en el exterior
  *b = 3;  // se modifica el objeto al que apunta b
  b = &a;  // no tiene efecto en el exterior
  c = 4;   // c es a todos los efectos la variable pasada
  b = &c;  // es posible tomar la dirección de la variable pasada
  *b = 5; // b ahora apunta a c, por lo que se modifica c
}
 
int main() { 
  int a1 = 1, b1 = 2, c1 = 2;
  f(a1, &b1, c1);
  // resultado: a1 = 1, b1 = 3, c1 = 5
    std::cout << "a1 = " << a1 << ", b1 = " << b1 << ", c1 = " << c1 << std::endl;
  return 0;
}
