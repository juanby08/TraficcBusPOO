#ifndef BUS_H
#define BUS_H

#include <string>
#include <utility>
#include "globaldefinitions.h"
#include "Vehicle.h"

    class Bus : public Vehicle {
    private:

        int capacity;
        int currentPassengers;

    public: 

        Bus(int ID, Color color, std::pair<int,int> location, Direction direction, int size, int capacity);
        int getCapacity() const;
        int getCurrentPassengers() const;
        bool isFull();
        bool boardPassenger();

    };
#endif // BUS_H