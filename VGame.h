#ifndef VGAME_H
#define VGAME_H

#include <string>
#include "Grid.h"

class VGame
{
public:
    void DisplayText(const std::string& text);
    void DisplayGame(Grid& grid);
};

#endif