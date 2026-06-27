// Curso: Fundamentos de Programacion Orientada a Objetos
// Archivo: CGame.cpp
// Autores:
// - Juan Ricardo Riaños Horta | Código: 2537573 | juan.rianos@correounivalle.edu.co
// - Carlos Anibal Ceron del Castillo | Código: 2537097 | carlos.ilich.ceron@correounivalle.edu.co
// - Anyela Lineth Cabrera Ordoñez | Código: 2540031 | anyela.cabrera@correounivalle.edu.co
// - Camilo Espinal León | Código: 2538740 | camilo.espinal@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 27/06/2026

#include "MGame.h"
#include "VGame.h"
#include "CGame.h"
#include <iostream>

// WIN = 1, LOSE = 2, RESTART = 3, QUIT = 4, PLAYING = 5
CGame::CGame(MGame* level, VGame* display) 
    : level(level), display(display), gameStatus(5){}

void CGame::updateGrid(){
    // clean board
    level->getGrid().clearBoard();
    // reconstruct board 
    for (auto vehicle : level->getVehicles()){
        level->getGrid().addVehicle(*vehicle);
    }
}

// Method to handle the user input while in game
char CGame::handleInput(){
    display->DisplayText("\nIngresa un numero para mover el vehiculo (1-9): \n");
    display->DisplayText("Presiona 'R' para reiniciar, 'Q' para salir: \n");

    char userInput;
    std::cin >> userInput;

    // Check if user wants to quit or restart the level.
    if(tolower(userInput) == 'q' || tolower(userInput) == 'r') {
        return tolower(userInput);
    }

    if (userInput >= '0' && userInput <= '9') {
        int targetId = userInput - '0';

        // Create a target vehicle pointer.
        Vehicle* targetVehicle = nullptr;

        for (Vehicle* vehicle : level->getVehicles()) {
            if (vehicle->getID() == targetId){
                targetVehicle = vehicle;
                break;
            }
        }

        // If target vehicle is not null, check if it can move.
        if (targetVehicle != nullptr) {
            // If path is clear add bus to the parking zone vector of vehicles, remove the vechile from the grid vehicle. 
            // Update grid to reflect the changes.
            if (level->getGrid().checkPath(*targetVehicle)){
                level->getParkingZone().addBus(targetVehicle);
                level->removeVehicle(targetVehicle->getID());
                updateGrid();
                boarding();
            }
            else {
                display->DisplayText("\n [!] El camino se encuentra bloqueado!");
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    }

    return userInput;
}

    
// Method to check if boarding is possible
bool CGame::boarding() {
    // Gets a reference of the passenger vector.
    auto& queue = level->getPassengers();
    
    bool boardingHappened = false;

    // Start the loop, check if there are still passengers left to continue the loop.
    while (!queue.empty()) {
        // Select the first passenger on the vector.
        Passenger* p = queue.front(); 
        bool boarded = false; 

        // Get the parked vehicles vector from parking zone.
        auto parkedBuses = level->getParkingZone().getParkedBuses();

        // The front passenger checks every possible bus trying to match color.
        for (Vehicle* bus : parkedBuses) {
            if (bus != nullptr && bus->getColor() == p->getColor()) {
                // Check if bus is not full
                if (!bus->isFull()) {
                    bus->boardPassenger();
                    
                    // Remove the passenger at the front.
                    queue.erase(queue.begin()); 
                    
                    boarded = true;
                    boardingHappened = true;

                    // If the bus is now full, delete it from parking zone vector.
                    if (bus->isFull()) {
                        level->getParkingZone().removeBus(bus->getID());
                    }

                    // If passenger boarded exit the loop.
                    break;
                }
            }
        }
        // Check if the passenger was able to board, if not then break the loop.
        if (!boarded) {
            break; 
        }
    }
    
    return boardingHappened;
}

// Main loop for the game
int CGame::play() {
    
    while (gameStatus == 5) {
        // Clean console
        system("cls"); 

        // Pass informacion to the display.
        display->printParkingZone(*level);
        display->printPassengerQueue(*level);
        display->printBoard(*level);
        display->DisplayText("\n");

        // Get the input from the user
        char input = handleInput();

        // Evaluate input:
        if (input == 'q') {
            gameStatus = 4;
            break;
        }

        if (input == 'r') {
            gameStatus = 3;
            break;
        }

        // Check win condition
        if (level->getPassengersQuantity() == 0) { 
            system("cls");
            display->printParkingZone(*level);
            display->printPassengerQueue(*level);
            display->printBoard(*level);
            display ->DisplayText("========================================================\n");
            display->DisplayText("VICTORIA! -- Todos los pasajeros abordaron exitosamente!"); 
            display ->DisplayText("========================================================\n");
            gameStatus = 1;
        }
        // Check lose condition (if there are no free parking spots and there are still passengers left on the vector)
        else if (!level->getParkingZone().columnFree() && level->getPassengersQuantity() > 0) {
            system("cls");
            display->printBoard(*level);
            display ->DisplayText("===========================================================\n");
            display->DisplayText("DERROTA! -- Los pasajeros no pudieron abordar exitosamente.");
            display ->DisplayText("===========================================================\n");
            gameStatus = 2;
        }
    }

    return gameStatus;

}