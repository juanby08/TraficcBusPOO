#ifndef PARKINGZONE_H
#define PARKINGZONE_H

#include <vector>
#include "Passenger.h"
#include "Bus.h"

using namespace std;

class ParkingZone {
private:
    vector<Passenger> passengerQueue;
    vector<Bus*> parkedBuses;

    int row;
    int columns;

public:
    ParkingZone();
    ParkingZone(int auxRow, int auxColumns);

    bool columnFree();

    bool addBus(Bus* bus);
    bool removeBus(int busID);
};

#endif