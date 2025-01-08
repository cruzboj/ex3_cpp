#ifndef SHIP_H
#define SHIP_H

#include <cstring>

class Ship{
        char* name; 
        int size;
        int hitsTaken;
    public:
        Ship(const char* shipName, int shipSize);
        virtual ~Ship();
        virtual void takeHit();
        bool isSunk() const;

        //geters
        int getSize() const {return size;}
        const char* getName() const {return name;}
};

class Carrier : public Ship {
    public:
        Carrier() : Ship("Carrier", 5) {}
};

class Battleship : public Ship {
    public:
        Battleship () : Ship("Battleship ", 5) {}
};

class Cruiser : public Ship {
    public:
        Cruiser() : Ship("Cruiser", 3) {}
};

class Submarine : public Ship {
    public:
        Submarine() : Ship("Submarine", 3) {}
};

class Destroyer : public Ship {
    public:
        Destroyer() : Ship("Destroyer", 2) {}
};

//Ship.cpp
Ship::Ship(const char* shipName, int shipSize) {
    size = shipSize;
    hitsTaken = 0;
    name = new char[strlen(shipName) + 1];
    strcpy(name, shipName);
}

Ship::~Ship() {
    delete[] name;
}

void Ship::takeHit() {
    hitsTaken++;
    std::cout << name << " got hit!" << std::endl;
}

bool Ship::isSunk() const {
    return hitsTaken >= size;
}

#endif