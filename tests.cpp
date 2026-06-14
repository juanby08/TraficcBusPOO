#include "MGame.h"
#include <iostream>
#include <fstream>
#include <cassert>

int main() {
    std::string testFileName = "Level1.txt";
    
    std::cout << "--- Iniciando Pruebas Unitarias para MGame ---" << std::endl;
    MGame game(1);
    
    // Validar constructor
    assert(game.getLevel() == 1);
    assert(game.getVehicleQuantity() == 0);
    assert(game.getPassengersQuantity() == 0);
    std::cout << "[PASÓ] Inicialización de MGame correcta." << std::endl;

    // 3. Ejecutar el método bajo prueba: loadLevel
    std::cout << "\nCargando nivel desde el archivo..." << std::endl;
    game.loadLevel(testFileName);
    std::cout << "---------------------------------------" << std::endl;

    // 4. Verificaciones post-carga

    // Verificar cantidades globales
    assert(game.getVehicleQuantity() == 2); // Creó 2 vehículos en total (el contador incrementa para ambos)
    assert(game.getPassengersQuantity() == 3); // 3 pasajeros en la cola
    std::cout << "[PASÓ] Contadores de vehículos y pasajeros correctos." << std::endl;

    // Verificar el vector de Vehículos
    auto vehicles = game.getVehicles();
    assert(vehicles.size() == 2);
    
    // Validar el primer vehículo (Debe ser un BUS)
    assert(vehicles[0]->getType() == "bus");
    assert(vehicles[0]->getColor() == 1); // Verde
    assert(vehicles[0]->getDirection() == 2); // Abajo
    assert(vehicles[0]->getSize() == 3);
    
    // Validar el segundo vehículo (Debe ser un CAR)
    assert(vehicles[1]->getType() == "Car");
    assert(vehicles[1]->getColor() == 4); // Rojo
    assert(vehicles[1]->getDirection() == 4); // Derecha
    assert(vehicles[1]->getSize() == 2); // El constructor de Car fuerza el tamaño a 2
    std::cout << "[PASÓ] Propiedades de los vehículos instanciados correctamente." << std::endl;

    // Verificar la cola de pasajeros
    auto passengers = game.getPassengers();
    assert(passengers.size() == 3);
    assert(passengers[0]->getColor() == 2); // Azul
    assert(passengers[1]->getColor() == 3); // Amarillo
    assert(passengers[2]->getColor() == 1); // Verde
    std::cout << "[PASÓ] Cola de pasajeros cargada en el orden correcto." << std::endl;

    // 5. Verificar el estado del Grid (Tablero)
    // El Bus (ID 0) está en (0,0) hacia Abajo (dx=1, dy=0), tamaño 3. 
    // Cuerpo en (0,0), (1,0) y Cabeza '^' o 'v' en (2,0)
    auto board = game.getGrid().getBoard();
    
    // El ID del primer vehículo es 0
    assert(board[0][0] == '0');
    assert(board[1][0] == '0');
    assert(board[2][0] == 'v'); // Dirección 2 es Down ('v')
    
    std::cout << "[PASÓ] El Grid reflejó correctamente la posición de los vehículos." << std::endl;

    std::cout << "\n--- ¡TODOS LOS TESTS PASARON CON ÉXITO! ---" << std::endl;

    return 0;
}