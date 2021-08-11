#include <iostream>
#include "game.h"
using namespace std;

Game::Game() {
    player1 = new Grid;
    player2 = new Grid;
    hi = 0;
}

Game::~Game() {
    delete player1;
    delete player2;
}
