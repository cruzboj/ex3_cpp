#ifndef SHIP_H
#define SHIP_H

#include "main.cpp"

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
        Carrier();
};

class Battleship : public Ship {
    public:
        Battleship();
};

class Cruiser : public Ship {
    public:
        Cruiser();
};

class Submarine : public Ship {
    public:
        Submarine();
};

class Destroyer : public Ship {
    public:
        Destroyer();
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