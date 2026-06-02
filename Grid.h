// Curso: Fundamentos de Programación Orientada a Objetos
// Archivo: Grid.h
// Autores:
// - Camilo Espinal León | Código: 2538740| camilo.espinal@correounivalle.edu.co
// 
// Fecha: 1/06/2026

/**
 * @file Grid.h
 * @brief Definición de la clase Grid.
 *
 * @details
 * Implementa la abstracción del entorno de juego representado como un
 * laberinto bidimensional. La clase Grid es responsable de gestionar
 * la estructura interna del mapa, permitir su carga desde archivo,
 * y ofrecer acceso controlado a sus celdas.
 *
 * -----------------------------------------------------------------------------
 * Estándar CRC (Clase - Responsabilidad - Colaboración)
 * -----------------------------------------------------------------------------
 *
 * Clase:
 *   Grid
 *
 * Responsabilidades:
 *   - Representar el Mapa como una matriz bidimensional.
 *   - Cargar la configuración del nivel/mapa desde un archivo externo (.txt).
 *   - Proporcionar acceso controlado a las celdas del mapa.
 *   - Gestionar y almacenar el nivel actual del juego.
 *
 * Colaboradores:
 *   - MGAME:
 *     * Mostrar gráficamente el nivel en consola.
 *   - Vehicle:
 *       * Consulta el estado de las celdas del mapa.
 *       * Utiliza la información del mapa para validar movimientos.
 *
 *
 * -----------------------------------------------------------------------------
 *
 * @author Camilo Espinal León | Código: 2538740|
 * @email camilo.espinal@correounivalle.edu.co
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

// Candado: Evita la doble declaración
#ifndef _GRID_H_
#define _GRID_H_
#include <vector>
#include <string>
using namespace std;

// Nombre clase
class Grid
{
  // atributos
  private: 
    string level; //Almacena el nivel del juego
    int n;
    int m;
    vector<vector<int>> Map;//El vector de vectores 1 y 0 mapa

  // métodos
  public:
  Grid();   // Método constructor
    int getBus(int x, int y);// Retorna el valor de la celda en la posición (x, y)
    void getLevel(string auxlevelname);   // Retorna el nivel del juego
};
// Cierro el candado
#endif