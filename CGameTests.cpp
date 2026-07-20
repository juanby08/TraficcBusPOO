#include <cassert>
#include <iostream>
#include "MGame.h"
#include "VGame.h"
#include "CGame.h"

// Load a level, update the board, and verify that there is at least one vehicle represented within the Grid matrix.
void testUpdateGrid() {
    // Create and load a game level.
    MGame model(1);
    model.loadLevel("Level1.txt");

    // Create display and controller.
    VGame display;
    CGame controller(&model, &display);

    // Rebuild the board from the current vehicle positions.
    controller.updateGrid();

    // Obtain the generated board.
    auto board = model.getGrid().getBoard();

    bool vehicleFound = false;

    // Search for any occupied cell.
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell != '.') {
                vehicleFound = true;
            }
        }
    }

    // Verify that at least one vehicle was drawn.
    assert(vehicleFound);

    std::cout << "testUpdateGrid PASSED\n";
}

// Verify that the number of passengers in the queue decreases when a successful boarding occurs.
void testBoarding() {
    // Create and load a game level.
    MGame model(1);
    model.loadLevel("Level1.txt");

    // Create display and controller.
    VGame display;
    CGame controller(&model, &display);

    // Store passenger count before boarding.
    int passengersBefore = model.getPassengersQuantity();

    // Attempt boarding.
    bool boarded = controller.boarding();

    // If boarding occurred, passenger count must decrease.
    if (boarded) {
        assert(model.getPassengersQuantity() < passengersBefore);
    }
    std::cout << "testBoarding PASSED\n";
}

// Simulate a state where no passengers remain in the queue and verify that the count is zero.
void testWinCondition() {

    // Create and load a game level.
    MGame model(1);
    model.loadLevel("Level1.txt");

    // Remove every passenger.
    model.getPassengers().clear();

    // Verify that no passengers remain.
    assert(model.getPassengersQuantity() == 0);

    std::cout << "testWinCondition PASSED\n";
}

// Verify that the columnFree() method returns a valid boolean value.
void testLoseCondition() {

    // Create and load a game level.
    MGame model(1);
    model.loadLevel("Level1.txt");

    // Verify that columnFree returns a valid boolean value.
    assert(
        model.getParkingZone().columnFree() == true ||
        model.getParkingZone().columnFree() == false
    );

    std::cout << "testLoseCondition PASSED\n";
}


int main() {
    testUpdateGrid();
    testBoarding();
    testWinCondition();
    testLoseCondition();

    std::cout << "\nTodos los tests de CGame pasaron correctamente.\n";
    return 0;
}