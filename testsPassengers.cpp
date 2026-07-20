// Curso: Fundamentos de Programacion Orientada a Objetos
// Archivo: testsPassengers.cpp
// Autores:
// - Juan Ricardo Riaños Horta | Código: 2537573 | juan.rianos@correounivalle.edu.co
// - Carlos Anibal Ceron del Castillo | Código: 2537097 | carlos.ilich.ceron@correounivalle.edu.co
// - Anyela Lineth Cabrera Ordoñez | Código: 2540031 | anyela.cabrera@correounivalle.edu.co
// - Camilo Espinal León | Código: 2538740 | camilo.espinal@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 19/06/2026
// comando g++ testsPassengers.cpp Passenger.cpp -o testsPassengers

#include <cassert>
#include <iostream>

#include "Passenger.h"

// Verify that the constructor correctly stores the color.
void testPassengerColor() {
    Passenger passenger(3);
    assert(passenger.getColor() == 3);
}

// Check another color to be sure.
void testPassengerColor1() {
    Passenger passenger(1);
    assert(passenger.getColor() == 1);
}

// Check another color to be sure.
void testPassengerColor2() {
    Passenger passenger(2);
    assert(passenger.getColor() == 2);
}

// Check another color to be sure.
void testPassengerColor4() {
    Passenger passenger(4);
    assert(passenger.getColor() == 4);
}

int main() {
    testPassengerColor();
    testPassengerColor1();
    testPassengerColor2();
    testPassengerColor4();
    std::cout << "Todos los tests de Passenger pasaron.\n";
    return 0;
}