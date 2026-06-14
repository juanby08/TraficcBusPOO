#include "Car.h"

Car::Car(
    int ID, 
    int color, 
    std::pair<int, int> location,
    int direction,
    int currentPassengers)
    : Vehicle (
    ID,
    color,
    location,
    direction,
    2,
    4,
    currentPassengers){}

std::string Car::getType() const{
    return "Car";
}