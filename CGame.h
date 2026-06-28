/**
 * @file CGame.h
 * @brief Definición de la clase CGame.
 *
 * @details
 * Actua como una clase Controlador, orquesta el ciclo principal del juego, procesa y valida las acciones
 * tomadas por parte del usuario, y determina la condicion de victoria o derrota en el juego.
 * 
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   CGame
 *
 * Responsabilidades:
 *   - Ejecutar y mantener el loop principal del juego.
 *   - Recibe y procesa las entradas por consola del usuario.
 *   - Evalua las solicitudes de movimiento de vehiculos.
 *   - Controla la logica de abordaje de los pasajeros.
 *   - Revisa si se cumplen las condiciones de Victoria o Derrota tras cada interaccion.
 *
 * Colaboradores:
 *   - MGame (Modelo del Juego):
 *     * Es el componente que guarda los datos, el controlador modifica y consulta activamente la informacion
 *       guardada en el mismo.
 *   - VGame (Vista del Juego):
 *     * Colabora directamente para renderizar la interfaz en consola e imprimir mensajes.
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


#ifndef CGAME_H
#define CGAME_H

#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include "MGame.h"
#include <string>
#include <vector>
#include <utility>
#include <thread>
#include <chrono>
#include "VGame.h"


class CGame {
    private: 

        int gameStatus;
        MGame* level;
        VGame* display;

        char handleInput();
    
    public:

        CGame(MGame* level, VGame* display);
        void updateGrid();
        int play();
        bool boarding();

};

#endif // CGAME_H