#ifndef PASSENGER_H
#define PASSENGER_H

#include "Color.h"

class Passenger {
private:
    Color color;

public:
    Passenger();
    Passenger(Color auxColor);

    Color getColor() const;
};

#endif