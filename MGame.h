#ifndef MGAME_H
#define MGAME_H

#include <string>
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