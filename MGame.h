#ifndef MGAME_H
#define MGAME_H

#include <string>
#include <utility>
//#include "Game.h"
using namespace std;

// Nombre Clase
class MGame{
    //Atributos
    protected: 
        int level;
        bool finished;
        int busQuantity;
        int passengersQuantity;
    
    //Metodos
    public:
        int getLevel() const;
        bool Finished() const;
        int getBusQuantity() const;
        int getPassengersQuantity() const;
        void loadLevel();
};

#endif // MGAME_H