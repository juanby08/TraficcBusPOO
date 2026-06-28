// Curso: Fundamentos de Programacion Orientada a Objetos
// Archivo: VGame.cpp
// Autores:
// - Juan Ricardo Riaños Horta | Código: 2537573 | juan.rianos@correounivalle.edu.co
// - Carlos Anibal Ceron del Castillo | Código: 2537097 | carlos.ilich.ceron@correounivalle.edu.co
// - Anyela Lineth Cabrera Ordoñez | Código: 2540031 | anyela.cabrera@correounivalle.edu.co
// - Camilo Espinal León | Código: 2538740 | camilo.espinal@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 27/06/2026

#include "VGame.h"
#include <iostream>

// Translate int numColor into a color code ANSI that the console can use.
std::string VGame::getColorCode(int colorNum) const {
    switch (colorNum) {
        case 1: return green;   
        case 2: return blue;    
        case 3: return yellow;  
        case 4: return red;     
        default: return reset;
    }
}

// Returns corresponding color int, checking if cell contains ID, head of the vehicle or a different character.
int VGame::getVehicleColorAt(MGame& game, int r, int c, char cell) const {
    auto vehicles = game.getVehicles();

    // If the cell contains the ID of the vehicle:
    if (cell >= '0' && cell <= '9') {
        int id = cell - '0';
        
        // Loop for each vehicle pointer in vehicles to compare ID, returns int Color. 
        for (auto vehicle : vehicles){
            if (vehicle->getID() == id){
                return vehicle->getColor();
            }
        }
    }
    
    // If the cell contains a symbol representing the vehicle's head ('^', 'v', '<', '>')
    // We use a method from grid to relate the head with the corresponding vehicle.
    if (cell == '^' || cell == 'v' || cell == '<' || cell == '>') {
        for (auto vehicle : vehicles) {

            //Get direction and calculate vehicle head position
            int direction = vehicle->getDirection();

            int dx = 0;
            int dy = 0;

            switch (direction) {
                case 1: // Up
                    dx = -1;
                    break;
                case 2: // Down
                    dx = 1;
                    break;
                case 3: // Left
                    dy = -1;
                    break;
                case 4: // Right
                    dy = 1;
                    break;
            }
            
            int headX = vehicle->getLocation().first + (vehicle->getSize() - 1) * dx;
            int headY = vehicle->getLocation().second + (vehicle->getSize() - 1) * dy;

            // If the head found matches the position calculated, it gets painted with the vehicle corresponding color.
            if (headX == r && headY == c) {
                return vehicle->getColor();
            }
        }
    }
    // Returns 0 for any other character.
    return 0; 
}

void VGame::printBoard(MGame& game) {
    // Get board from MGame-Grid-GetBoard.
    std::vector<std::vector<char>> board = game.getGrid().getBoard();

    // Loop over the board to get each cell's char
    for (int r = 0; r < static_cast<int>(board.size()); ++r) {
        for (int c = 0; c < static_cast<int>(board[r].size()); ++c) {
            char cell = board[r][c];
            
            // Buscamos si la celda le pertenece a algún vehículo y qué color tiene
            int colorNum = getVehicleColorAt(game, r, c, cell);
            
            if (colorNum != 0) {
                // Imprime el caracter envolviéndolo en su código de color y luego resetea la terminal
                std::cout << getColorCode(colorNum) << cell << reset << ' ';
            } else {
                // Si es un camino vacío '.', se imprime de forma normal
                std::cout << cell << ' ';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// General method to display text on screen.
void VGame::DisplayText(const std::string& text){
    std::cout << text << std::endl;
}

void VGame::printParkingZone(MGame& game) {
    std::cout << "--- ZONA DE PARQUEO ---\n";
    
    // Get Vehicle vector from Parking Zone.
    auto parkedBuses = game.getParkingZone().getParkedBuses(); 

    for (int i = 0; i < parkedBuses.size(); i++) {
        std::cout << "Espacio " << i + 1 << ": ";
        
        if (parkedBuses[i] == nullptr) {
            // If there is a null pointer at vector index [i] then the spot is free.
            std::cout << "[ Vacio ]\n";
        } else {
            // We get the vehicle and get the color
            Vehicle* vehicle = parkedBuses[i];
            
            std::string colorStr = getColorCode(vehicle->getColor());
            
            //print using colorStr and ends reseting the string to default value.
            std::cout << colorStr << "[ " 
                      << vehicle->getType() << " " 
                      << vehicle->getID() 
                      << " | Capacidad: " 
                      << vehicle->getCurrentPassengers() << "/" << vehicle->getCapacity() 
                      << " ]" << reset << "\n";
        }
    }
    std::cout << "\n";
}

//Method to print passengerQueue
void VGame::printPassengerQueue(MGame& game) {
    std::cout << "--- FILA DE PASAJEROS ---\n";
    
    // Get passenger Queue from MGame
    auto queue = game.getPassengers(); 

    if (queue.empty()) {
        std::cout << "No hay pasajeros en la fila.\n";
    } else {
        for (size_t i = 0; i < queue.size(); i++) {

            int pColor = queue[i]->getColor(); 
            std::cout << getColorCode(pColor) << "Pasajero " << (i + 1) << reset << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
