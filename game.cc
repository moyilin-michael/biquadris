#include <iostream>
#include "game.h"
using namespace std;

Game::Game() {
    player1 = new Grid("sequence1.txt");
    player2 = new Grid("sequence2.txt");
}

Game::~Game() {
    delete player1;
    delete player2;
}

void Game::renewp1() {
	if (player1 != nullptr) {
		string s1 = player1->infile;
	        delete player1;
	        player1 = new Grid(s1);
	}
}

void Game::renewp2() {
	if (player2 != nullptr) {
		string s2 = player2->infile;
	        delete player2;
	        player2 = new Grid(s2);
	}
}
	

void Game::printGame(){
    cout << "Level:    " << player1->level << "     " << "Level:    " << player2->level << endl;
    cout << "Score:    " << player1->score << "     " << "Score:    " << player2->score << endl;
   
    cout << "***********     ***********" << endl;
    for (int row = 0; row < 18; row++) {
        for (int col1 = 0; col1 < 11; col1++) {
            if (player1->grid[row * 11 + col1]->returnType() == 'N') {
                cout << ' ';
            }
            else {
                cout << player1->grid[row * 11 + col1]->returnType();
            }
        }
        cout << "     ";
        for (int col2 = 0; col2 < 11; col2++) {
           if (player2->grid[row * 11 + col2]->returnType() == 'N') {
                cout << ' ';
            }
            else {
                cout << player2->grid[row * 11 + col2]->returnType();
            }
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

Grid* Game::getPlayer1() {
    return player1;
}

Grid* Game::getPlayer2() {
    return player2;
}
