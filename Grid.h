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
    std::tuple<int,int,char> getDirection(const Vehicle& vehicle);

    public: 
    Grid(int columns,int rows);
    void addVehicle(const Vehicle& vehicle);
    bool checkPath(const Vehicle& vehicle);

    //getters
    std::vector<std::vector<char>> getBoard();
    int getRows() const;
    int getColumns() const;

    };
#endif // GRID_H