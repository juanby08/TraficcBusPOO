/* Curso: Fundamentos de Programación Orientada a Objetos
 Archivo: MGame.cpp
 Autores:
 - Anyela Lineth Cabrera Ordoñez | Código: 202540031| anyela.cabrera@correounivalle.edu.co
*/

#include "MGame.h"
#include <iostream>
#include <fstream>

using namespace std;

//Constructor
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
        std::string error = "Error: No se pudo abrir " + filePath + "\n";
        return;
    }
    // Temporal var to save information
    int rows, columns, parkingSpots;
    file >> rows >> columns >> parkingSpots; 

    //creates grid
    grid = std::make_unique<Grid>(columns, rows);

    //creates parkingZone
    parkingZone = std::make_unique<ParkingZone>(rows, parkingSpots);

    //Creating Temporary Variables
    string typeStr;
    int x, y, size, capacity, currentPassengers, vehicleColor, vehicleDir, passengerColor, isParked;

    // While loop goes until it finds "-"
    while (file >> typeStr && typeStr != "-") {
        file >> vehicleColor >> x >> y >> vehicleDir >> size >> currentPassengers >> isParked;

        //Create vehicle with nullptr
        Vehicle* vehicle = nullptr;

        // Creates an object of the corresponding type
        if (typeStr == "BUS") {
            vehicle = new Bus(vehicleQuantity, vehicleColor, {x, y}, vehicleDir, size, currentPassengers);
        } 
        else if (typeStr == "CAR") {
            vehicle = new Car(vehicleQuantity, vehicleColor, {x, y}, vehicleDir, currentPassengers);
        }

        // Check if vehicle is different from nullptr to proceed
        if (vehicle != nullptr){
            vehicles.push_back(vehicle);
            vehicleQuantity++;

            // Vehicle goes to parking zone
            if (isParked == 1){
                parkingZone->addBus(vehicle);
            } 
            // Vehicle gets added to the grid
            else {
                grid->addVehicle(*vehicle);
            }
        }
    
    }

    // Creates new Passengers and adds them to the corresponding vector
    while (file >> passengerColor) {
        passengerQueue.push_back(new Passenger(passengerColor));
        passengersQuantity++;
    }

    file.close();
}

void MGame::removeVehicle(int vehicleID) {
    // Iterate over vehicles vector from first until last element.
    for(auto i = vehicles.begin(); i != vehicles.end(); ++i){
        // Dereference i iterator to get a vehicle pointer (Vehicle*), use -> operator to access getID method.
        if((*i)->getID() == vehicleID){
            // Takes the iterator and deletes de slot containing the Vehicle pointer.
            vehicles.erase(i);
            break;
        }
    };
}

int MGame::getVehicleQuantity() const{
    return vehicleQuantity;
}

int MGame::getPassengersQuantity() const{
    return passengerQueue.size();
}

int MGame::getLevel() const{
    return level;
}

Grid& MGame::getGrid() {
    return *grid;
}

std::vector<Vehicle*> MGame::getVehicles() const{
    return vehicles;
}

std::vector<Passenger*>& MGame::getPassengers(){
    return passengerQueue;
}

ParkingZone& MGame::getParkingZone() const{
    return *parkingZone;
}