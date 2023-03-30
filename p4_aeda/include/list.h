#ifndef LIST_H
#define LIST_H

#include <list>

#include "sequence.h"

template <class Key>
class List : public Sequence<Key> {
    private:
    std::list<Key> keys;

    public:
    unsigned getSize() const;
    bool insert(const Key& key);
    bool search(const Key& key) const;
    bool isFull() const;
    void print() const;
    void write(std::ostream& os) const ;

};

template <class Key>
bool List<Key>::isFull() const {
    return false;
}

template <class Key>
unsigned List<Key>::getSize() const {
    return std::distance(keys.begin(), keys.end());
}

template <class Key>
bool List<Key>::insert(const Key& key) {
    if(search(key)){
        return false;
    } else {
    //keys.push_front(key);
    keys.push_back(key);
    return true;
    }
}

template <class Key>
bool List<Key>::search(const Key& key) const {
    bool found = false;
    int iter = 0;
    for(typename std::list<Key>::const_iterator it = keys.begin(); it != keys.end(); it++) {
        iter++;
        if (*it == key) {
            found = true;
            std::cout << "Iteraciones: " << iter << std::endl;
            return found;
        }
    }
    return found;
}

template <class Key>
void List<Key>::print() const {
    for(typename std::list<Key>::const_iterator it = keys.begin(); it != keys.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <class Key>
void List<Key>::write(std::ostream& os) const {
    for(typename std::list<Key>::const_iterator it = keys.begin(); it != keys.end(); ++it) {
        os << *it << " ";
    }
}

#endif // LIST_H	
