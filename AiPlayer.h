#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "Player.h"
#include <cstdlib>
#include <ctime>

class AiPlayer : public Player {
public:
    AiPlayer(const char* name) : Player(name) {}

    void placeAllShips();

    void makeMove(Player* opponent);
};

#endif
