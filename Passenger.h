/*
 * @file Passenger.h
 * @brief Definición de la clase Passenger.
 *
 * @details
 * Representa de forma individual a un pasajero en la lógica del juego. Guarda y encapsula su color
 * permitiendo a otras clases acceder al atributo pero no modificarlo.
 * 
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   Passenger
 *
 * Responsabilidades:
 *   - Almacenar y encapsular la informacion de color perteneciente a cada passajero.
 *   - Permitir a otras clases consultar el atributo de color.
 *
 * Colaboradores:
 *   - MGame (Modelo del Juego):
 *     * Mediante un vector de punteros de tipo Passenger estructura una fila o "PassengerQueue".
 *   - CGame (Controlador del Juego):
 *     * Consulta el color del pasajero a la cabeza de la fila para compararlo con los buses en la Parking Zone.
 *   - VGame (Vista del Juego):
 *     * Lee el color de cada pasajero para imprimirlo correctamente en la consola.
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

#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger {
private:
    int color; // 1 = Green, 2 = Blue, 3 = Yellow, 4 = Red

public:
    Passenger(int auxColor);

    int getColor() const;
};

#endif