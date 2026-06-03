#include "Car.h"

Car::Car(
    int ID, 
    Color color, 
    std::pair<int, int> location,
    Direction direction)
    : Vehicle (
    ID,
    color,
    location,
    direction,
    2,
    4,
    0){}

VehicleType Car::getType() const{
    return VehicleType::CAR;
}