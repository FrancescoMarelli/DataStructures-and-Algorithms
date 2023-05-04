#ifndef NODOAVL_H
#define NODOAVL_H

#include <iostream>

/**
 * @brief Clase NodoAVL
 * @details Clase que representa un nodo de un árbol binario de búsqueda AVL
 * @tparam Key Tipo de dato de los elementos del árbol
 */
template <class Key>
class NodoAVL : public  NodoB<Key> {

    public:
    NodoAVL(const Key& k, NodoAVL<Key>* izdo = nullptr, NodoAVL<Key>* dcho = nullptr) : NodoB<Key>(k, izdo, dcho), bal(0) {}
    
    Key getBal() const { return bal; }
    
    NodoAVL<Key>* getIzdoAVL() const { return reinterpret_cast<NodoAVL<Key>*>(this->getIzdo()); }
    NodoAVL<Key>*& getIzdoAVL() { return reinterpret_cast<NodoAVL<Key>*&>(this->getIzdo()); }
    NodoAVL<Key>* getDchoAVL() const { return reinterpret_cast<NodoAVL<Key>*>(this->getDcho()); }
    NodoAVL<Key>*& getDchoAVL() { return reinterpret_cast<NodoAVL<Key>*&>(this->getDcho()); }
    
    
    void setBal(int bal) { this->bal = bal; }

    private:
    int bal;

};


#endif