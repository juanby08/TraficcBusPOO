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
        size),
    capacity(capacity),
    currentPassengers(0){}

int Bus::getCapacity() const{
    return capacity;
}    

int Bus::getCurrentPassengers() const{
    return currentPassengers;
}

bool Bus::isFull(){
    return currentPassengers == capacity;
}

bool Bus::boardPassenger(){
    if(isFull()){

        return false;
        
    }

    currentPassengers++;
    return true;
    
}