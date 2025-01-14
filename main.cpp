#include <iostream>
#include <cstdlib> // For std::rand(), std::srand()
#include <ctime>   // For std::time()
// #include "Game.h"
// #include "AiPlayer.h"
#include "Ships.h"
#include "Grid.h"
#include "Player.h"
#include "HumanPlayer.h"

int main()
{
    // Player test("yoav");
    // test.placeAllShips();
    // test.displayGrid();

    

    // // Seed the random number generator for AI placement and moves
    // // You need it to stay HERE when you use random in the AiPlayer class
    // std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // // Create two players: one human, one AI
    Player* p1 = new HumanPlayer("Human");
    p1->placeAllShips();
    p1->displayGrid();
    // Player* p2 = new AiPlayer("Computer");

    // // Create the Game object with the two players
    // Game game(p1, p2);

    // // Set up the game (place all ships)
    // game.setup();

    // // Start the turn-by-turn gameplay
    // game.start();

    // // If needed, you could delete the players here, but assume Game or Player destructors handle cleanup.
    // // delete p1;
    // // delete p2;

    return 0;
}