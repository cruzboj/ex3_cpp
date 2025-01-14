// #pragma once
// using namespace std;
// #include "Player.h"
// #include "Ships.h"
// #include "Grid.h"

// char getShipChar(int i) {
//     switch (i){
//         case 0:
//             return 'C';
//         case 1:
//             return 'B';
//         case 2:
//             return 'R';
//         case 3:
//             return 'S';
//         case 4:
//             return 'D';
//         default:
//             return '~';
//     }
// }

// class HumanPlayer : public Player{

//     public:
//         HumanPlayer(const char* name);
//         ~HumanPlayer();
//         void placeAllShips();
// };

// void HumanPlayer::placeAllShips()
// {
//     for (int i = 0; i < MaxShips; i++)
//     {
//         cout << "Ship:" << i + 1<< " Size: " << ships[i]->getSize() << endl;
//         int row = 0, col = 0;
//         bool horizontal = 0;
//         cout << "Row:";
//         cin >> row;
//         cout << "Column: ";
//         cin >> col;
//         cout << "Horizontal(0 For Vertical/1 For horizontal):";
//         cin >> horizontal;
//         cout << row << col << horizontal << endl;
//         if (grid.inBounds(row, col, ships[i]->getSize(), horizontal))
//         {
//             int IsOccupied = 0;
//             if (horizontal == 1)
//             {
//                 for (int j = col; j < col + ships[i]->getSize(); j++)
//                 {
//                     if (grid.isTileOccupied(row - 1, j - 1) == true)
//                     {
//                         cout << "Occupied" << endl;
//                         IsOccupied++;
//                     }
//                 }
//                 if (IsOccupied == 0)
//                 {
//                     grid.placeShip(row, col, ships[i]->getSize(), horizontal, getShipChar(i));
//                     grid.PrintGrid();
//                 }
//                 else
//                 {
//                     i--;
//                 }
//             }
//             else if (horizontal == 0)
//             {
//                 for (int j = row; j < row + ships[i]->getSize(); j++)
//                 {
//                     if (grid.isTileOccupied(j - 1, col - 1) == true)
//                     {
//                         cout << "Occupied" << endl;
//                         IsOccupied++;
//                     }
//                 }
//                 if (IsOccupied == 0)
//                 {
//                     grid.placeShip(row, col, ships[i]->getSize(), horizontal, getShipChar(i));
//                     grid.PrintGrid();
//                 }
//                 else
//                     i--;
//             }
//         }
//         else
//         {
//             cout << "Out of Bounds" << endl;
//             i--;
//             continue;
//         }
//     }
// }