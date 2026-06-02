/*

.cpp Creado solamente para testear el funcionamiento del constructor y las funciones de BUS.


NO SE INCLUIRA EN LA ENTREGA FINAL.

Comando para probar los tests: g++ Vehicle.cpp Bus.cpp Car.cpp BusTest.cpp -o BusTest

*/

#include <cassert>
#include <iostream>

#include "Bus.h"
#include "Car.h"

void testConstructor()
{
    Bus bus(
        1,
        Color::Red,
        {2, 3},
        Direction::Right,
        3,
        4
    );
    std::cout<<bus.getID();
    assert(bus.getID() == 1);
    assert(bus.getColor() == Color::Red);
    assert(bus.getLocation() == std::make_pair(2, 3));
    assert(bus.getSize() == 3);

    assert(bus.getCapacity() == 4);
    assert(bus.getCurrentPassengers() == 0);

    std::cout << "testConstructor passed\n";
}

void testGetters()
{
    Bus bus(
        10,
        Color::Blue,
        {5, 6},
        Direction::Left,
        2,
        8
    );

    assert(bus.getID() == 10);
    assert(bus.getColor() == Color::Blue);
    assert(bus.getLocation().first == 5);
    assert(bus.getLocation().second == 6);
    assert(bus.getSize() == 2);

    assert(bus.getCapacity() == 8);
    assert(bus.getCurrentPassengers() == 0);

    std::cout << "testGetters passed\n";
}

void testIsFullInitiallyFalse()
{
    Bus bus(
        1,
        Color::Green,
        {0, 0},
        Direction::Up,
        2,
        2
    );

    assert(!bus.isFull());

    std::cout << "testIsFullInitiallyFalse passed\n";
}

void testBoardPassenger()
{
    Bus bus(
        1,
        Color::Yellow,
        {0, 0},
        Direction::Right,
        2,
        3
    );

    assert(bus.boardPassenger());
    assert(bus.getCurrentPassengers() == 1);

    assert(bus.boardPassenger());
    assert(bus.getCurrentPassengers() == 2);

    assert(bus.boardPassenger());
    assert(bus.getCurrentPassengers() == 3);

    assert(bus.isFull());

    std::cout << "testBoardPassenger passed\n";
}

// void testBoardPassengerWhenFull()
// {
//     Bus bus(
//         1,
//         Color::Red,
//         {0, 0},
//         Direction::Right,
//         3,
//         2
//     );

//     assert(bus.boardPassenger());
//     assert(bus.boardPassenger());

//     assert(bus.isFull());

//     // No debería permitir más pasajeros
//     assert(!bus.boardPassenger());

//     assert(bus.getCurrentPassengers() == 2);

//     std::cout << "testBoardPassengerWhenFull passed\n";
// }

void testCapacityOne()
{
    Bus bus(
        5,
        Color::Blue,
        {1, 1},
        Direction::Down,
        2,
        1
    );

    assert(!bus.isFull());

    assert(bus.boardPassenger());

    assert(bus.isFull());

    assert(!bus.boardPassenger());

    std::cout << "testCapacityOne passed\n";
}

void testCarConstructor()
{
    Car car(
        20,
        Color::Blue,
        {4, 7},
        Direction::Left
    );

    assert(car.getID() == 20);
    assert(car.getColor() == Color::Blue);
    assert(car.getLocation() == std::make_pair(4,7));

    // Todos los carros ocupan 2 espacios
    assert(car.getSize() == 2);

    std::cout << "testCarConstructor passed\n";
}

void testCarGetters()
{
    Car car(
        30,
        Color::Green,
        {1, 2},
        Direction::Up
    );

    assert(car.getID() == 30);
    assert(car.getColor() == Color::Green);

    auto location = car.getLocation();

    assert(location.first == 1);
    assert(location.second == 2);

    std::cout << "testCarGetters passed\n";
}

void testBusDestructor()
{
    Vehicle* vehicle =
        new Bus(
            1,
            Color::Red,
            {0,0},
            Direction::Right,
            3,
            4
        );

    delete vehicle;

    std::cout << "testBusDestructor passed\n";
}

int main()
{
    testConstructor();
    testGetters();
    testIsFullInitiallyFalse();
    testBoardPassenger();
    //testBoardPassengerWhenFull();
    testCapacityOne();
    testCarConstructor();
    testCarGetters();
    testBusDestructor();

    std::cout << "\nAll Bus tests passed successfully.\n";

    return 0;
}