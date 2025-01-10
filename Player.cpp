//player.cpp

#include "Player.h"

Player::Player(const char* name){
        ships[0] = new Carrier();
        ships[1] = new Battleship();
        ships[2] = new Cruiser();
        ships[3] = new Submarine();
        ships[4] = new Destroyer();
    }

Player::~Player() {
    for (int i = 0; i < 5; ++i) {
        delete ships[i];  // שחרור זיכרון של כל ספינה
    }
}

bool Player::allShipsSunk()const{
    for (int i = 0; i < 5; ++i) {
            if (!ships[i]->isSunk()) {
                return false;
            }
        }
        return true;
}

void Player::displayMyGrid()const{
        grid.printGrid();
}