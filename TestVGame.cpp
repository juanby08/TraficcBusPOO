#include "VGame.h"
#include "Grid.h"

int main()
{
    VGame text;
    text.DisplayText("Bienvenido a TrafficJam!");

    Grid grid(5, 5);

    VGame game;
    game.DisplayGame(grid);


    return 0;
}