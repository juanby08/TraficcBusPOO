// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: Grid.cpp
// Autores:
// - Camilo Espinal León | Código: 2538740| camilo.espinal@correounivalle.edu.co
//
// Fecha: 1/06/2026

// incluir la clase
#include "Grid.h"
#include <vector>
// libreria para el manejo de archivos planos
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constructor
Grid::Grid()
{
    Map.resize(0); //Se inicializa el laberinto en vacio
    level = "";
}


void Grid::getLevel(string auxlevelname)
{
  // Abrir el archivo plano
  ifstream flujoDatos(auxlevelname);
  // capturar la información linea a linea del archivo plano
  string line;
  string aux;
  // Recorrer el archivo plano
  while(getline(flujoDatos, line)){
    vector <int> auxVector;
    for(int j=0; j<19; j = j+2){
      aux = line.substr(j, 1);
      auxVector.push_back(stoi(aux));// Cargar el Mapa (atributo) y transformar el dato char a int
    }
    Map.push_back(auxVector);// Cargar el Mapa (atributo)
  }
}


int Grid::getBus(int x, int y)
{
  return Map[x][y]; // Retorna "0" o "1" del Mapa
}


