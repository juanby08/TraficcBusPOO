#ifndef VGAMEB_H
#define VGAMEB_H

#include "MGame.h"
#include <string>

class VGame {
private:
    // ANSI color codes for different colors. Reset goes back to original console print color.
    const std::string reset = "\033[0m";
    const std::string green = "\033[32m";   //  green = 1
    const std::string blue = "\033[34m";    //  blue = 2
    const std::string yellow = "\033[33m";  //  yellow = 3
    const std::string red = "\033[31m";     //  red = 4

    std::string getColorCode(int colorNum) const;
    int getVehicleColorAt(MGame& game, int r, int c, char cell) const;

public:

    VGame() = default;

    void printBoard(MGame& game);
    void DisplayText(const std::string& text);
    void printParkingZone(MGame& game);
    void printPassengerQueue(MGame& game);
};

#endif // VGAMEB_H