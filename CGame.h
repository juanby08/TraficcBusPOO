#ifndef CGAME_H
#define CGAME_H

#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include "MGame.h"
#include "VGame.h"
#include <windows.h>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// Definición de la clase CGame
class CGame {
    // Atributos
    private: 
        bool win;
        MGame* level;
        VGame* display;
    
    // Métodos
    public:   
        CGame(MGame* level, VGame* display);
        
        // Getters 
        HANDLE getConsoleHandle() const; // Se usa para obtener el handle de la consola y configurar entrada (input) para leer eventos de teclado
        string readUserInput() const; // Se usa para leer el teclado y retornar un string con la tecla presionada
        
        void play();
        bool boarding();
};

#endif // CGAME_H