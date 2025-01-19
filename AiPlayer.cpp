#include "AiPlayer.h"

AiPlayer::AiPlayer(const char *name) : Player(name) {}

int AiPlayer::getRandomCoordinate()
{
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
        int row = 0, col = 0;
        bool horizontal = 0;
        row = getRandomCoordinate();
        col = getRandomCoordinate();
        horizontal = rand0or1();
        if (getGrid().inBounds(row, col, getShip(i)->getSize(), horizontal))
        {
            int IsOccupied = 0;
            if (horizontal == 1)
            {
                for (int j = col; j < col + getShip(i)->getSize(); j++)
                {
                    if (getGrid().isTileOccupied(row - 1, j - 1) == true)
                    {
                        IsOccupied++;
                    }
                }
                if (IsOccupied == 0)
                {
                    getGrid().placeShip(row, col, getShip(i)->getSize(), horizontal, getShipChar(i));
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
                        IsOccupied++;
                    }
                }
                if (IsOccupied == 0)
                {
                    getGrid().placeShip(row, col, getShip(i)->getSize(), horizontal, getShipChar(i));
                }
                else
                    i--;
            }
        }
        else
        {
            i--;
            continue;
        }
    }
}

AiPlayer::~AiPlayer()
{
    cout << playerName << "AI Destractor" << endl;
    delete[] playerName;
    for(int i = 0 ; i < MaxShips ; i++)
        delete ships[i];
}

void AiPlayer::makeMove(Player *opponent)
{
    int row = getRandomCoordinate() - 1;
    int col = getRandomCoordinate() - 1;
    if (opponent->getGrid().isTileOccupied(row, col))
    {
        char cell = opponent->getGrid().getCell(row, col);
        int ship_index = getShipint(cell);
        opponent->getShip(ship_index)->takeHit();
        // std::cout << opponent->getShip(ship_index)->getHits() << std::endl;
        opponent->getGrid().markHit(row, col);
    }
    else
    {
        opponent->getGrid().markMiss(row, col);
    }
    std::cout << "Player's grid:" << std::endl;
    opponent->displayGrid();
}