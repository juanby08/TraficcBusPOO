#include "Vehicle.h"

Vehicle::Vehicle(
    int ID, 
    Color color, 
    std::pair<int,int> location,
    Direction direction,
    int size,
    int capacity,
    int currentPassengers
):
    ID(ID),
    color(color),
    location(location),
    direction(direction),
    size(size),
    capacity(capacity),
    currentPassengers(0){}

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

int Vehicle::getCapacity() const{
    return capacity;
}

int Vehicle::getCurrentPassengers() const{
    return currentPassengers;
}

bool Vehicle::isFull(){
    return currentPassengers == capacity;
}

bool Vehicle::boardPassenger(){
    if(isFull()){
        return false;
    }
    currentPassengers++;
    return true;
}