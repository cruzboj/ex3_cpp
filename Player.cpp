#include "Player.h"
using namespace std;

char getShipChar(int i);

Player::Player(const char *name)
{
    playerName = new char[strlen(name) + 1];
    strcpy(playerName, name);
    ships[0] = new Carrier;
    ships[1] = new Battleship;
    ships[2] = new Cruiser;
    ships[3] = new Submarine;
    ships[4] = new Destroyer;
}

void Player::displayGrid()
{
    getGrid().PrintGrid();
}

Player::~Player()
{
    cout << playerName << " player Destractor" << endl;
    delete[] playerName;
}

void Player::PlaceShip(int row, int col, bool horizontal, Ship *ship)
{
    int inBounds = 0;
    while (inBounds = 0)
    {

        if (grid.inBounds(row, col, ship->getSize(), horizontal))
        {
            grid.placeShip(row, col, ship->getSize(), horizontal, 'S');
            inBounds = 1;
        }
        else
        {
            cout << "Ship Out of bounds" << endl;
        }
    }
}

void Player::placeAllShips()
{
    for (int i = 0; i < MaxShips; i++)
    {
        cout << "Ship:" << i + 1<< " Size: " << ships[i]->getSize() << endl;
        int row = 0, col = 0;
        bool horizontal = 0;
        cout << "Row:";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << "Horizontal(0 For Vertical/1 For horizontal):";
        cin >> horizontal;
        cout << row << col << horizontal << endl;
        if (grid.inBounds(row, col, ships[i]->getSize(), horizontal))
        {
            int IsOccupied = 0;
            if (horizontal == 1)
            {
                for (int j = col; j < col + ships[i]->getSize(); j++)
                {
                    if (grid.isTileOccupied(row - 1, j - 1) == true)
                    {
                        cout << "Occupied" << endl;
                        IsOccupied++;
                    }
                }
                if (IsOccupied == 0)
                {
                    grid.placeShip(row, col, ships[i]->getSize(), horizontal, getShipChar(i));
                    grid.PrintGrid();
                }
                else
                {
                    i--;
                }
            }
            else if (horizontal == 0)
            {
                for (int j = row; j < row + ships[i]->getSize(); j++)
                {
                    if (grid.isTileOccupied(j - 1, col - 1) == true)
                    {
                        cout << "Occupied" << endl;
                        IsOccupied++;
                    }
                }
                if (IsOccupied == 0)
                {
                    grid.placeShip(row, col, ships[i]->getSize(), horizontal, getShipChar(i));
                    grid.PrintGrid();
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
}

char getShipChar(int i) {
    switch (i){
        case 0:
            return 'C';
        case 1:
            return 'B';
        case 2:
            return 'R';
        case 3:
            return 'S';
        case 4:
            return 'D';
        default:
            return '~';
    }
}