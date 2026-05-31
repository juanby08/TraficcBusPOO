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
        //constructor Vehicle(int id){}
        virtual ~Vehicle() {}
        virtual void MoveFoward() = 0;
        Color getColor();
        int getID();

    };

#endif // VEHICLE_H