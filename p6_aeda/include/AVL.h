#ifndef AVL_H
#define AVL_H


#include <iostream>
#include "NodoAVL.h"

/**
 * @brief Clase AVL
 * @details Clase que representa un árbol binario de búsqueda AVL
 * @tparam Key Tipo de dato de los elementos del árbol
 */
template <class Key>
class AVL : public ABB<Key> {


    public:

    AVL() : ABB<Key>() {}
    ~AVL() {}	

    bool insertar(const Key&) override;
    bool buscar(const Key&) const override;

    protected:
    NodoAVL<Key> *getRoot() const {return reinterpret_cast<NodoAVL<Key>*>(this->getRaiz());}
    NodoAVL<Key> *&getRoot() {return reinterpret_cast<NodoAVL<Key>*&>(this->getRaiz());}
   
    void insert_bal(NodoAVL<Key>*& nodo, NodoAVL<Key>* k, bool& crece, bool& introduce);
    void insert_rebalance_izda(NodoAVL<Key>*& nodo, bool& crece);
    void insert_rebalance_dcha(NodoAVL<Key>*& nodo, bool& crece);

    bool buscarRama(NodoAVL<Key>*, const Key&) const;

    void RotacionII(NodoAVL<Key> *& );
    void RotacionDD(NodoAVL<Key> *& );
    void RotacionID(NodoAVL<Key> *& );
    void RotacionDI(NodoAVL<Key> *& );

};

/**
 * @brief 
 * 
 * @tparam Key 
 * @param this->getDato() 
 * @return true 
 * @return false 
 */

template <class Key>
bool AVL<Key>::insertar(const Key& k) {
  bool crece = false;
  bool introduce = false;
  NodoAVL<Key>* nuevo = new NodoAVL<Key>(k);
  insert_bal(getRoot(), nuevo, crece, introduce);
    return introduce;
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
void AVL<Key>::insert_bal(NodoAVL<Key>*& nodo, NodoAVL<Key>* k, bool& crece, bool& introduce) { 
    if(nodo == NULL) {
        nodo = k;
        crece = true;
        introduce = true;
    }
    if(nodo->getDato() == k->getDato()) {
       return;
    } else if (k->getDato() < nodo -> getDato()) {
        insert_bal(nodo->getIzdoAVL(), k, crece, introduce);
        if(crece) insert_rebalance_izda(nodo, crece);
    } else {
            insert_bal(nodo->getDchoAVL(), k, crece, introduce);
            if(crece) insert_rebalance_dcha(nodo, crece);
        }

    }

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 * @param crece 
 */
template <class Key>
void AVL<Key>::insert_rebalance_izda(NodoAVL<Key>* &nodo, bool& crece) {
    switch (nodo->getBal()) {
    case -1:
        nodo->setBal(0);
        crece = false;
        break;
    case 0:
        nodo->setBal(1);
        break;
    case 1:
    NodoAVL<Key>* aux = nodo->getIzdoAVL();
    if(aux->getBal() == 1) {
        RotacionII(nodo);
    } else {
        RotacionID(nodo);
    }
    crece = false;
    break;
    }
}


/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 * @param crece 
 */
template <class Key>
void AVL<Key>::insert_rebalance_dcha(NodoAVL<Key>* &nodo, bool& crece) {
    switch (nodo->getBal()) {
    case 1:
        nodo->setBal(0);
        crece = false;
        break;
    case 0:
        nodo->setBal(-1);
        break;
    case -1:
    NodoAVL<Key>* aux = nodo->getDchoAVL();
    if(aux->getBal() == -1) {
        RotacionDD(nodo);
    } else {
        RotacionDI(nodo);
    }
    crece = false;
    break;
    }
}

/**
 * @brief 
 * 
 * @tparam Key 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool AVL<Key>::buscar(const Key& k) const {
  return buscarRama(this->getRoot(), k);
}

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 * @param k 
 * @return true 
 * @return false 
 */
template <class Key>
bool AVL<Key>::buscarRama(NodoAVL<Key>* nodo, const Key& k) const {
    if(nodo == NULL) return false;
    if(nodo->getDato() == k) return true;
    if(k < nodo->getDato())  return buscarRama(nodo->getIzdoAVL(), k);
    return buscarRama(nodo->getDchoAVL(), k);
}

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 */
template <class Key>
void AVL<Key>::RotacionII(NodoAVL<Key>*& nodo) {

    std::cout << "Desbalanceo " << std::endl;
    this->operator>>(std::cout);
    std::cout << "Rotación II sobre [" << nodo->getDato() << "]"<< std::endl;
    
    // 
    NodoAVL<Key>* aux = nodo->getIzdoAVL();
    nodo->setIzdo(aux->getDcho());
    aux->setDcho(nodo);

    if(aux->getBal() == 1) {
        nodo->setBal(0);
        aux->setBal(0);
    } else {
        nodo->setBal(1);
        aux->setBal(-1);
    }
    nodo = aux;
}

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 */
template <class Key>
void AVL<Key>::RotacionDD(NodoAVL<Key>* &nodo) {
        
            std::cout << "Desbalanceo" << std::endl;
            this->operator>>(std::cout);
            std::cout << "Rotación DD sobre [" << nodo->getDato() << "]"<< std::endl;
            
            NodoAVL<Key>* aux = nodo->getDchoAVL();
            nodo->setDcho(aux->getIzdoAVL());
            aux->setIzdo(nodo);
            
            if(aux->getBal() == -1) {
                nodo->setBal(0);
                aux->setBal(0);
            } else {
                nodo->setBal(-1);
                aux->setBal(1);
            }
            nodo = aux;
}

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 */
template <class Key>
void AVL<Key>::RotacionID(NodoAVL<Key>* &nodo) {
    
        std::cout << "Desbalanceo" << std::endl;
        this->operator>>(std::cout);
        std::cout << "Rotación ID sobre [" << nodo->getDato() << "]"<< std::endl;
        
        NodoAVL<Key>* aux = nodo->getIzdoAVL();
        NodoAVL<Key>* aux2 = aux->getDchoAVL();
        nodo->setIzdo(aux2->getDchoAVL());
        aux2->setDcho(nodo);
        aux->setDcho(aux2->getIzdoAVL());
        aux2->setIzdo(aux);
        if(aux2->getBal() == -1) {
            nodo->setBal(1);
        } else {
            nodo->setBal(0);
        }
        if(aux2->getBal() == 1) {
            aux->setBal(-1);
        } else {
            aux->setBal(0);
        }
        aux2->setBal(0);
        nodo = aux2;
}

/**
 * @brief 
 * 
 * @tparam Key 
 * @param nodo 
 */
template <class Key>
void AVL<Key>::RotacionDI(NodoAVL<Key>* &nodo) {
        
            std::cout << "Desbalanceo " << std::endl;
            this->operator>>(std::cout);
            std::cout << "Rotación DI sobre [" << nodo->getDato() << "]"<< std::endl;
            
            NodoAVL<Key>* aux = nodo->getDchoAVL();
            NodoAVL<Key>* aux2 = aux->getIzdoAVL();
            nodo->setDcho(aux2->getIzdoAVL());
            aux2->setIzdo(nodo);
            aux->setIzdo(aux2->getDchoAVL());
            aux2->setDcho(aux);

            if(aux2->getBal() == 1) {
                nodo->setBal(-1);
            } else {
                nodo->setBal(0);
            }
            if(aux2->getBal() == -1) {
                aux->setBal(1);
            } else {
                aux->setBal(0);
            }
            aux2->setBal(0);
            nodo = aux2;
}

#endif

