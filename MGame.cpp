/* Curso: Fundamentos de Programación Orientada a Objetos
 Archivo: MGame.cpp
 Autores:
 - Anyela Lineth Cabrera Ordoñez | Código: 202540031| anyela.cabrera@correounivalle.edu.co
*/

#include "MGame.h"
#include <iostream>
#include <fstream>

using namespace std;

MGame::MGame(int level) : level(level) {
    vehicleQuantity = 0;
    passengersQuantity = 0;
}

void MGame::loadLevel(string filePath) {
    std::string loading = "Cargando nivel " + filePath + "... \n";
    // Open the text file containing the level information.
    ifstream file(filePath);
    // Condition to verify if the file was opened correctly
    if (!file.is_open()) {
        std::string error = "Error: No se pudo abrir " + filePath + "\n"; //Check SRP
        return;
    }
    // Temporal var to save information
    int rows, columns, parkingSpots;
    file >> rows >> columns >> parkingSpots; 

    //creates grid
    grid = std::make_unique<Grid>(columns, rows);

    //creates parkingZone
    parkingZone = std::make_unique<ParkingZone>(rows, parkingSpots);

    string typeStr;
    int x, y, size, capacity, currentPassengers, vehicleColor, vehicleDir, passengerColor, isParked;

    // Leer los vehículos hasta encontrar el "-"
    while (file >> typeStr && typeStr != "-") {
        file >> vehicleColor >> x >> y >> vehicleDir >> size >> currentPassengers >> isParked;

        //Create vehicle with nullptr
        Vehicle* vehicle = nullptr;

        // Instanciar los objetos y agregarlos al vector de vehículos
        if (typeStr == "BUS") {
            // El constructor de Bus pide capacidad. Le pasamos 4 por defecto.
            vehicle = new Bus(vehicleQuantity, vehicleColor, {x, y}, vehicleDir, size, currentPassengers);
        } 
        else if (typeStr == "CAR") {
            vehicle = new Car(vehicleQuantity, vehicleColor, {x, y}, vehicleDir, currentPassengers);
        }

        if (vehicle != nullptr){
            vehicles.push_back(vehicle);
            vehicleQuantity++;

            if (isParked == 1){
                parkingZone->addBus(vehicle);
            } 
            else {
                grid->addVehicle(*vehicle);
            }
        }
    
    }

    // Bucle para leer la fila de pasajeros y guardarla en la cola
    while (file >> passengerColor) {
        passengerQueue.push_back(new Passenger(passengerColor));
        passengersQuantity++;
    }

    std::string levelStatus = "Nivel cargado exitosamente.\n";
    cout << "Vehiculos creados: " << vehicleQuantity << endl;
    cout << "Pasajeros en fila: " << passengersQuantity << endl;

    //Check for condition
    
    // for (auto vehicle: vehicles){
    //     grid->addVehicle(*vehicle);
    // }
    cout << "Nivel cargado exitosamente.2" << endl;

    file.close();
}

int MGame::getVehicleQuantity() const
{
    return vehicleQuantity;
}

int MGame::getPassengersQuantity() const
{
    return passengersQuantity;
}

int MGame::getLevel() const
{
    return level;
}

Grid& MGame::getGrid() const{
    return *grid;
}

std::vector<Vehicle*> MGame::getVehicles() const{
    return vehicles;
}


std::vector<Passenger*> MGame::getPassengers() const{
    return passengerQueue;
}

ParkingZone& MGame::getParkingZone() const{
    return *parkingZone;
}