#ifndef GAME_H
#define GAME_H
#include "Player.h"

class Game{
    private:
        Player* player1;
        Player* player2;
    public:
        Game(Player* p1, Player* p2);
        ~Game();
        void setup();
        void start();
        bool isGameOver() const;
};

#endif