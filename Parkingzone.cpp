#include "ParkingZone.h"

ParkingZone::ParkingZone() {
    row = 0;
    columns = 4;

    cout << "ParkingZone creada." << endl;
    cout << "Fila: " << row << endl;
    cout << "Columnas: " << columns << endl;
}

ParkingZone::ParkingZone(int auxRow, int auxColumns) {
    row = auxRow;
    columns = auxColumns;

    cout << "ParkingZone creada." << endl;
    cout << "Fila: " << row << endl;
    cout << "Columnas: " << columns << endl;
}

bool ParkingZone::columnFree() {
    return parkedBuses.size() < columns;
}

bool ParkingZone::addBus(Bus* bus) {

    if (!columnFree())
        return false;

    parkedBuses.push_back(bus);
    return true;
}

bool ParkingZone::removeBus(int busID) {

    for (auto it = parkedBuses.begin(); it != parkedBuses.end(); ++it) {

        if ((*it)->getID() == busID) {
            parkedBuses.erase(it);
            return true;
        }
    }

    return false;
}