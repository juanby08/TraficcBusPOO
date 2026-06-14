#include <cassert>
#include <iostream>

#include "Passenger.h"

// Verifica que el constructor guarde correctamente el color
void testPassengerColor() {
    Passenger passenger(3);
    assert(passenger.getColor() == 3);
}

// Verifica otro color para asegurarnos
void testPassengerColor1() {
    Passenger passenger(1);
    assert(passenger.getColor() == 1);
}

// Verifica otro color para asegurarnos
void testPassengerColor2() {
    Passenger passenger(2);
    assert(passenger.getColor() == 2);
}

// Verifica otro color para asegurarnos
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