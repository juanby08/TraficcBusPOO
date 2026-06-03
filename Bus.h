/**
 * @file Bus.h
 * @brief Definición de la clase Bus.
 *
 * @details
 * Representa un vehiculo de tipo Bus en el juego. Implementa los atributos y metodos 
 * incluidos en la clase padre de Vehiculo.
 * 
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   Bus
 *
 * Responsabilidades:
 *   - Representar un vehiculo de tipo Bus en el juego.
 *   - Contiene informacion sobre el estado espacial, usando posicion direccion y tamaño variable.
 *   - Controla el flujo de pasajeros, permitiendo abordar y verificar capacidad maxima.
 *
 * Colaboradores:
 *   - Vehicle - Clase Padre:
 *     * Hereda la estructura de atributos y metodos.
 *   - globaldefinitions:
 *     * Toma las estructuras de color, direccion y vehicletype.
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


#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

    class Bus : public Vehicle {

    public: 

        Bus(
            int ID, 
            Color color, 
            std::pair<int,int> location, 
            Direction direction, 
            int size, 
            int capacity
        );

        VehicleType getType() const override;

    };
#endif // BUS_H