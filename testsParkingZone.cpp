// Curso: Fundamentos de Programacion Orientada a Objetos
// Archivo: testParkingZone.cpp
// Autores:
// - Juan Ricardo Riaños Horta | Código: 2537573 | juan.rianos@correounivalle.edu.co
// - Carlos Anibal Ceron del Castillo | Código: 2537097 | carlos.ilich.ceron@correounivalle.edu.co
// - Anyela Lineth Cabrera Ordoñez | Código: 2540031 | anyela.cabrera@correounivalle.edu.co
// - Camilo Espinal León | Código: 2538740 | camilo.espinal@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 19/06/2026
// comando para ejecutar test: g++ testsParkingZone.cpp ParkingZone.cpp Vehicle.cpp Bus.cpp Car.cpp -o testParkingZone

#include <cassert>
#include <iostream>

#include "ParkingZone.h"
#include "Bus.h"

//Create a parking zone
void testColumnFree() {
    ParkingZone zone(1, 2);
    assert(zone.columnFree() == true);
}

//Test for 2 methods: Adding and removing a bus
void testColumnFreeAfterRemovingBus() {
    ParkingZone zone(1, 1);
    Bus* bus = new Bus(
        1,
        1,
        {0,0},
        1,
        3,
        20
    );
    // Add the bus to the parking zone.
    assert(zone.addBus(bus));

    // Parking zone should now be full.
    assert(zone.columnFree() == false);

    // Remove the bus.
    assert(zone.removeBus(1));

    // Parking zone should now have a free space.
    assert(zone.columnFree() == true);
}

int main() {

    testColumnFree();
    testColumnFreeAfterRemovingBus();

    std::cout << "Todos los tests pasaron.\n";

    return 0;
}