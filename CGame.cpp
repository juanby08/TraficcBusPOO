#include "MGame.h"
#include "VGame.h"
#include <iostream>

int main() {
    MGame game(1);
    game.loadLevel("Level1.txt");

    VGame view;

    // Aquí "renderizamos" el frame completo del juego
    view.printBoard(game);
    view.printParkingZone(game);
    view.printPassengerQueue(game);

    return 0;
}