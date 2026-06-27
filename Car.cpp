// Curso: Fundamentos de Programacion Orientada a Objetos
// Archivo: Car.cpp
// Autores:
// - Juan Ricardo Riaños Horta | Código: 2537573 | juan.rianos@correounivalle.edu.co
// - Carlos Anibal Ceron del Castillo | Código: 2537097 | carlos.ilich.ceron@correounivalle.edu.co
// - Anyela Lineth Cabrera Ordoñez | Código: 2540031 | anyela.cabrera@correounivalle.edu.co
// - Camilo Espinal León | Código: 2538740 | camilo.espinal@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 27/06/2026

#include "Car.h"

Car::Car(
    int ID, 
    int color, 
    std::pair<int, int> location,
    int direction,
    int currentPassengers)
    : Vehicle (
    ID,
    color,
    location,
    direction,
    2,
    4,
    currentPassengers){}

std::string Car::getType() const{
    return "Car";
}