#ifndef SEQUENCE_H
#define SEQUENCE_H

template <class Key>
class Sequence {

    public:
    virtual bool search(const Key& key) const = 0;
    virtual bool insert(const Key& key) = 0;
    virtual bool isFull() const = 0;
    virtual void print() const = 0;
    virtual void write(std::ostream& os) const = 0;
};

#include "list.h"
#include "block.h"



#endif // SEQUENCE_H