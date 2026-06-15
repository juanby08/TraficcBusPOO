#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <cstdlib>

#include "Grid.h"
#include "Bus.h"
#include "Car.h"

// Helper function just to visually represent the board.
void printBoard(Grid& grid){
    std::vector<std::vector<char>> board = grid.getBoard();

    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void testGridConstructor(){
    Grid grid(5,4);

    assert(grid.getColumns() == 5);
    assert(grid.getRows() == 4);

    std::vector <std::vector<char>> board = grid.getBoard();

    assert(board.size() == 4);
    assert(board[0].size() == 5);


    for (int i = 0; i < grid.getRows(); ++i) {
        for (int j = 0; j < grid.getColumns(); ++j){
            assert(board[i][j] == '.');
        }
    }

    std::cout<<"[SUCCESS] Grid initialized correctly with '.'\n";
}

void testClearBoard(){
    Grid grid(4,4);

    Car car(0, 2, {0, 0}, 2, 0);
    grid.addVehicle(car);

    assert(grid.getBoard()[0][0] == '0');

    // Clear the board should reset all positions to '.'
    grid.clearBoard();

    std::vector <std::vector<char>> board = grid.getBoard();
    for (int i = 0; i < grid.getRows(); ++i) {
        for (int j = 0; j < grid.getColumns(); ++j){
            assert(board[i][j] == '.');
        }
    }

    std::cout<<"[SUCCESS] Grid cleared correctly\n";


}

void testAddVehicleAndCheckPath() {
    std::cout << "--- Running Vehicle Placement and Path Checking Tests ---\n";

    Grid grid(6, 6);
    
    Car car1(1, 4, {1, 1}, 4, 0);
    grid.addVehicle(car1);
    
    std::vector<std::vector<char>> board = grid.getBoard();
    assert(board[1][1] == '1');
    assert(board[1][2] == '>');
    
    std::cout << "Board after adding Car 1 (heading Right):\n";
    printBoard(grid);
    
    assert(grid.checkPath(car1) == true);
    std::cout << "[SUCCESS] Car 1 added and its path is clear.\n";

    Bus bus1(2, 2, {4, 4}, 1, 3, 0);
    grid.addVehicle(bus1);
    
    board = grid.getBoard();
    assert(board[4][4] == '2');
    assert(board[3][4] == '2');
    assert(board[2][4] == '^');
    
    std::cout << "Board after adding Bus 1 (heading Up):\n";
    printBoard(grid);
    
    assert(grid.checkPath(bus1) == true);
    
    Car car2(3, 3, {1, 5}, 3, 0);
    grid.addVehicle(car2);
    
    board = grid.getBoard();
    assert(board[1][5] == '3');
    assert(board[1][4] == '<');
    
    std::cout << "Board after adding Car 2 (blocking Car 1's path):\n";
    printBoard(grid);
    
    assert(grid.checkPath(car1) == false);
    std::cout << "[SUCCESS] checkPath correctly detected an obstacle for Car 1.\n";
}


int main(){
    system("cls");
    testGridConstructor();
    testClearBoard();
    testAddVehicleAndCheckPath();

    std::cout<<"\nAll test were completed successfully.\n";
    return 0;
}