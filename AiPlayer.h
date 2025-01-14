#pragma once
using namespace std;
#include "Player.h"
#include "Ships.h"
#include "Grid.h"

#include <cstdlib> // For std::rand(), std::srand()
#include <ctime>   // For std::time()

class AiPlayer : public Player{

    public:
        AiPlayer(const char* name);
        ~AiPlayer();
        void placeAllShips();
        //void makeMove(Player* opponent);
        int getRandomCoordinate();
};