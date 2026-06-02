#include "Vehicle.h"

Vehicle::Vehicle(
    int ID, 
    Color color, 
    std::pair<int,int> location,
    Direction direction,
    int size
):
    ID(ID),
    color(color),
    location(location),
    direction(direction),
    size(size){}

Color Vehicle::getColor() const{
    return color;
}

int Vehicle::getID() const{
    return ID;
}

std::pair<int, int> Vehicle::getLocation() const{
    return location;
}

int Vehicle::getSize() const{
    return size;
}

Direction Vehicle::getDirection() const{
    return direction;
}