#ifndef CRUISER_H
#define CRUISER_H
#include "Ship.h"

class Cruiser : public Ship {
public:
    Cruiser() : Ship("Cruiser", 3) {}
};

#endif