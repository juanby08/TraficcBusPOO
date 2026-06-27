/**
 * @file Vehicle.h
 * @brief Definición de la clase abstracta Vehiculo.
 *
 * @details
 * Define los atributos y metodos comunes a todos los objetos de tipo Vehiculo.
 * Funciona como una interfaz que encapsula el estado en el espacio, teniendo en 
 * cuenta posicion, tamaño y direccion, y controla la capacidad de pasajeros.
 * 
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   Vehicle
 *
 * Responsabilidades:
 *   - Definir atributos y metodos comunes para los objetos de tipo vehiculo.
 *   - Gestiona el estado en el espacio de los objetos (posicion, direccion, tamaño)
 *   - Controla el flujo de pasajeros, permitiendo abordar y verificar capacidad maxima.
 *
 * Colaboradores:
 *   - Bus - Clase Hija:
 *     * Hereda el comportamiento de vehiculo.
 *   - Car - Clase Hija:
 *     * Hereda el comportamiento de Car. 
 *
 * -----------------------------------------------------------------------------
 *
 * @author 
 * @email 
 * @license GNU General Public License v3.0 (GPL)
 *
 * Este programa es software libre: puede redistribuirlo y/o modificarlo
 * bajo los términos de la Licencia Pública General de GNU publicada por
 * la Free Software Foundation, ya sea la versión 3 de la Licencia, o
 * (a su elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; incluso sin la garantía implícita de
 * COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR.
 * Véase la Licencia Pública General de GNU para más detalles.
 *
 * Debería haber recibido una copia de la Licencia Pública General de GNU
 * junto con este programa. Si no, consulte <https://www.gnu.org/licenses/>.
 */


#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <utility>

    class Vehicle{
    protected:

        int ID;
        int color; // 1 = Green, 2 = Blue, 3 = Yellow, 4 = Red
        std::pair<int,int> location;
        int direction; // 1 = Up, 2 = Down, 3 = Left, 4 = Right
        int size;

        int capacity;
        int currentPassengers;

    public:

        Vehicle(
            int ID, 
            int color, 
            std::pair<int,int> location, 
            int direction, 
            int size,
            int capacity,
            int currentPassengers
            );

        virtual ~Vehicle() = default;
        int getColor() const;
        int getID() const;
        std::pair<int,int> getLocation() const;
        int getSize() const;
        int getDirection() const;

        int getCapacity() const;
        int getCurrentPassengers() const;

        bool boardPassenger();
        bool isFull();

        virtual std::string getType() const = 0;
    };

#endif // VEHICLE_H
