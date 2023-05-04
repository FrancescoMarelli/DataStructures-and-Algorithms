#ifndef NODOB_H
#define NODOB_H

#include <iostream>

/**
 * @brief Clase NodoB
 * @details Clase que representa un nodo de un árbol binario
 * @tparam Key Tipo de dato de los elementos del árbol
 */
template <class Key>
class NodoB {

    public:
    NodoB(const Key& dato, NodoB<Key>* izdo = nullptr, NodoB<Key>* dcho = nullptr) : dato(dato), izdo(izdo), dcho(dcho) {}
    ~NodoB() {}

    //getters
    Key getDato() const { return dato; }
    NodoB<Key>* getIzdo() const { return izdo; }
    NodoB<Key>* getDcho() const { return dcho; }
    NodoB<Key>*& getIzdo() { return izdo; }
    NodoB<Key>*& getDcho() { return dcho; }

    //setters
    void setDato(Key& dato) { this->dato = dato; }
    void setIzdo(NodoB<Key>* izdo) { this->izdo = izdo; }
    void setDcho(NodoB<Key>* dcho) { this->dcho = dcho; }

    protected:
    Key dato;
    NodoB<Key>* izdo;
    NodoB<Key>* dcho;

};

#include "NodoAVL.h"

#endif

