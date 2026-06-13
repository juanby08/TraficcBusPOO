#ifndef MGAME_H
#define MGAME_H

#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include <string>
#include <vector>
#include <utility>
//#include "Game.h"
using namespace std;

// Nombre Clase
class MGame{
    //Atributos
    private: 
        std::vector<Vehicles> vehicles;
        std::vector<Passengers> passengers;
        Grid* grid;
        ParkingZone parkingZone;
    
    //Métodos
    public:
        MGame(); //constructor

        //Getters
        std::vector<Vehicles> getVehicles() const;
        std::vector<Passengers> getPassengers() const;
        Grid createBoard() const;
        ParkingZone getParkingZone() const;

        // Método que recibe el nombre del archivo txt
        void loadLevel(string filePath);
};

#endif // MGAME_H