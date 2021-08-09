#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <utility>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <stdlib.h> 
#include <cmath>
#include "grid.h"
#include "game.h"
#include "display.h"
#include "window.h"
#include "block.h"

using namespace std;

int main(int argc, char * argv[])
{
    int turn = 1;
    Game *game = new Game();
    string scriptfile1 = "";
    string scriptfile2 = "";
    Grid *player1 = game->getPlayer1();
    Grid *player2 = game->getPlayer2();
    time_t seed = 1;
    bool iftext = false;

    if(argc >= 2){
		for(int start = 1; start < argc; start++) {
            if(argv[start] == "-scriptfile1") {
                scriptfile1 = argv[start + 1];
                player1->cLevel->updateSeq(scriptfile1);
                player1->setcurrentblock(player1->cLevel->currentc);
                player1->setnextblock(player1->cLevel->nextc);
            } 
            if(argv[start] == "-scriptfile2") {
                scriptfile2 = argv[start + 1];
                player2->setcurrentblock(player2->cLevel->currentc);
                player2->setnextblock(player2->cLevel->nextc);
            }
            if(argv[start] == "-startlevel") {
                int newlevel = stoi(argv[counter + 1]);
                player1->leveln = newlevel;
                player2->leveln = newlevel;
            }
            if(argv[start] == "-seed") {
                seed = stoi(argv[counter + 1]);
            }
            if(argv[start] == "-text") {
                iftext = true;
            }
        }
    }

    game->printGame();
    string strans;
    vector<string> lst;

    while(cin >> strans){
        if(strans == "sequence"){
			string fileName;
			cin >> fileName;
			ifstream fi{fileName};
			string s;
			while(fi >> s){
				lst.push_back(s);
			}
		} else {
			lst.push_back(strans);
		}

       while(lst.size() != 0){
			string sinput = lst[lst.size() - 1];
			int times = 0;
			int i = 0;
            while(true) {
                if(times[i] <= '9' && times[i] >= '0') {
                    times += (times[i] - '0') * pow(10, i);
                    i++;
                } else {
                    break;
                }
            }

            if(times == 0) {
                times= 1;
            }

            string inputaction = sinput.substr(i);  
            char c = inputaction[0];
            
            if ((c == 'I') || (c == 'J') || (c == 'L') || (c == '0') || (c == 'S') || (c == 'Z') || (c == 'T')) {
                if(turn == 1) {
                    player1->setcurrentblock(c);
                    lst.pop_back();
                    game->printGame();
                } else {
                    player2->setcurrentblock(c);
                    lst.pop_back();
                    game->printGame();
                }  

            } else if(c == 'l') {
				//left
				//leveldown
				//levelup

                if(inputaction.length() >= 3) {           //
                    if(inputaction.[2] == 'f'){
                      if(turn == 1) {
                        player1->move_left(times);  
                        lst.pop_back();
                        g->printGame();
                      } else {
                        player2->move_left(times);  
                        lst.pop_back();
                        g->printGame();
                      }
                    }
                }

                if(inputaction.length() >= 6) {
                      if(inputaction.[5] == 'd'){
                         if(turn == 1) {
                            player1->level -= 1 * times;  
                            lst.pop_back();
                            g->printGame();
                        } else {
                            player2->level -= 1 * times; 
                            lst.pop_back();
                            g->printGame();
                        }
                    }
		      if(inputaction.[5] == 'u'){
                         if(turn == 1) {
			    player1->level += 1 * times;
                            lst.pop_back();
                            g->printGame();
                        } else {
                            player2->level += 1 * times;  
                            lst.pop_back();
                            g->printGame();
                        }
                    }
                }

            } else if(inputaction.[0] == 'r'){
				//right
				//restart
				//random

		if(inputaction.length() >= 2){
		   if(inputaction[1] == 'i'){
		     if(turn == 1) {
                        player1->move_right(times);  
                        lst.pop_back();
                        game->printGame();
                      } else {
                        player2->move_right(times);  
                        lst.pop_back();
                        game->printGame();
                      }

					} else if(inputaction[1] == 'e'){
						delete game;
						game = new Game();
						Grid *player1 = game->getPlayer1();
   						Grid *player2 = game->getPlayer2();
					    lst.pop_back();
						turn = 1;
						game->printGame();

					} else if(inputaction[1] == 'a'){
						if((turn == 1)&&(player1->ifrandom == false)) {
							if(player1->leveln == 3 || player1->leveln == 4){
								player1->ifrandom = true;
								lst.pop_back();
								game->printGame();
							}
						} else if ((turn == 2)&&(player2->ifrandom == false)) {
							if(player2->leveln == 3 || player2->leveln == 4){
								player2->ifrandom = true;
								lst.pop_back();
								game->printGame();
							}
						}

					} else if (inputaction[0] == 'n'){
						//norandom
						if ((turn == 1)&&(player1->ifrandom == true)) {
							string file;
							cin >> file;
							player1->level.updateSeq(file);
							lst.pop_back();
							player1->ifrandom = false;
							game->printGame();
						} else if ((turn == 2)&&(player2->ifrandom == true)) {
							string file;
							cin >> file;
							player2->level.updateSeq(file);
							lst.pop_back();
							player2->ifrandom = false;
							game->printGame();
						}

				}
				}

					} else if (inputaction[0] == 'd'){
						//down	
						//drop
						if(inputaction.length() >= 2){
							if(inputaction[1] == 'o'){
								if(turn == 1) {
									player1->move_down(times);  
									lst.pop_back();
									game->printGame();
								} else {
									player2->move_down(times);  
									lst.pop_back();
									game->printGame();
								}

						} else if(inputaction[1] == 'r'){
								if(turn == 1) {
									player1->drop();
								} else {
									player2->drop();
								}
						}
					}

					} else if (inputaction[0] == 'c'){
						//clockwise
						//counterclockwise
						if(inputaction.length() >= 2){
							if(inputaction[1] == 'l' || inputaction[1] == 'w'){
								if(turn == 1) {
									for(int i = 0; i < times; i++) {
										player1->rclockwise();  
									}
									lst.pop_back();
									game->printGame();
								} else {
									for(int i = 0; i < times; i++) {
										player2->rclockwise();  
									}
									lst.pop_back();
									game->printGame();
								}
							}
							if(inputaction[1] == 'o' || inputaction[1] == 'c'){
								if(turn == 1) {
									player1->rcounterclockwise();  
									lst.pop_back();
									game->printGame();
								} else {
									player2->rcounterclockwise(); 
									lst.pop_back();
									game->printGame();
								}
							}
						}
					}

			if (player1->checklose() == true) {	
				string winmessage = "Game is over - Player 2 wins!";
				cout << winmessage << std::endl;
				delete game;
			} else if (player2->checklose() == true) {
				string winmessage = "Game is over - Player 1 wins!";
				cout << winmessage << std::endl;
				delete game;
			}

	   }
	   delete game;           
}
