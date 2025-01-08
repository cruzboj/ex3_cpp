#ifndef DESTROYER_H
#define DESTROYER_H
#include "Ship.h"

class Destroyer : public Ship {
public:
    Destroyer() : Ship("Destroyer", 2) {}
};

#endif