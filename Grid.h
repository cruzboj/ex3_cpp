#include <iostream>
#pragma once
const int MaxGrid = 10;

class Grid{
    private:
    char cells[MaxGrid][MaxGrid];
    public:
    Grid();
    void PrintGrid();
    bool isTileOccupied(int row,int col) const;
    bool inBounds(int row, int col, int shipSize, bool horizontal) const;
    void placeShip(int row, int col, int shipSize, bool horizontal, char symbol);
    void markHit(int row, int col);
    void markMiss(int row, int col);
    char getCell(int row, int col) const;
};