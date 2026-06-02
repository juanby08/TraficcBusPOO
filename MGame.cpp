#include "MGame.h"
//#include "Game.cpp"
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
    cout << "Cargando nivel " << filePath << endl;

    // Abrir el archivo txt
    ifstream file(filePath);

    // Variables para almacenar los datos del nivel
    int row, columns;
    
    file >> row >> columns; // Leer el número de filas y columnas del nivel
    cout << "Se creo un tablero de " << row << " filas y " << columns << " columnas." << endl;

    //ciclo para leer vehiculos y pasajeros.... en espera
    cout << "Nivel cargado exitosamente" << endl;
}
