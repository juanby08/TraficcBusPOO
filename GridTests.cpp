#include <iostream>
#include "Grid.h"
#include "Bus.h"
#include "Car.h"

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

int main()
{
    cout << "=== Test Constructor ===" << endl;

    Grid grid(8, 8);

    Bus bus1 (
        1,
        4, // 1 = Green, 2 = Blue, 3 = Yellow, 4 = Red
        {2, 3},
        1,// 1 = Up, 2 = Down, 3 = Left, 4 = Right
        3,
        4
    );    

    printBoard(grid);

    cout << "=== Test Vehicle UP ===" << endl;

    grid.addVehicle(bus1);

    printBoard(grid);

    cout << "=== Test Vehicle DOWN ===" << endl;

    Bus bus2 (
        2,
        4, // 1 = Green, 2 = Blue, 3 = Yellow, 4 = Red
        {1, 1},
        2,// 1 = Up, 2 = Down, 3 = Left, 4 = Right
        2,
        4
    );   

    grid.addVehicle(bus2);

    printBoard(grid);

    cout << "=== Test Vehicle LEFT ===" << endl;

    Bus bus3 (
        3,
        4, // 1 = Green, 2 = Blue, 3 = Yellow, 4 = Red
        {6, 6},
        3,// 1 = Up, 2 = Down, 3 = Left, 4 = Right
        3,
        4
    );   

    grid.addVehicle(bus3);

    printBoard(grid);

    cout << "=== Test Vehicle RIGHT ===" << endl;

    Bus bus4 (
        4,
        4, // 1 = Green, 2 = Blue, 3 = Yellow, 4 = Red
        {0, 0},
        4,// 1 = Up, 2 = Down, 3 = Left, 4 = Right
        2,
        4
    );   

    grid.addVehicle(bus4);

    printBoard(grid);

    std::cout<<std::endl;
    std::cout<<grid.checkPath(bus1)<<std::endl;
    std::cout<<grid.checkPath(bus2)<<std::endl;
    std::cout<<grid.checkPath(bus3)<<std::endl;
    std::cout<<grid.checkPath(bus4)<<std::endl;

    return 0;
}