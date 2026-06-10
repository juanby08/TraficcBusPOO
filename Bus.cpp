#include "Bus.h"

Bus::Bus(
    int ID,
    int color, 
    std::pair<int, int> location,
    int direction,
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