#include "Bus.h"

Bus::Bus(
    int ID,
    int color, 
    std::pair<int, int> location,
    int direction,
    int size,
    int currentPassengers) 
    : Vehicle(
        ID, 
        color, 
        location,
        direction,
        size,
        size == 2 ? 6:8,
        currentPassengers){}

std::string Bus::getType() const{
    return "bus";
}