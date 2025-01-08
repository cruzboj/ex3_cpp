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

//Grid.ccp
Grid::Grid(){
    for(int i = 0; i < 10 ; i++)
        for(int j = 0; j <10 ;j++)
            cells[i][j] = '~';
}

bool Grid::isTileOccupied(int row, int col) const{
    return cells[row][col] == 'S' || cells[row][col] == 'X';
}

bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const{
    if (horizontal) {
            return col + shipSize <= 10;
        } else {
            return row + shipSize <= 10;
        }
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol){
    for (int i = 0; i < shipSize; ++i) {
            if (horizontal) {
                cells[row][col + i] = symbol;
            } else {
                cells[row + i][col] = symbol;
            }
        }
}

void Grid::markHit(int row, int col) {
        cells[row][col] = 'X';
}
void Grid::markMiss(int row, int col) {
        cells[row][col] = 'M';
}

void Grid::printGrid() const {
        std::cout << "   A B C D E F G H I J" << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << i + 1 << "  ";
            for (int j = 0; j < 10; ++j) {
                std::cout << cells[i][j] << " ";
            }
            std::cout << std::endl;
        }
}
#endif