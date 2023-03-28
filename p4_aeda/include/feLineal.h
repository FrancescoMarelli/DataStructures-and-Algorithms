#ifndef FE_LINEAL_H
#define FE_LINEAL_H

template <class Key>
class FeLineal : public ExplorationFunction<Key> {

    public:
    unsigned operator()(const Key& key, const unsigned i) const {
        return i;
    }
};

#endif // FE_LINEAL_H