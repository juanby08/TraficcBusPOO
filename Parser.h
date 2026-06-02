#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "globaldefinitions.h"

using namespace std;

class Parser {
    public:
    // Método para convertir una cadena a un objeto
    static Color stringToColor(string colorStr);
    static Direction stringToDirection(string dirStr);
};

#endif