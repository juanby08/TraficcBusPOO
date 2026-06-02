#include "Vehicle.h"

#ifndef CAR_H
#define CAR_H

class Car : public Vehicle {
    
    public:
        Car(int ID, Color color, std::pair<int, int> location, Direction direction);
    
};

#endif // CAR_H