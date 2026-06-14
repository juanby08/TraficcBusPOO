#include "ParkingZone.h"
#include <iostream>

ParkingZone::ParkingZone(int auxRow, int auxColumns) {
    row = auxRow;
    columns = auxColumns;

    parkedBuses.resize(columns, nullptr);
}

//metodo para revisar si parkingZone está vacio
bool ParkingZone::columnFree() {
    for (int i = 0; i < parkedBuses.size(); i++) {
        if (parkedBuses[i] == nullptr) { //verifica que haya espacio
            return true;
        }
    }
    return false;
}

//Añadir vehiculo al parkingZone
bool ParkingZone::addBus(Vehicle* vehicle) {
    for (int i = 0; i < parkedBuses.size(); i++) {
        if (parkedBuses[i] == nullptr) {
            parkedBuses[i] = vehicle;
            return true;
        }
    }
    return false;
}

//Quitar un vehículo al parkingZone
bool ParkingZone::removeBus(int vehicleID) {
    for (int i = 0; i < parkedBuses.size(); i++) {
        //Si hay un vehiculo y ese coincide con el ID del que se necesita, se borra
        if (parkedBuses[i] != nullptr && parkedBuses[i]->getID() == vehicleID) {
            parkedBuses[i] = nullptr;
            return true;
        }
    }

    return false;
}

//solo para mostrar el test visual
void ParkingZone::showParking() {
    std::cout << "[ ";
    for (int i = 0; i < parkedBuses.size(); i++) {
        if (parkedBuses[i] == nullptr) {
            std::cout << "Empty ";
        }
        else {
            std::cout << parkedBuses[i]->getID() << " ";
        }
    }

    std::cout << "]\n";
}