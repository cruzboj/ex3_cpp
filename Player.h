#ifndef PLAYER_H
#define PLAYER_H
#include "Ship.h"
#include "Grid.h"


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