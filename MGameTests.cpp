// Curso: Fundamentos de Programacion Orientada a Objetos
// Archivo: MGameTests.cpp
// Autores:
// - Juan Ricardo Riaños Horta | Código: 2537573 | juan.rianos@correounivalle.edu.co
// - Carlos Anibal Ceron del Castillo | Código: 2537097 | carlos.ilich.ceron@correounivalle.edu.co
// - Anyela Lineth Cabrera Ordoñez | Código: 2540031 | anyela.cabrera@correounivalle.edu.co
// - Camilo Espinal León | Código: 2538740 | camilo.espinal@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 19/06/2026

#include "MGame.h"
#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;

// Prints the board to visually verify that the level was loaded correctly.
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

    // Load Level1.txt to test the MGame class.
    string fileName = "Level1.txt";

    MGame game(1);
    game.loadLevel(fileName);

    // Verify Grid initialization.
    assert(game.getGrid().getRows() == 6);
    assert(game.getGrid().getColumns() == 6);

    cout << "[SUCCESS] Grid initialized correctly (6x6)." << endl;

    // Verify vehicles and passengers were loaded correctly.
    assert(game.getVehicleQuantity() == 4);
    assert(game.getVehicles().size() == 4);

    assert(game.getPassengersQuantity() == 6);
    assert(game.getPassengers().size() == 6);

    cout << "[SUCCESS] Vehicles and passengers loaded correctly." << endl;

    // Verify first vehicle on the board.
    Grid grid = game.getGrid();
    vector<vector<char>> board = grid.getBoard();

    assert(board[1][1] == '0');
    assert(board[1][2] == '>');

    cout << "[SUCCESS] Grid representation is correct." << endl;

    cout << "\nVisual representation of Level 1:\n";
    printBoard(grid);

    // Verify passenger queue order.
    // Sequence in Level1.txt:
    // 1 2 3 4 1 2
    assert(game.getPassengers()[0]->getColor() == 1);
    assert(game.getPassengers()[1]->getColor() == 2);
    assert(game.getPassengers()[2]->getColor() == 3);
    assert(game.getPassengers()[3]->getColor() == 4);
    assert(game.getPassengers()[4]->getColor() == 1);
    assert(game.getPassengers()[5]->getColor() == 2);

    cout << "[SUCCESS] Passenger queue loaded correctly." << endl;

    // Verify removeVehicle().
    game.removeVehicle(2);

    assert(game.getVehicles().size() == 3);

    bool found = false;

    for (Vehicle* vehicle : game.getVehicles()) {
        if (vehicle->getID() == 2) {
            found = true;
        }
    }

    assert(!found);

    cout << "[SUCCESS] removeVehicle() works correctly." << endl;
}

int main() {

    system("cls");
    testMGameWithLevel1();
    cout << "All MGame tests were successful.\n";
    return 0;
}