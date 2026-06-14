#ifndef MGAME_H
#define MGAME_H

#include "Vehicle.h"
#include "Grid.h"
#include "Passenger.h"
#include "Bus.h"
#include "Car.h"
#include "Parkingzone.h"
#include <string>
#include <vector>
#include <utility>
#include <memory>
using namespace std;

// Nombre Clase
class MGame{
    //Atributos
    private: 
        int level;
        int vehicleQuantity;
        int passengersQuantity;
        std::vector<Vehicle*> vehicles;
        std::vector<Passenger*> passengerQueue;
        std::unique_ptr<Grid> grid;
        std::unique_ptr<ParkingZone> parkingZone;
    
    //Métodos
    public:
        MGame(int level); //constructor

        //Getters
        int getLevel() const;
        int getVehicleQuantity() const;
        int getPassengersQuantity() const;
        Grid& getGrid() const;
        ParkingZone& getParkingZone() const;
        std::vector<Vehicle*> getVehicles() const;
        std::vector<Passenger*> getPassengers() const;

        // Método que recibe el nombre del archivo txt
        void loadLevel(string filePath);
};

#endif // MGAME_H