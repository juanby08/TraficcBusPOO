#include "Bus.h"

Bus::Bus(
    int ID,
    Color color, 
    std::pair<int, int> location,
    Direction direction,
    int size,
    int capacity) 
    : Vehicle(
        ID, 
        color, 
        location,
        direction,
        size,
        capacity,
        0){}

VehicleType Bus::getType() const{
    return VehicleType::BUS;
}