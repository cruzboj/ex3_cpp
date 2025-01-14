#ifndef SHIP_H
#define SHIP_H

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
        //int getSize() const {return size;}
        //const char* getName() const {return name;}
};

class Carrier : public Ship {
    public:
        Carrier() : Ship("Carrier", 5) {}
};

class Battleship : public Ship {
    public:
        Battleship () : Ship("Battleship ", 4) {}
};

class Cruiser : public Ship {
    public:
        Cruiser() :  Ship("Cruiser", 3) {}
};

class Submarine : public Ship {
    public:
        Submarine() : Ship("Submarine", 3) {}
};

class Destroyer : public Ship {
    public:
        Destroyer() : Ship("Destroyer", 2) {}
};

#endif