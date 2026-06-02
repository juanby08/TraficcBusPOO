#include "MGame.h"
//#include "Game.cpp"
#include <fstream> // Para leer los archivos planos de niveles
#include <iostream>
using namespace std;

MGame:: MGame(){

    }

//Se cargaria el nivel, se inicializarian los buses y pasajeros, y se colocarian en el tablero
void MGame::loadLevel(){
  
    cout << "Cargando nivel " << level << endl;
}
