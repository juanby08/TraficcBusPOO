#include "MGame.h"
#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;

void printBoard(Grid& grid) {
    vector<vector<char>> board = grid.getBoard();
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void testMGameWithLevel1() {
    
    // Using level 1 as the test for MGame methods.
    std::string fileName = "Level1.txt";
    MGame game(1);
    game.loadLevel(fileName);
    
    // Grid Dimensions (8 rows, 8 columns)
    assert(game.getGrid().getRows() == 8);
    assert(game.getGrid().getColumns() == 8);
    std::cout << "[SUCCESS] Grid initialized to 8x8.\n";

    // Verifying getters: 6 Vehicles created, 9 Passengers created
    assert(game.getVehicleQuantity() == 6);
    assert(game.getVehicles().size() == 6);
    assert(game.getPassengers().size() == 9);
    std::cout << "[SUCCESS] 6 vehicles and 9 passengers created." << std::endl;

    // Quick verification of the grid
    Grid grid = game.getGrid();
    std::vector<std::vector<char>> board = game.getGrid().getBoard();
    
    // BUS at x=0, y=0, direction 2, size 3
    assert(board[0][0] == '0');
    assert(board[1][0] == '0');
    assert(board[2][0] == 'v');
    
    std::cout << "\nVisual representation of level 1:\n";
    printBoard(grid);

    // Verify Passenger vector created in the correct order:
    // Sequence in file: 2 3 1 1 2 3 2 1 2
    assert(game.getPassengers()[0]->getColor() == 2);
    assert(game.getPassengers()[1]->getColor() == 3);
    assert(game.getPassengers()[2]->getColor() == 1);
    assert(game.getPassengers()[8]->getColor() == 2);
    std::cout << "[SUCCESS] Passengers queue created correctly.\n";

    // Test Remove method
    game.removeVehicle(2);
    assert(game.getVehicles().size() == 5);
    // Check if Vehicle no longer appears on vector:
    assert(game.getVehicles()[2]->getID() == 3);
    std::cout << "[SUCCESS] removeVehicle working as intended.\n";
}

int main() {
    
    system("cls");
    testMGameWithLevel1();
    std::cout << "All MGame tests were successful\n";

    return 0;
}