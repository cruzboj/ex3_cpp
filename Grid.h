#ifndef GRID_H
#define GRID_H
#include "main.cpp"

class Grid{
        char cells[10][10]; //`'~'` for empty, `'S'` for ship, `'X'` for hit, `'M'` for miss.
    public:
        Grid();
        //Returns true if the cell indicates a ship or a previously hit cell.
        bool isTileOccupied(int row, int col) const;
        //Checks if placing a ship of length `shipSize` at `(row, col)` horizontally/vertically stays within the 10×10 grid.
        bool inBounds(int row, int col, int shipSize, bool horizontal) const;
        //Marks each relevant cell with `symbol` (e.g., `'S'`) if valid.
        void placeShip(int row, int col, int shipSize, bool horizontal, char symbol);
        
        void markHit(int row, int col);
        
        void markMiss(int row, int col);
        
        char getCell(int row, int col) const{return cells[row][col];}
        
        void printGrid()const;
};


#endif