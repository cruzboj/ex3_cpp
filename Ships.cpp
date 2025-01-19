#include "Ships.h"

#pragma region Base

Ship::Ship(const char* shipName, int shipSize){
    name = new char[strlen(shipName)+1];
    strcpy(name,shipName);
    hitsTaken = 0;
    size = shipSize;
}

bool Ship::isSunk() const{
    if(hitsTaken >= size)
        return true;
    else
        return false;
}

void Ship::takeHit(){
    hitsTaken++;
    // std::cout << name << " got hit!" << std::endl;
    if(isSunk()){
        std::cout << name << " got sunk" << std::endl;
    }
}

Ship::~Ship(){
    std::cout << "Destructed " << name << std::endl;
    delete[] name;
}

#pragma endregion