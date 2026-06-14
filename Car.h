/**
 * @file Car.h
 * @brief Definición de la clase Car.
 *
 * @details
 * Representa un vehiculo de tipo Car en el juego. Implementa los atributos y metodos 
 * incluidos en la clase padre de Vehiculo.
 * 
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   Car
 *
 * Responsabilidades:
 *   - Representar un vehiculo de tipo Car en el juego.
 *   - Contiene informacion sobre el estado espacial, usando posicion y direccion, con un tamaño fijo de 2.
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

#include "Vehicle.h"

#ifndef CAR_H
#define CAR_H

class Car : public Vehicle {
    
    public:
        Car(
            int ID, 
            int color, 
            std::pair<int, int> location, 
            int direction,
            int currentPassengers);

    
        std::string getType() const override;
    
};

#endif // CAR_H