#pragma once
using namespace std;
#include "Player.h"
#include "Ships.h"
#include "Grid.h"

class HumanPlayer : public Player{

    public:
        HumanPlayer(const char* name);
        ~HumanPlayer();
        void placeAllShips();
};
