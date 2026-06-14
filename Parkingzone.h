#ifndef PARKINGZONE_H
#define PARKINGZONE_H

#include <vector>
#include "Vehicle.h"

class ParkingZone {
private:
    std::vector<Vehicle*> parkedBuses;

    int row;
    int columns;

public:
    ParkingZone(int row, int columns);

    bool columnFree();

    bool addBus(Vehicle* vehicle);
    bool removeBus(int vehicleID);

    void showParking();

    //getters
    std::vector<Vehicle*> getParkedBuses() const;

};

#endif