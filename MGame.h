/**
 * @file MGame.h
 * @brief Definición de la clase MGame.
 *
 * @details
 * Actua como una clase Modelo, es capaz de obtener de leer un archivo de texto plano para instanciar
 * los componentes del juego. Almacena el estado de la partida durante la ejecución.
 * 
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   MGame
 *
 * Responsabilidades:
 *   - Mantener un registro del estado actual del juego.
 *   - Leer archivos de texto con la configuracion para el inicio del nivel.
 *   - Orquestar el ciclo de vida de sus componentes (Grid y Parking Zone).
 *   - Administrar la memoria y los punteros a objetos.
 *   - Exponer el estado del juego mediante metodos de acceso.
 *
 * Colaboradores:
 *   - Vehicle - Bus y Car:
 *     * Crea instancias y las almacena en el vector correspondiente.
 *   - Passenger:
 *     * Crea instancias y las almacena y las almacena en el vector correspondiente.
 *   - Grid:
 *     * Encapsula e instancia un objeto de esta clase.
 *   - ParkingZone:
 *     * Encapsula e instancia un objeto de esta clase.
 *   - CGame (Controlador del Juego):
 *     * Manipula directamente a MGame usando sus metodos para cambiar el estado del juego.
 *   - VGame (Vista del Juego):
 *     * Consulta sus componentes para presentarlos al usuario.
 *
 * -----------------------------------------------------------------------------
 *
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

#ifndef MGAME_H
#define MGAME_H

#include "Vehicle.h"
#include "Grid.h"
#include "Passenger.h"
#include "Bus.h"
#include "Car.h"
#include "Parkingzone.h"
#include <string>
#include <vector>
#include <utility>
#include <memory>

class MGame{

    private: 
        int level;
        int vehicleQuantity;
        int passengersQuantity;
        std::vector<Vehicle*> vehicles;
        std::vector<Passenger*> passengerQueue;
        std::unique_ptr<Grid> grid;
        std::unique_ptr<ParkingZone> parkingZone;

    public:
        MGame(int level);
        void loadLevel(std::string filePath);
        void removeVehicle(int VehicleID);

        //Getters
        int getLevel() const;
        int getVehicleQuantity() const;
        int getPassengersQuantity() const;
        Grid& getGrid();
        ParkingZone& getParkingZone() const;
        std::vector<Vehicle*> getVehicles() const;
        std::vector<Passenger*>& getPassengers();

};

#endif // MGAME_H