#include "Player.h"
using namespace std;


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

Player::~Player(){}

void Player::PlaceShip(int row, int col, bool horizontal, Ship *ship)
{
    int inBounds = 0;
    while (inBounds = 0)
    {

        if (getGrid().inBounds(row, col, ship->getSize(), horizontal))
        {
            inBounds = 1;
        }
        else
        {
            cout << "Ship Out of bounds" << endl;
        }
    }
}

bool Player::allShipsSunk() const
{
    for (int i = 0; i < MaxShips; i++)
    {
        if (getShip(i)->isSunk() == false)
        {
            return false;
        }
    }
    return true;
}

char Player::getShipChar(int i) {
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

int Player::getShipint(char ship_char)
{
    switch (ship_char)
    {
    case 'C':
        return 0;
    case 'B':
        return 1;
    case 'R':
        return 2;
    case 'S':
        return 3;
    case 'D':
        return 4;
    }
    return -1;
}