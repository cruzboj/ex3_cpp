//Grid.ccp

#include "Grid.h"

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