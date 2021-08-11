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

void Game::printGame(){
    cout << "Level:    " << player1->level << "     " << "Level:    " << player2->level << endl;
    cout << "Score:    " << player1->score << "     " << "Score:    " << player2->score << endl;
   
    cout << "***********     ***********" << endl;
    for (int row = 0; row < 15; row++) {
        for (int col1 = 0; col1 < 11; col1++) {
            cout << player1->grid[row * 11 + col1].c;
        }
        cout << "     ";
        for (int col2 = 0; col2 < 11; col2++) {
            cout << player1->grid[row * 11 + col2].c;
        }
        cout << endl;
    }

    cout << "***********     ***********" << endl;
    cout << "Next:           Next:      " << endl;
    
    player1->printNext1();
    cout << "            ";
    player2->printNext1();
    cout << endl;
    player1->printNext2();
    cout << "            ";
    player2->printNext2();
    cout << endl;
}

Game* Game::getPlayer1() {
    return player1;
}

Game* Game::getPlayer2() {
    return player2;
}
