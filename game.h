#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "grid.h"

struct Game {
    Grid* player1;
    Grid* player2;
    int hi;
    Game();
    ~Game();
    void printGame();
    Game* getPlayer1();
    Game* getPlayer2();
};

#endif
