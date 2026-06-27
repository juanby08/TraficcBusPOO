// Curso: Fundamentos de Programacion Orientada a Objetos
// Archivo: Grid.cpp
// Autores:
// - Juan Ricardo Riaños Horta | Código: 2537573 | juan.rianos@correounivalle.edu.co
// - Carlos Anibal Ceron del Castillo | Código: 2537097 | carlos.ilich.ceron@correounivalle.edu.co
// - Anyela Lineth Cabrera Ordoñez | Código: 2540031 | anyela.cabrera@correounivalle.edu.co
// - Camilo Espinal León | Código: 2538740 | camilo.espinal@correounivalle.edu.co
// - Juan José Peña Garcés | Código: 2538880 | juan.jose.pena@correounivalle.edu.co
// Fecha: 27/06/2026

#include "Grid.h"

Grid::Grid(int columns, int rows): columns(columns), rows(rows){
    board.resize(rows, std::vector<char>(columns, '.'));
}

std::tuple<int,int,char> Grid::getDirection(const Vehicle& vehicle){

    int direction = vehicle.getDirection();

    int dx = 0;
    int dy = 0;
    char symbol;
    // 1 = Up, 2 = Down, 3 = Left, 4 = Right
    switch (direction){
        case 1:
            dx = -1;
            symbol = '^'; 
            break;
        case 2:
            dx = 1;
            symbol = 'v';
            break;
        case 3:
            dy = -1;
            symbol = '<';
            break;
        case 4:
            dy = 1;
            symbol = '>';
            break;
    }

    return {dx, dy, symbol};
}

void Grid::addVehicle(const Vehicle& vehicle){

    //def variables
    int id = vehicle.getID();
    std::pair<int,int> location = vehicle.getLocation();
    int size = vehicle.getSize();

    auto [dx, dy, symbol] = getDirection(vehicle);

    //Creating Vehicle body
    for (int i = 0; i < size - 1; i++){
        // 48 + id works with digits from 0 to 9
        board[location.first + i*dx][location.second + i*dy] = '0' + id; 
    }

    //Creating Vehicle head
    board[location.first + (size-1) * dx][location.second + (size-1) * dy] = symbol;
        
    }

bool Grid::checkPath(const Vehicle& vehicle){
    //def variables
    std::pair<int,int> location = vehicle.getLocation();
    int size = vehicle.getSize();

    auto [dx, dy, symbol] = getDirection(vehicle);

    int nextX = location.first + (size) * dx;
    int nextY = location.second + (size) * dy;

    while(
        nextX >= 0 && nextX < rows
        && nextY >= 0 && nextY < columns
        ){
        
            if (board[nextX][nextY] != '.'){
                return false;
            }

            nextX += dx;
            nextY += dy;
    }

    return true;
}

std::vector<std::vector<char>> Grid::getBoard(){
    return board;
}

int Grid::getRows() const{
    return rows;
}

int Grid::getColumns() const{
    return columns;
}

void Grid::clearBoard() {
    //Reassigns all the values on the board to be '.'
    board.assign(rows, std::vector<char>(columns, '.'));
}
