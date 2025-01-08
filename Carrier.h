#ifndef CARRIER_H
#define CARRIER_H
#include "Ship.h"

class Carrier : public Ship {
    public:
        Carrier() : Ship("Carrier", 5) {}
};

#endif