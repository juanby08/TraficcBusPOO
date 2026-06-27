/**
 * @file Parkingzone.h
 * @brief Definición de la clase ParkingZone.
 *
 * @details
 * Define los atributos y metodos encargados de gestionar la zona de parkeo para el juego.
 * Define esta zona de manera bidimensional como un vector, controla el espacio de los buses 
 * y la entrada y salida de los mismos.
 * 
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   ParkingZone
 *
 * Responsabilidades:
 *   - Crea el vector de punteros que representa el espacio de parqueo.
 *   - Gestiona el contenido del vector, permitiendo agregar y remover punteros a objetos tipo vehiculo.
 *
 * Colaboradores:
 *   - Vehicle:
 *     * Almacena un vector de punteros de tipo Vehiculo que representan Buses o Carros en la logica del juego.
 *   - MGame (Modelo del Juego):
 *     * Usa a parking zone para representar la informacion del estado del juego.
 *   - CGame (Controlador del Juego):
 *     * Invoca los metodos de "addBus" y "removeBus" para alterar el estado del parqueadero segun la 
 *       logica del juego.
 *   - VGame (Vista del Juego):
 *     * Lee la informacion de ParkingZone para mostrarla al usuario.
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

#ifndef PARKINGZONE_H
#define PARKINGZONE_H

#include <vector>
#include "Vehicle.h"

class ParkingZone {
private:
    std::vector<Vehicle*> parkedBuses;

    int row;
    int columns;

public:
    ParkingZone(int row, int columns);

    bool columnFree();

    bool addBus(Vehicle* vehicle);
    bool removeBus(int vehicleID);

    //getters
    std::vector<Vehicle*> getParkedBuses() const;

};

#endif