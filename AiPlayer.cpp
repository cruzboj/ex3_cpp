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
    for (int i = 0; i < MaxShips; i++)
        delete ships[i];
}

void AiPlayer::makeMove(Player *opponent)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int availableMove = 0;
    while (availableMove == 0)
    {
        int row = getRandomCoordinate();
        int col = getRandomCoordinate();
        cout << row << " " << col << endl;
        if (opponent->getGrid().isTileOccupied(row - 1, col - 1))
        {
            char cell = opponent->getGrid().getCell(row - 1, col - 1);
            int ship_index = getShipint(cell);
            if (ship_index == -1)
            {
                cout << "Invalid input" << endl;
                continue;
            }
            else
            {
                availableMove = 1;
                opponent->getShip(ship_index)->takeHit();
                opponent->getGrid().markHit(row - 1, col - 1);
            }
        }
        else
        {
            availableMove = 1;
            opponent->getGrid().markMiss(row - 1, col - 1);
        }
    }
    std::cout << "Player's grid:" << std::endl;
    opponent->displayGrid();
}