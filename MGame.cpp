/* Curso: Fundamentos de Programación Orientada a Objetos
 Archivo: MGame.cpp
 Autores:
 - Anyela Lineth Cabrera Ordoñez | Código: 202540031| anyela.cabrera@correounivalle.edu.co
*/

//#include "Game.h"
#include "MGame.h"
#include "Parser.h" 
#include <iostream>
#include <fstream>

using namespace std;

//MGame::MGame() {}

void MGame::loadLevel(string filePath) {
    cout << "Cargando nivel " << filePath << "..." << endl;
    // Abrir el archivo plano
    ifstream file(filePath);
    // Verificar que el archivo se abrió correctamente
    if (!file.is_open()) {
        cout << "Error: No se pudo abrir " << filePath << endl;
        return;
    }
    // Variables para almacenar temporalmente los datos del archivo
    int row, columns;
    file >> row >> columns; 
    string typeStr, colorStr, dirStr;
    int x, y, size;

    // Leer los vehículos hasta encontrar el "-"
    while (file >> typeStr && typeStr != "-") {
        file >> colorStr >> x >> y >> dirStr >> size;
        // Convertir los strings 
        Color vehicleColor = Parser::stringToColor(colorStr);
        Direction vehicleDir = Parser::stringToDirection(dirStr);

        // Instanciar los objetos y agregarlos al vector de vehículos
        if (typeStr == "BUS") {
            // El constructor de Bus pide capacidad. Le pasamos 4 por defecto.
            vehicles.push_back(new Bus(busQuantity, vehicleColor, {x, y}, vehicleDir, size, 4));
            busQuantity++;
        } 
        else if (typeStr == "CAR") {
            vehicles.push_back(new Car(busQuantity, vehicleColor, {x, y}, vehicleDir));
            busQuantity++; 
        }
    }

    
    // Leer el "-" que separa los vehículos de la fila de pasajeros
    string dummyStr; 
    file >> dummyStr;

    // Bucle para leer la fila de pasajeros y guardarla en la cola
    while (file >> colorStr) {
        Color passengerColor = Parser::stringToColor(colorStr);
        passengerQueue.push_back(passengerColor);
        passengersQuantity++;
    }

    cout << "Nivel cargado exitosamente." << endl;
    cout << "Vehiculos creados: " << busQuantity << endl;
    cout << "Pasajeros en fila: " << passengersQuantity << endl;

    file.close();
}