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
    // Player test("yoav");
    // test.placeAllShips();
    // test.displayGrid();

    // // Seed the random number generator for AI placement and moves
    // // You need it to stay HERE when you use random in the AiPlayer class
    // std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // std::srand(std::time(0));

    // // Create two players: one human, one AI
    Player *p1 = new HumanPlayer("Human");
    Player *p2 = new AiPlayer("Computer");
    Game game(p1, p2);
    game.setup();
    game.start();
    // p1->placeAllShips();
    // p1->displayGrid();
    // cout << "\n"
    //      << endl;

    // p2->placeAllShips();
    // p2->displayGrid();
    // cout << "\n"
    //      << endl;
    // int IsWinner = 0;

    // while (true)
    // {
    //     p1->makeMove(p2);
    //     if (p2->allShipsSunk())
    //     {
    //         cout << "Human Wins" << endl;
    //         break;
    //     }
    //     p2->makeMove(p1);
    //     if (p1->allShipsSunk())
    //     {
    //         cout << "Computer Wins" << endl;
    //         break;
    //     }
    // }
    // // Create the Game object with the two players

    // // Set up the game (place all ships)

    // // Start the turn-by-turn gameplay

    // // If needed, you could delete the players here, but assume Game or Player destructors handle cleanup.
    // // delete p1;
    // // delete p2;

    return 0;
}