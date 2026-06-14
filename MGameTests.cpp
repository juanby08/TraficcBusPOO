#include "MGame.h"
#include <cassert>
#include <iostream>

using namespace std;

void printBoard(Grid& grid)
{
    vector<vector<char>> board = grid.getBoard();

    for (const auto& row : board)
    {
        for (char cell : row)
        {
            cout << cell << ' ';
        }
        cout << endl;
    }

    cout << endl;
}

void testLoadLevel()
{
    MGame game(1);

    game.loadLevel("Level1.txt");

    assert(game.getLevel() == 1);
    assert(game.getBusQuantity() == 2);
    assert(game.getPassengersQuantity() == 5);

    cout << "testLoadLevel PASSED" << endl;
}

void testBoardSize()
{
    MGame game(1);

    game.loadLevel("Level1.txt");

    Grid& grid = game.getGrid();

    cout << "testBoardSize PASSED" << endl;
}

void testPrintInitialBoard()
{
    MGame game(1);

    game.loadLevel("Level1.txt");

    Grid& grid = game.getGrid();

    cout << endl;
    cout << "TABLERO INICIAL" << endl;

    printBoard(grid);
}

void testBusHeadPosition()
{
    MGame game(1);

    game.loadLevel("Level1.txt");

    Grid& grid = game.getGrid();

    vector<vector<char>> board = grid.getBoard();

    assert(board[0][0] == '.');

    cout << "testBusHeadPosition PASSED" << endl;
}

int main()
{
    testLoadLevel();
    testBoardSize();
    testPrintInitialBoard();
    cout << endl;
    cout << "TODOS LOS TESTS FINALIZADOS" << endl;

    return 0;
}