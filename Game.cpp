#include "Game.h"

Game::Game(Player *p1, Player *p2)
{
    player1 = p1;
    player2 = p2;
}

Game::~Game()
{
    delete player1;
    delete player2;
}

bool Game::isGameOver() const
{
    if (player1->allShipsSunk() || player2->allShipsSunk())
        return true;
    else
        return false;
}

void Game::setup()
{
    player1->placeAllShips();
    player2->placeAllShips();
}

void Game::start()
{

    std::cout << std::endl << "Please enter a move" << std::endl;
    while (!isGameOver())
    {
        player1->makeMove(player2);
        if (player2->allShipsSunk())
        {
            std::cout << player1->getName() <<" wins!" << std::endl;
            break;
        }
        player2->makeMove(player1);
        if (player1->allShipsSunk())
        {
            std::cout <<player2->getName() <<" wins!" << std::endl;
            break;
        }
    }
}