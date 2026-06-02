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
        int level;
        bool finished;
        int busQuantity;
        int passengersQuantity;
        std::vector<Vehicle*> vehicles;
        std::vector<Color> passengerQueue;
    
    //Métodos
    public:
        MGame(); //constructor

        //Getters
        int getLevel() const;
        bool Finished() const;
        int getBusQuantity() const;
        int getPassengersQuantity() const;

        // Método que recibe el nombre del archivo txt
        void loadLevel(string filePath);
};

#endif // MGAME_H