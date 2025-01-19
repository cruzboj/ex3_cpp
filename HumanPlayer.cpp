#include "HumanPlayer.h"

int getShipint(char ship_char)
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

HumanPlayer::HumanPlayer(const char* name) : Player(name){}

void HumanPlayer::placeAllShips()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < MaxShips; i++)
    {
        
        cout << "Ship:" << i + 1<< " Size: " << getShip(i)->getSize() << endl;
        int row = 0, col = 0;
        bool horizontal = 0;
        cout << "Row:";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << "Horizontal(0 For Vertical/1 For horizontal):";
        cin >> horizontal;
        //cout << row << col << horizontal << endl;

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
                    //getGrid().PrintGrid();
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
                    //getGrid().PrintGrid();
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

HumanPlayer::~HumanPlayer(){
    cout << playerName << " player Destractor" << endl;
    delete[] playerName;
}

void HumanPlayer::makeMove(Player* opponent)
{
    
    int row = 0, col = 0;
    cout << "Enter row: ";
    cin >> row;
    cout << "Enter column: ";
    cin >> col;
    if(row > 10 || col > 10){
        cout << "Invalid input" << endl;
        return;
    }
    if(opponent->getGrid().isTileOccupied(row-1, col-1)){
        char cell = opponent->getGrid().getCell(row-1, col-1);
        int ship_index = getShipint(cell);
        if(ship_index == -1){
            cout << "Invalid input" << endl;
            return;
        }
        opponent->getShip(ship_index)->takeHit();
        
        opponent->getGrid().markHit(row-1, col-1);
        //cout << "Hit" << endl;
    }
    else{
        opponent->getGrid().markMiss(row-1, col-1);
        cout << "Miss" << endl;
    }
    opponent->displayGrid();
    cout << "\n"<<endl;
}