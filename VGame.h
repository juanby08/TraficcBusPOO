/*
 * @file VGame.h
 * @brief Definición de la clase VGame.
 *
 * @details
 * Funciona como una clase de tipo Vista. Se encarga de mostrar los datos en la consola, representa
 * los atributos y el color de los elementos en el Modelo del juego mediante códigos ANSI.
 * 
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   VGame
 *
 * Responsabilidades:
 *   - Imprime el tablero (Grid) del juego.
 *   - Obtiene la informacion de color de los elementos del juego para representarlos correctamente.
 *   - Muestra graficamente el estado de la Parking Zone.
 *   - Muestra la cola de pasajeros manteniendo el orden e indicando su color.
 *   - Provee de una interfaz general para imprimir cadenas de texto.
 *
 * Colaboradores:
 *   - MGame (Modelo del Juego):
 *     * Provee la informacion necesaria para que VGame pueda imprimir de manera correcta el estado del juego.
 *   - CGame (Controlador del Juego):
 *     * Invoca los metodos publicos de la vista durante cada interaccion para actualizar el estado del juego
 *       en la pantalla.
 *   - Grid:
 *     * Extrae el estado del tablero para imprimir.
 *   - ParkingZone:
 *     * Obtiene los vectores de vehiculos y pasajeros para presentarlos en consola.
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

#ifndef VGAMEB_H
#define VGAMEB_H

#include "MGame.h"
#include <string>

class VGame {
private:
    // ANSI color codes for different colors. Reset goes back to original console print color.
    const std::string reset = "\033[0m";
    const std::string green = "\033[32m";   //  green = 1
    const std::string blue = "\033[34m";    //  blue = 2
    const std::string yellow = "\033[33m";  //  yellow = 3
    const std::string red = "\033[31m";     //  red = 4

    std::string getColorCode(int colorNum) const;
    int getVehicleColorAt(MGame& game, int r, int c, char cell) const;

public:

    VGame() = default;

    void printBoard(MGame& game);
    void DisplayText(const std::string& text);
    void printParkingZone(MGame& game);
    void printPassengerQueue(MGame& game);
};

#endif // VGAMEB_H