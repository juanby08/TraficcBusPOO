#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger {
private:
    int color; // 1 = Green, 2 = Blue, 3 = Yellow, 4 = Red

public:
    Passenger(int auxColor);

    int getColor() const;
};

#endif