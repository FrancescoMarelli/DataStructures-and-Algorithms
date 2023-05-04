#ifndef AB_H
#define AB_H

#include <iostream>
#include <queue>

#include "NodoB.h"

/**
 * @brief Clase AB
 * @details Clase que representa un árbol binario
 * @tparam Key Tipo de dato de los elementos del árbol
 */

template <class Key>
class AB {

    public:
    AB() : raiz(nullptr) {}
    virtual ~AB() {this->podar(getRaiz()); }

    
    virtual bool insertar(const Key& k ) = 0;
    virtual bool buscar(const Key& k) const = 0;

    void inorden() const;
    void preorden() const;
    void postorden() const;

    void podarArbol();

    std::ostream& operator>>(std::ostream& os);

    protected:
    // const porque no se puede modificar el puntero
    // y no puedo sobrecargar el otro getRaiz
    NodoB<Key>* getRaiz() const { return raiz; }
    NodoB<Key>*& getRaiz() { return raiz; }
    void SetRaiz(NodoB<Key>* raiz) { this->raiz = raiz; }


    private:
        void podar(NodoB<Key>*);
        void RecorreInorden(NodoB<Key>*) const;
        void RecorrePreorden(NodoB<Key>*) const;
        void RecorrePostorden(NodoB<Key>*) const;
        void getValue(const Key&) const;

        NodoB<Key>* raiz;
};

#include "ABB.h"

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 */
template <class Key>
void AB<Key>::podar( NodoB<Key>* nodo)  {
        if (nodo == nullptr) return;
        podar(nodo->getIzdo());
        podar(nodo->getDcho());
        delete nodo;
        nodo = nullptr;
}

/**
 * @brief 
 * 
 * @tparam Key 
 */
template <class Key>
void AB<Key>::podarArbol() {
    podar(this->getRaiz());
    this->SetRaiz(nullptr);
}

/**
 * @brief 
 * 
 * @tparam Key   
 */
template <class Key>
void AB<Key>::inorden() const {
    std::cout << "Inorden: ";
    RecorreInorden(this->getRaiz());
}

/**
 * @brief
 * 
 * @tparam Key
 * @param nodo
 */
template <class Key>
void AB<Key>::RecorreInorden(NodoB<Key>* nodo) const {
    if (nodo == nullptr) return;
    RecorreInorden(nodo->getIzdo());
    getValue(nodo->getDato());
    RecorreInorden(nodo->getDcho());
}

/**
 * @brief
 * 
 * @tparam Key
 * @param k
 */
template <class Key>
void AB<Key>::getValue(const Key& k) const {
    std::cout << k << " ";
}

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 */
template <class Key>
void AB<Key>::preorden() const {
    std::cout << "Preorden: ";
    RecorrePreorden(this->getRaiz());
}

/**
 * @brief
 * 
 * @tparam Key
 * @param nodo
 */
template <class Key>
void AB<Key>::RecorrePreorden(NodoB<Key>* nodo) const {
    if (nodo == nullptr) return;
    getValue(nodo->getDato());
    RecorrePreorden(nodo->getIzdo());
    RecorrePreorden(nodo->getDcho());
}

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 */
template <class Key>
void AB<Key>::postorden() const {
    std::cout << "Postorden: ";
    RecorrePostorden(this->getRaiz());
}

/**
 * @brief
 * 
 * @tparam Key
 * @param nodo
 */
template <class Key>
void AB<Key>::RecorrePostorden(NodoB<Key>* nodo) const {
    if (nodo == nullptr) return;
    RecorrePostorden(nodo->getIzdo());
    RecorrePostorden(nodo->getDcho());
    getValue(nodo->getDato());
}


/**
 * @brief 
 * 
 * @tparam Key 
 * @param os 
 * @return std::ostream 
 */
template <class Key>
std::ostream& AB<Key>::operator>>(std::ostream& os) {
  std::queue<std::pair<NodoB<Key>*, int>> Q;
  std::pair<NodoB<Key>*, int> aux_Q;
  NodoB<Key> *nodo;
  int nivel, Nivel_actual = 0;
  
  //Nodo raiz en la cola
  aux_Q.first = getRaiz();
  aux_Q.second = 0;
  Q.push(aux_Q);

  std::cout << "Nivel 0: ";  
  //Recorrido por niveles
  while (!Q.empty()) {
    aux_Q = Q.front();
    nodo = aux_Q.first;
    nivel = aux_Q.second;
    Q.pop();

    if(nivel > Nivel_actual) { //Incremento de nivel
      Nivel_actual = nivel;
      std::cout << "\nNivel " << Nivel_actual << ":";
    }  

    if(nodo != nullptr) {      
      std::cout << "[" << nodo->getDato() << "]";
      aux_Q.second = nivel + 1;
      aux_Q.first = nodo->getIzdo();
      Q.push(aux_Q);
      aux_Q.first = nodo->getDcho();
      Q.push(aux_Q);        
    }
    else {
      std::cout << "[.]";  //Subarbol vacío
    }    
  }
  std::cout << std::endl;


  return os;
}


#endif
