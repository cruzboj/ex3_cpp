#include "Ships.h"
#include "Grid.h"
#pragma once
const int MaxShips = 5;

class Player{
    private:
        char *playerName;
        Grid grid;
    public:
        Ship* ships[5];
        Player(const char* name);
        virtual ~Player();
        // virtual void placeAllShips();
        void displayGrid();
        void PlaceShip(int row, int col,bool horizontal, Ship *ship);

        virtual void placeAllShips();
};