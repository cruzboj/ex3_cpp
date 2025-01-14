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

<<<<<<< HEAD
        virtual void placeAllShips();
};
=======
class Player {
protected:
    const char* playerName;
    Ship * ships[5];
    Grid grid;
public:
    
    Player(const char* name) : playerName(name){};

    virtual ~Player();

    virtual void placeAllShips() = 0; //pure virtual
    virtual void makeMove(Player* opponent) = 0; //pure virtual

    bool allShipsSunk() const;

    void displayMyGrid() const;

    // Grid getGrid() {return grid;}
    // Ship * getShips(){return *ships;}
};

#endif
>>>>>>> ede2f4fc1362571e37be2c27ccbcc4d6a51498e6
