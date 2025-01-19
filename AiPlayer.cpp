#include "AiPlayer.h"

AiPlayer::AiPlayer(const char *name) : Player(name) {}

int AiPlayer::getRandomCoordinate()
{
    // Ensure srand(...) is called in main
    return std::rand() % 10 + 1;
}
int rand0or1()
{
    return std::rand() % 2;
}

void AiPlayer::placeAllShips()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < MaxShips; i++)
    {
        // cout << "Ship:" << i + 1<< " Size: " << getShip(i)->getSize() << endl;
        int row = 0, col = 0;
        bool horizontal = 0;
        // cout << "Row:";
        row = getRandomCoordinate();
        // cout << "Column: ";
        col = getRandomCoordinate();
        // cout << "Horizontal(0 For Vertical/1 For horizontal):";
        horizontal = rand0or1();
        // cout << row << col << horizontal << endl;
        if (getGrid().inBounds(row, col, getShip(i)->getSize(), horizontal))
        {
            int IsOccupied = 0;
            if (horizontal == 1)
            {
                for (int j = col; j < col + getShip(i)->getSize(); j++)
                {
                    if (getGrid().isTileOccupied(row - 1, j - 1) == true)
                    {
                        // cout << "Occupied" << endl;
                        IsOccupied++;
                    }
                }
                if (IsOccupied == 0)
                {
                    getGrid().placeShip(row, col, getShip(i)->getSize(), horizontal, getShipChar(i));
                    // getGrid().PrintGrid();
                }
                else
                {
                    i--;
                }
            }
            else if (horizontal == 0)
            {
                for (int j = row; j < row + getShip(i)->getSize(); j++)
                {
                    if (getGrid().isTileOccupied(j - 1, col - 1) == true)
                    {
                        // cout << "Occupied" << endl;
                        IsOccupied++;
                    }
                }
                if (IsOccupied == 0)
                {
                    getGrid().placeShip(row, col, getShip(i)->getSize(), horizontal, getShipChar(i));
                    // getGrid().PrintGrid();
                }
                else
                    i--;
            }
        }
        else
        {
            // cout << "Out of Bounds" << endl;
            i--;
            continue;
        }
    }
}

AiPlayer::~AiPlayer()
{
    cout << playerName << "AI Destractor" << endl;
    delete[] playerName;
}

void AiPlayer::makeMove(Player *opponent)
{
    int row = getRandomCoordinate() - 1;
    int col = getRandomCoordinate() - 1;
    if (opponent->getGrid().isTileOccupied(row, col))
    {
        opponent->getGrid().markHit(row, col);
        cout << "Hit" << endl;
    }
    else
    {
        opponent->getGrid().markMiss(row, col);
    }
    std::cout << "Player's grid:" << std::endl;
    opponent->displayGrid();
}