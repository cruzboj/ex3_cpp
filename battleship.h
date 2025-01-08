#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "Ship.h"

class Battleship  : public Ship {
    public:
        Battleship () : Ship("Battleship ", 5) {}
};

#endif