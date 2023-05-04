#ifndef _LIBRO_H_
#define _LIBRO_H_

#include <iostream>

class Libro {
    private:
    std::string ISBN;

    public:
    Libro(std::string ISBN);
    Libro();
    std::string getISBN() const;
    ~Libro(){}


  bool operator==(const Libro &libro) const;
  unsigned operator%(size_t number) const;
  int operator%(int number) const;
  long operator/(const int number) const;
  
  Libro &operator=(const Libro &libro);
  Libro &operator=(const long &number);

  friend std::ostream &operator<<(std::ostream &os, const Libro &libro);
  friend std::istream &operator>>(std::istream &is, Libro &libro);

  operator long() const ;
    
};

Libro::Libro(std::string ISBN) {
    this->ISBN = ISBN;
}

Libro::Libro() {
    this->ISBN = "";
}

std::string Libro::getISBN() const {
    return ISBN;
}

bool Libro::operator==(const Libro &libro) const {
    return this->ISBN == libro.ISBN;
}

unsigned Libro::operator%(size_t number) const {
    Libro libro = *this;
    return long(libro) % number;
}



long Libro::operator/(const int number) const {
    return std::stoi(this->ISBN) / number;
}

Libro &Libro::operator=(const Libro &libro) {
    this->ISBN = libro.ISBN;
    return *this;
}

Libro &Libro::operator=(const long &number) {
    this->ISBN = std::to_string(number);
    return *this;
}

// implementa el operador de conversion de libro a long 
// para que se pueda usar la funcion de dispersion por division
Libro::operator long() const {
    return std::stoi(this->ISBN);
}

std::ostream &operator<<(std::ostream &os, const Libro &libro) {
    os << libro.ISBN;
    return os;
}

std::istream &operator>>(std::istream &is, Libro &libro) {
    is >> libro.ISBN;
    return is;
}

#endif
