#ifndef VGAME_H
#define VGAME_H

#include "MGame.h"
#include <string>

class VGame {
private:
    // Códigos ANSI para colores de texto en consola
    const std::string reset = "\033[0m";
    const std::string green = "\033[32m";  // 1
    const std::string blue = "\033[34m";  // 2
    const std::string yellow = "\033[33m";  // 3
    const std::string red = "\033[31m";  // 4

    // Métodos auxiliares privados
    std::string getColorCode(int colorNum) const;
    int getVehicleColorAt(MGame& game, int r, int c, char cell) const;

public:
    VGame() = default;

    // Método principal de renderizado (se ejecuta una sola vez por llamada)
    void printBoard(MGame& game);
    void DisplayText(const std::string& text);
    void printParkingZone(MGame& game);
    void printPassengerQueue(MGame& game);
};

#endif // VGAME_H