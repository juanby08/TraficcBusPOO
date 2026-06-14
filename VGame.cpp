#include "VGame.h"
#include <iostream>

// Traduce el entero del atributo color al código ANSI correspondiente
std::string VGame::getColorCode(int colorNum) const {
    switch (colorNum) {
        case 1: return green;   
        case 2: return blue;    
        case 3: return yellow;  
        case 4: return red;     
        default: return reset;
    }
}

// Devuelve el número de color correspondiente a una celda específica
int VGame::getVehicleColorAt(MGame& game, int r, int c, char cell) const {
    auto vehicles = game.getVehicles();

    // CASO 1: Es el cuerpo del vehículo (un dígito de ID '0' a '9')
    if (cell >= '0' && cell <= '9') {
        int id = cell - '0';
        if (id >= 0 && id < static_cast<int>(vehicles.size())) {
            return vehicles[id]->getColor(); // Retorna el color del vehículo por su ID
        }
    }
    
    // CASO 2: Es la cabeza del vehículo ('^', 'v', '<', '>')
    // Como la matriz no guarda el ID en la cabeza, calculamos matemáticamente dónde está la cabeza de cada vehículo
    if (cell == '^' || cell == 'v' || cell == '<' || cell == '>') {
        for (auto vehicle : vehicles) {
            int direction = vehicle->getDirection();
            int dx = 0, dy = 0;
            
            // Replicamos la lógica de movimiento de Grid para hallar la orientación
            switch (direction) {
                case 1: dx = -1; break; // Up
                case 2: dx = 1;  break; // Down
                case 3: dy = -1; break; // Left
                case 4: dy = 1;  break; // Right
            }
            
            // Calculamos la coordenada exacta de la cabeza
            int headX = vehicle->getLocation().first + (vehicle->getSize() - 1) * dx;
            int headY = vehicle->getLocation().second + (vehicle->getSize() - 1) * dy;

            // Si la cabeza evaluada coincide con la posición actual del mapa, encontramos el vehículo
            if (headX == r && headY == c) {
                return vehicle->getColor();
            }
        }
    }

    return 0; // Retorna 0 si es un espacio vacío '.' sin color
}

void VGame::printBoard(MGame& game) {
    // Obtenemos el tablero dinámico del Grid actual
    std::vector<std::vector<char>> board = game.getGrid().getBoard();

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

void VGame::DisplayText(const std::string& text)
{
    cout << text << endl;
}

void VGame::printParkingZone(MGame& game) {
    std::cout << "--- ZONA DE PARQUEO ---\n";
    
    // Obtenemos el vector de vehículos parqueados
    auto parkedBuses = game.getParkingZone().getParkedBuses(); 

    for (int i = 0; i < parkedBuses.size(); i++) {
        std::cout << "Espacio " << i + 1 << ": ";
        
        if (parkedBuses[i] == nullptr) {
            // Si el puntero es nulo, el espacio está libre
            std::cout << "[ Vacio ]\n";
        } else {
            // Extraemos el vehículo
            Vehicle* v = parkedBuses[i];
            
            // Reutilizamos nuestra función para obtener el código de color ANSI
            std::string colorStr = getColorCode(v->getColor());
            
            // Imprimimos con el formato solicitado: Tipo + ID + Pasajeros/Capacidad
            // Nota: Nos aseguramos de envolver todo en el color correspondiente
            std::cout << colorStr << "[ " 
                      << v->getType() << " " 
                      << v->getID() 
                      << " | Capacidad: " 
                      << v->getCurrentPassengers() << "/" << v->getCapacity() 
                      << " ]" << reset << "\n";
        }
    }
    std::cout << "\n";
}

// ---------------------------------------------------------
// Método para imprimir la cola de pasajeros
// ---------------------------------------------------------
void VGame::printPassengerQueue(MGame& game) {
    std::cout << "--- FILA DE PASAJEROS ---\n";
    
    // Obtenemos la fila de pasajeros desde MGame
    auto queue = game.getPassengers(); 

    if (queue.empty()) {
        std::cout << "No hay pasajeros en la fila.\n";
    } else {
        // Iteramos sobre el vector de pasajeros
        for (size_t i = 0; i < queue.size(); i++) {
            // Extraemos el color de cada pasajero
            int pColor = queue[i]->getColor(); 
            
            // Imprimimos la palabra "Pasajero " + (índice + 1) aplicando su color
            std::cout << getColorCode(pColor) << "Pasajero " << (i + 1) << reset << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}