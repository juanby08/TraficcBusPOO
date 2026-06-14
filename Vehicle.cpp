#include "Vehicle.h"

Vehicle::Vehicle(
    int ID, 
    int color, 
    std::pair<int,int> location,
    int direction,
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
    currentPassengers(currentPassengers){}

// 1 = Green, 2 = Blue, 3 = Yellow, 4 = Red
int Vehicle::getColor() const{
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

// 1 = Up, 2 = Down, 3 = Left, 4 = Right
int Vehicle::getDirection() const{
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