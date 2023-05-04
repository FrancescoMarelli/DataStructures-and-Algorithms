#ifndef ABB_H
#define ABB_H

#include <iostream>

/**
 * @brief Clase ABB
 * @details Clase que representa un árbol binario de búsqueda
 * @tparam Key Tipo de this->getDato() de los elementos del árbol
 */
template <class Key>
class ABB : public AB<Key> {

    public:

    ABB() : AB<Key>() {}
    ~ABB() {}

    bool insertar(const Key&) override;
    bool buscar(const Key&) const override;

    protected:
    bool insertarRama(NodoB<Key>*&, const Key&);
    bool buscarRama(NodoB<Key>*, const Key&) const;

};

#include "AVL.h"

/**
 * @brief 
 * 
 * @tparam Key 
 * @param this->getDato() 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::insertar(const Key& k) {
  if(this->getRaiz() == NULL) {
    this->SetRaiz(new NodoB<Key>(k,nullptr,nullptr));
    return true;
  } 
    return insertarRama(this->getRaiz(), k);
}

/**
 * @brief 
 * 
 * @tparam Key 
 * @param this->getDato() 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::buscar(const Key& k) const {
  return buscarRama(this->getRaiz(), k);
}

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 * @param this->getDato() 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::insertarRama(NodoB<Key>*& nodo, const Key& k) {
    if (nodo->getDato() == k) return false;
    if(k < nodo->getDato()) {
    if(nodo->getIzdo() == NULL) {
        nodo->setIzdo(new NodoB<Key>(k,nullptr,nullptr));
        return true;
    } else {
        return insertarRama(nodo->getIzdo(), k);
    }
  } else {
        if(nodo->getDcho() == NULL) {
            nodo->setDcho(new NodoB<Key>(k,nullptr,nullptr));
            return true;
        } else {
            return insertarRama(nodo->getDcho(), k);
        }
    }
}

    

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 * @param this->getDato() 
 * @return true 
 * @return false 
 */
template <class Key>
bool ABB<Key>::buscarRama(NodoB<Key>* nodo, const Key& k) const {
    if(nodo == nullptr) return false;
    if(k == nodo->getDato()) return true;
    if(k < nodo->getDato()) return buscarRama(nodo->getIzdo(), k);
    return buscarRama(nodo->getDcho(), k);
}

#endif