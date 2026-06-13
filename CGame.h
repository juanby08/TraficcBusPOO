#ifndef CGAME_H
#define CGAME_H

#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include "MGame.h"
#include <windows.h>
#include <string>
#include <vector>
#include <utility>
//#include "Game.h"
using namespace std;

// Nombre Clase
class CGame{
    //Atributos
    private: 
        bool win;
        MGame* level;
        VGame* display;
    
    //Métodos
    public:   
        //Getters
        HANDLE UserInput() const;
        CGame(MGame* level, VGame* display);
        void play();
        bool boarding();
};

#endif // CGAME_H