#ifndef MGAME_H
#define MGAME_H

#include <string>
#include <utility>
#include "globaldefinitions.h"
using namespace std;

class MGame{
    protected: 
        int level;
        bool finished;
        int busQuantity;
        int passengersQuantity;
    
    public:
        void loadLevel();

};
#endif // MGAME_H