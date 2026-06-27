// Curso: Fundamentos de Programacion Orientada a Objetos
// Archivo: Parkingzone.cpp
// Autores:
// - Juan Ricardo Riaños Horta | Código: 2537573 | juan.rianos@correounivalle.edu.co
// - Carlos Anibal Ceron del Castillo | Código: 2537097 | carlos.ilich.ceron@correounivalle.edu.co
// - Anyela Lineth Cabrera Ordoñez | Código: 2540031 | anyela.cabrera@correounivalle.edu.co
// - Camilo Espinal León | Código: 2538740 | camilo.espinal@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 27/06/2026

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

std::vector<Vehicle*> ParkingZone::getParkedBuses() const{
    return parkedBuses;
}