/**
 * @file Grid.h
 * @brief Definición de la clase Grid.
 *
 * @details
 * Define los atributos y metodos encargados de representar un tablero bidimensional.
 * Guarda el estado visual de los vehiculos, mostrando su ID y direccion, ademas valida caminos libres
 * en el tablero.
 * 
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   Grid
 *
 * Responsabilidades:
 *   - Crea una matriz bidimensional de caracteres que representan el tablero del juego.
 *   - Traduce la orientacion del vehiculo en simbolos visualmente identificables.
 *   - Registra cada vehiculo al interior del tablero, guardando su posicion e indicando su ID y direccion.
 *   - Evalua si la trayectoria del vehiculo se encuentra libre de obstaculos.
 *   - Permite limpiar el tablero para volver a su estado inicial.
 *
 * Colaboradores:
 *   - Vehicle:
 *     * Le provee de la infirmacion de estado del vehiculo (ID, dirección, tamaño y ubicación)
 *   - MGame (Modelo del Juego):
 *     * Usa a grid para guardar la informacion del estado global del juego.
 *   - CGame (Controlador del Juego):
 *     * Invoca los metodos para alterar el estado del tablero (addVehicle, cleanBoard).
 *   - VGame (Vista del Juego):
 *     * Consulta la matriz de caracteres para presentarlos al usuario.
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

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>
#include "Vehicle.h"

    class Grid{

    private:

    int rows;
    int columns;
    std::vector<std::vector<char>> board;

    public: 
    
    Grid(int columns,int rows);
    void addVehicle(const Vehicle& vehicle);
    bool checkPath(const Vehicle& vehicle);

    //getters
    std::vector<std::vector<char>> getBoard();
    int getRows() const;
    int getColumns() const;
    void clearBoard();
    static std::tuple<int,int,char> getDirection(const Vehicle& vehicle);

    };
#endif // GRID_H