#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include "grid.h"

struct Game {
    Grid* player1;
    Grid* player2;
    Game();
    ~Game();
    void printGame();
    Grid* getPlayer1();
    Grid* getPlayer2();
};

#endif
