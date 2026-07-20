// Curso: Fundamentos de Programacion Orientada a Objetos
// Archivo: testSave.cpp
// Autores:
// - Juan Ricardo Riaños Horta | Código: 2537573 | juan.rianos@correounivalle.edu.co
// - Carlos Anibal Ceron del Castillo | Código: 2537097 | carlos.ilich.ceron@correounivalle.edu.co
// - Anyela Lineth Cabrera Ordoñez | Código: 2540031 | anyela.cabrera@correounivalle.edu.co
// - Camilo Espinal León | Código: 2538740 | camilo.espinal@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 19/06/2026

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "MGame.h"

const std::string LEVEL_FILE = "Level3.txt";

//Reads all non-empty lines from a file.
std::vector<std::string> readLines(const std::string& path) {
    std::vector<std::string> lines;
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) lines.push_back(line);
    }
    return lines;
}

// Test 1: When saving Level3.txt without modifications, the header (rows, columns, parkingSpots) and the passenger row are preserved.
void test_headerAndPassengersFromLevel3() {
    MGame model(3);
    model.loadLevel(LEVEL_FILE);

    // Level3.txt contains 4 buses + 6 cars = 10 vehicles, and 16 passengers..
    assert(model.getVehicleQuantity() == 10);
    assert(model.getPassengersQuantity() == 16);

    model.Save("test_level3.txt");

    std::vector<std::string> lines = readLines("test_level3.txt");
    assert(!lines.empty());

    // --- Heading ---
    std::istringstream headerStream(lines[0]);
    int rows, columns, parkingSpots;
    headerStream >> rows >> columns >> parkingSpots;

    assert(rows == 10);
    assert(columns == 10);
    assert(parkingSpots == 4); // total parking capacity

    // --- Passenger row (last line) ---
    std::string lastLine = lines.back();
    std::istringstream passengerStream(lastLine);
    std::vector<int> savedColors;
    int color;
    while (passengerStream >> color) {
        savedColors.push_back(color);
    }

    std::vector<int> expectedColors = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 2, 1, 3, 4};
    assert(savedColors == expectedColors);

    std::cout << "[OK] El nivel 3 (sin cambios) se guardo exitosamente" << std::endl;
}

// ---------------------------------------------------------------------------
// Test 2: If a vehicle ends up parked, the number of vehicles should remain the same upon reloading the saved file.

void test_parkedVehicleDuplicationBug() {
    MGame model(3);
    model.loadLevel(LEVEL_FILE);

    int originalVehicleQuantity = model.getVehicleQuantity();
    assert(originalVehicleQuantity == 10);

    // Take the BUS with ID 0 (the first one loaded from Level3.txt).
    Vehicle* targetVehicle = nullptr;
    for (Vehicle* v : model.getVehicles()) {
        if (v->getID() == 0) {
            targetVehicle = v;
            break;
        }
    }
    assert(targetVehicle != nullptr);

    // Move it until it leaves the board, just like in CGame::handleInput.
    while (model.getGrid().moveVehicle(*targetVehicle)) {
    }

    // Park it, just as CGame does after the vehicle is exited.
    model.getParkingZone().addBus(targetVehicle);

    model.Save("test_output_parked.txt");

    MGame reloadedModel(3);
    reloadedModel.loadLevel("test_output_parked.txt");

    assert(reloadedModel.getVehicleQuantity() == originalVehicleQuantity);

    std::cout << "[OK] El vehiculo parqueado no se duplica en el archivo guardado" << std::endl;
}
//-----------------------------------------------------------------------------------------------------
// Test main method
int main() {
    std::cout << "=== Ejecutando tests para MGame::Save (usando Level3.txt) ===\n\n";

    test_headerAndPassengersFromLevel3();
    test_parkedVehicleDuplicationBug();

    std::cout << "\nTodos los tests pasaron correctamente.\n";
    return 0;
}
