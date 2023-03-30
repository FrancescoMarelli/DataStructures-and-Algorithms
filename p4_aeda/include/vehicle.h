#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>

class Vehicle {
    private:
        std::string plate;
        std::string brand;


    public:
    Vehicle(const std::string brand, const std::string& plate) : brand(brand), plate(plate) {}
    std::string getPlate() const { return plate; }
    long toKey() const;
    Vehicle operator%(const Vehicle& v) const;
    bool operator==(const Vehicle& v) const;
    std::string getBrand() const { return brand; }
};

long Vehicle::toKey() const {
    long key = 0;
    for (unsigned i = 0; i < plate.length(); i++) {
        key += plate[i];
    }
    return key;
}

bool operator==(const Vehicle& v1, const Vehicle& v2) {
    return ((v1.getPlate() == v2.getPlate()) && (v1.getBrand() == v2.getBrand()));
}



#endif // _VEHICLE_H_