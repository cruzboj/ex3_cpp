#include <iostream>
#pragma once
const int MaxGrid = 10;

class Grid{
    private:
    char cells[MaxGrid][MaxGrid];
    public:
<<<<<<< HEAD
    Grid();
    void PrintGrid();
    bool isTileOccupied(int row,int col) const;
    bool inBounds(int row, int col, int shipSize, bool horizontal) const;
    void placeShip(int row, int col, int shipSize, bool horizontal, char symbol);
    void markHit(int row, int col);
    void markMiss(int row, int col);
    char getCell(int row, int col) const;
};
=======
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
>>>>>>> ede2f4fc1362571e37be2c27ccbcc4d6a51498e6
