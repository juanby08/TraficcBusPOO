/* Curso: Fundamentos de Programación Orientada a Objetos
 Archivo: MGame.cpp
 Autores:
 - Anyela Lineth Cabrera Ordoñez | Código: 202540031| anyela.cabrera@correounivalle.edu.co
*/

#include "MGame.h"
//#include "Game.cpp"
#include "Parser.cpp" 
#include <iostream>
#include <fstream> // Para leer los archivos planos de niveles
using namespace std;

// Constructor
MGame:: MGame(){
    level = 1;
    finished = false;
    busQuantity = 0;
    passengersQuantity = 0;

    }

// Método
void MGame::loadLevel(string filePath) {
    //ifstream file(filePath);
    cout << "Cargando nivel " << filePath << endl;

    // Abrir el archivo txt
    ifstream file(filePath);
    int row, columns; // Variables para almacenar los datos del nivel
    file >> row >> columns; // Leer el número de filas y columnas del nivel
    cout << "Se creo un tablero de " << row << " filas y " << columns << " columnas." << endl;

    /*if (!file.is_open()) {
        cout << "Error: No se pudo abrir " << filePath << endl;
        return;
    }*/

    //ciclo para leer vehiculos y pasajeros.... en espera
    cout << "Nivel cargado exitosamente" << endl;

    string typeStr, colorStr, dirStr;
    int x, y, size;

    // Bucle para leer los vehículos
    while (file >> typeStr && typeStr != "-") {
        file >> colorStr >> x >> y >> dirStr >> size;

        // Uso del traductor para convertir el texto a los tipos de tu juego
        Color vehicleColor = Parser::stringToColor(colorStr);
        Direction vehicleDir = Parser::stringToDirection(dirStr);

        // Crar el vehículo usando los datos leídos 
        cout << "Vehiculo procesado correctamente." << endl;
    }

    // Aquí iría la parte de los pasajeros 
    file.close();
}
