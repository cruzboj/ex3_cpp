<<<<<<< HEAD
#include "Grid.h"

Grid::Grid()
{
    for (int i = 0; i < MaxGrid; i++)
    {
        for (int j = 0; j < MaxGrid; j++)
        {
            cells[i][j] = '~';
        }
    }
}

void Grid::PrintGrid()
{
    for (int i = 0; i < MaxGrid; i++)
    {
        for (int j = 0; j < MaxGrid; j++)
        {
            std::cout << cells[i][j];
        }
        std::cout << std::endl;
    }
}
bool Grid::isTileOccupied(int row, int col) const
{
    if (cells[row][col] == '~')
        return false;
    else
        return true;
}
bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
{
    if (horizontal == true)
    {
        if (col + shipSize < MaxGrid)
        {
            return true;
        }
        else
            return false;
    }
    else
    {
        if (row + shipSize <= MaxGrid)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol){
    if (horizontal == true){
        for(int i = col; i < col+shipSize; i++){
            cells[row-1][i-1] = symbol;
        }
    }
    else {
        for (int i = row; i<row+shipSize; i++){
            cells[i-1][col-1] = symbol;
        }
    }
}

void Grid::markHit(int row, int col){
    cells[row][col] = 'X';
}

void Grid::markMiss(int row,int col){
    cells[row][col] = 'M';
}

char Grid::getCell(int row, int col) const
{
    if (row < 10 && col < 10)
        return cells[row][col];
    else
        std::cout << "Error, cell out of line" << std::endl;
=======
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
>>>>>>> ede2f4fc1362571e37be2c27ccbcc4d6a51498e6
}