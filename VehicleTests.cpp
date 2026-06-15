/*
Comando para probar los tests: g++ Vehicle.cpp Bus.cpp Car.cpp BusTest.cpp -o BusTest
*/

#include <cassert>
#include <iostream>
#include "Bus.h"
#include "Car.h"

void testConstructor()
{
    Bus bus(1,
        4, // 1 = Green, 2 = Blue, 3 = Yellow, 4 = Red
        {2, 3},
        4,// 1 = Up, 2 = Down, 3 = Left, 4 = Right
        3, 4);

    assert(bus.getID() == 1);
    assert(bus.getColor() == 4);
    assert(bus.getLocation() == std::make_pair(2, 3));
    assert(bus.getSize() == 3);

    assert(bus.getCapacity() == 8);
    assert(bus.getCurrentPassengers() == 4);

  std::cout << "[SUCCESS] " << "Test Constructor passed\n";
}

void testBusGetters(){

    Bus bus (10,2,{5, 6},3,2,0);

    assert(bus.getID() == 10);
    assert(bus.getColor() == 2);
    assert(bus.getLocation().first == 5);
    assert(bus.getLocation().second == 6);
    assert(bus.getSize() == 2);

    assert(bus.getCapacity() == 6);
    assert(bus.getCurrentPassengers() == 0);

    std::cout << "[SUCCESS] " << "Test Bus Getters passed\n";
}

void testCarGetters(){
    Car car (2, 4, {0,0}, 4, 2);

    assert(car.getID() == 2);
    assert(car.getColor() == 4);
    assert(car.getLocation() == std::make_pair(0,0));
    assert(car.getDirection() == 4);
    assert(car.getCurrentPassengers() == 2);

    std::cout << "[SUCCESS] " << "Test Car Getters passed\n";
}

void testIsFullInitiallyFalse()
{
    Bus bus (1, 1, {0, 0}, 1, 2, 2);

    assert(!bus.isFull());
    assert(bus.getCurrentPassengers() == 2);

    std::cout << "[SUCCESS] " << "Test Vehicle isFull-False passed\n";
}

void testBoardPassenger()
{
    Car car(101, 4, {0,0}, 4, 0);

    assert(car.boardPassenger());
    assert(car.getCurrentPassengers() == 1);

    assert(car.boardPassenger());
    assert(car.getCurrentPassengers() == 2);

    assert(car.boardPassenger());
    assert(car.getCurrentPassengers() == 3);

    assert(car.boardPassenger());
    assert(car.getCurrentPassengers() == 4);

    assert(car.isFull());

     std::cout << "[SUCCESS] " << "Test Vehicle board passenger passed\n";
}

int main()
{
    testConstructor();
    testBusGetters();
    testCarGetters();
    testIsFullInitiallyFalse();
    testBoardPassenger();

    std::cout << "\nAll Vehicle tests passed successfully.\n";

    return 0;
}