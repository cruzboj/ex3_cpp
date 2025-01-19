#ifndef PLAYER_H
#define PLAYER_H
#include "Ships.h"
#include "Grid.h"
const int MaxShips = 5;

class Player{
    protected:
        char *playerName;
        Grid grid;
        Ship* ships[5];
    public:
        Player(const char* name);
        virtual ~Player() = 0;
        void PlaceShip(int row, int col,bool horizontal, Ship *ship);
        void displayGrid();
        
        virtual void placeAllShips() = 0;
        //virtual void placeAllShips();
        //added
        virtual void makeMove(Player* opponent)=0;

        bool allShipsSunk() const;
        
        //getters
        Grid &getGrid() { return grid; }
        Ship* getShip(int i) const {return ships[i];}
        
        virtual char getShipChar(int i);
};

#endif