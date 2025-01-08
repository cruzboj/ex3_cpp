#ifndef SUBMARINE_H
#define SUBMARINE_H
#include "Ship.h"

class Submarine : public Ship {
public:
    Submarine() : Ship("Submarine", 3) {}
};

#endif