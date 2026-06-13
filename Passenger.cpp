#include "Passenger.h"

Passenger::Passenger(int auxColor) {
    color= auxColor;
}

int Passenger::getColor() const {
    return color;
}