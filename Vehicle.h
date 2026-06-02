/*
Información CRC:

Clase: Vehicle

Responsabilidades:
- Definir los atributos y metodos comunes para los objetos de tipo vehiculo en el tablero

Colaboradores:

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.

    
    Autor: 
    Correo: 
    Fecha: Mayo 2026
*/
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <utility>
#include "globaldefinitions.h"

    class Vehicle{
    protected:

        int ID;
        Color color; //Color sera definido en un header como una estructura de enum que contenga los colores (GREEN, YELLOW, BLUE, RED)
        std::pair<int,int> location;
        Direction direction;// Direction sera definido en un header como una estructura de enum que contenga las direcciones (UP, DOWN, LEFT, RIGHT)
        int size;

    public:
        Vehicle(int ID, Color color, std::pair<int,int> location, Direction direction, int size);
        virtual ~Vehicle() = default;
        Color getColor() const;
        int getID() const;
        std::pair<int,int> getLocation() const;
        int getSize() const;
        Direction getDirection() const;
    };

#endif // VEHICLE_H
