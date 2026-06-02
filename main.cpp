#include <iostream>
#include "MGame.h"

int main() {
    MGame game;
    // Cargar el nivel desde el archivo plano
    game.loadLevel("level1.txt"); 
    return 0;
}
