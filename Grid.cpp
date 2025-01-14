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
        return ' ';
}