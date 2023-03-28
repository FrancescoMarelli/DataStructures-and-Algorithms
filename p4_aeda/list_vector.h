#ifndef LIST_H
#define LIST_H

#include "sequence.h"

template <class Key>
class List : public Sequence<Key> {
    private:
    std::vector<Key> keys;

    public:
    unsigned getSize() const;
    bool insert(const Key& key);
    bool search(const Key& key) const;
    bool isFull() const;
    void print() const;
};

template <class Key>
bool List<Key>::isFull() const {
    return false;
}


template <class Key>
unsigned List<Key>::getSize() const {
    return keys.size();
}

template <class Key>
bool List<Key>::insert(const Key& key) {
    if(search(key)){
        return false;
    } else {
    keys.push_back(key);
    return true;
    }
}

template <class Key>
bool List<Key>::search(const Key& key) const {
    bool found = false;
    for(unsigned i = 0; i < keys.size(); i++) {
        if (keys[i] == key) {
            found = true;
            return found;
        }
    }
    return found;
}

template <class Key>
void List<Key>::print() const {
    for(unsigned i = 0; i < keys.size(); i++) {
        std::cout << keys[i] << " ";
    }
    std::cout << std::endl;
}

#endif // LIST_H	
