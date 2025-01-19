#include "HumanPlayer.h"



HumanPlayer::HumanPlayer(const char *name) : Player(name) {}

void HumanPlayer::placeAllShips()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < MaxShips; i++)
    {

        cout << "Ship:" << i + 1 << " Size: " << getShip(i)->getSize() << endl;
        int row = 0, col = 0;
        bool horizontal = 0;
        cout << "Row:";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << "Horizontal(0 For Vertical/1 For horizontal):";
        cin >> horizontal;

        if (getGrid().inBounds(row, col, getShip(i)->getSize(), horizontal))
        {
            int IsOccupied = 0;
            if (horizontal == 1)
            {
                for (int j = col; j < col + getShip(i)->getSize(); j++)
                {
                    if (getGrid().isTileOccupied(row - 1, j - 1) == true)
                    {
                        cout << "Occupied" << endl;
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
                        cout << "Occupied" << endl;
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
            cout << "Out of Bounds" << endl;
            i--;
            continue;
        }
    }
    cout << endl <<  "All Ships are placed \n" << endl;
}

HumanPlayer::~HumanPlayer()
{
    delete[] playerName;
    for(int i = 0; i<MaxShips; i++){
        delete ships[i];
    }
}

void HumanPlayer::makeMove(Player *opponent)
{
    int AvailableMove = 0;
    while (AvailableMove == 0)
    {
        int row = 0, col = 0;
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> col;
        if (row > 10 || col > 10)
        {
            cout << "Invalid input" << endl;
            return;
        }
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
                opponent->getShip(ship_index)->takeHit();
                opponent->getGrid().markHit(row - 1, col - 1);
                AvailableMove = 1;
            }
        }
        else
        {
            opponent->getGrid().markMiss(row - 1, col - 1);
            AvailableMove = 1;
        }
    }
    std::cout << "AI Grid" << std::endl;
    opponent->displayGrid();
    cout << "\n"
         << endl;
}