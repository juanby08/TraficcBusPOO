#include "Passenger.h"



Passenger::Passenger() {
    color = Color::Red;
}

Passenger::Passenger(Color auxColor) {
    color= auxColor;
}

Color Passenger::getColor() const {
    return color;
}