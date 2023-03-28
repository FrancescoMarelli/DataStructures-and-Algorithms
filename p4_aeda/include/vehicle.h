#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>

template <class Key>
class Vehicle {
    private:
        std::string plate;
        Key k_plate;
    public:
    Vehicle(const std::string& plate) : plate(plate) {}
    std::string getPlate() const { return plate; }
    long toKey() const;
};

template <class Key>
long Vehicle<Key>::toKey() const {
    long key = 0;
    for (unsigned i = 0; i < plate.length(); i++) {
        key += plate[i];
    }
    k_plate = key;
    return key;
}



#endif // _VEHICLE_H_