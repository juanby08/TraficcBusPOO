#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

    class Bus : public Vehicle {

    public: 

        Bus(
            int ID, 
            Color color, 
            std::pair<int,int> location, 
            Direction direction, 
            int size, 
            int capacity
        );

        VehicleType getType() const override;

    };
#endif // BUS_H