// Curso: Fundamentos de Programacion Orientada a Objetos
// Archivo: testParkingZone.cpp
// Autores:
// - Juan Ricardo Riaños Horta | Código: 2537573 | juan.rianos@correounivalle.edu.co
// - Carlos Anibal Ceron del Castillo | Código: 2537097 | carlos.ilich.ceron@correounivalle.edu.co
// - Anyela Lineth Cabrera Ordoñez | Código: 2540031 | anyela.cabrera@correounivalle.edu.co
// - Camilo Espinal León | Código: 2538740 | camilo.espinal@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 27/06/2026

#include <cassert>
#include <iostream>

#include "ParkingZone.h"
#include "Bus.h"

//Crear zona de parqueo
void testColumnFree() {
    ParkingZone zone(1, 2);
    assert(zone.columnFree() == true);
}

//Test para 2 metodos: Añadir y sacar un bus
void testColumnFreeAfterRemovingBus() {
    ParkingZone zone(1, 1);
    Bus* bus = new Bus( //se crea un bus
        1,
        1,
        {0,0},
        1,
        3,
        20
    );
    zone.addBus(bus);
    assert(zone.columnFree() == false); //el parkingzone esta lleno
    zone.removeBus(1); //que busque el bus con ID 1
    assert(zone.columnFree() == true); //ahora el parkingzone esta vacio
    delete bus;
}

int main() {

    testColumnFree();
    testColumnFreeAfterRemovingBus();

    std::cout << "Todos los tests pasaron.\n";

    return 0;
}