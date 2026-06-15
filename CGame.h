#ifndef CGAME_H
#define CGAME_H

#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include "MGame.h"
//#include <windows.h>
#include <string>
#include <vector>
#include <utility>
#include <thread>
#include <chrono>
#include "VGame.h"


class CGame {
    private: 

        int gameStatus;
        MGame* level;
        VGame* display;

        char handleInput();
    
    public:

        CGame(MGame* level, VGame* display);
        void updateGrid();
        int play();
        bool boarding();

};

#endif // CGAME_H