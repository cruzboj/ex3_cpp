#include <iostream>
#include <cstdlib> // For std::rand(), std::srand()
#include <ctime>   // For std::time()
#include "Game.h"
#include "AiPlayer.h"
#include "Ships.h"
#include "Grid.h"
#include "Player.h"
#include "HumanPlayer.h"

int main()
{
    Player *p1 = new HumanPlayer("Human");
    Player *p2 = new AiPlayer("Computer");
    Game game(p1, p2);
    game.setup();
    game.start();

    return 0;
}