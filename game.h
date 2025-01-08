// Game.h
#ifndef GAME_H
#define GAME_H
#include "Player.h"

class Game {
private:
    Player* player1;
    Player* player2;

public:
    Game(Player* p1, Player* p2) : player1(p1), player2(p2) {}

    void setup() {
        player1->placeAllShips();
        player2->placeAllShips();
    }

    void start() {
    
    }
};

#endif
