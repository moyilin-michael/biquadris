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

int main(int argc, char *argv[])
{
	int turn = 1;
	Game *game = new Game();
	string scriptfile1 = "";
	string scriptfile2 = "";
	Grid *player1 = game->getPlayer1();
	Grid *player2 = game->getPlayer2();
	time_t seed = 1;
	bool iftext = false;
	bool win = false;

	if (argc >= 2)
	{
		for (int start = 1; start < argc; start++)
		{
			if (argv[start] == "-scriptfile1")
			{
				scriptfile1 = argv[start + 1];
				player1->infile = scriptfile1;
				start++;
				/*player1->cLevel->updateSeq(scriptfile1);
				player1->setcurrentblock(player1->cLevel->currentc);
				player1->setnextblock(player1->cLevel->nextc); */
			}

			if (argv[start] == "-scriptfile2")
			{
				scriptfile2 = argv[start + 1];
				player2->infile = scriptfile2;
				start++;
				/*player2->cLevel->updateSeq(scriptfile2);	//
                    player2->setcurrentblock(player2->cLevel->currentc);
                    player2->setnextblock(player2->cLevel->nextc); */
			}

			/*if (argv[start] == "-startlevel")
			{
				int newlevel = stoi(argv[counter + 1]);
			    player1->leveln = newlevel;
			    player2->leveln = newlevel;
			}*/

			/*if (argv[start] == "-seed")
			{
				seed = stoi(argv[counter + 1]);
			}*/

			if (argv[start] == "-text")
			{
				iftext = true;
			}
		}
	}

	game->printGame();
	string strans;
	std::vector<string> lst;

	while (cin >> strans)
	{
		if (strans == "sequence")
		{
			string fileName;
			cin >> fileName;
			ifstream fi
			{
				fileName
			};
			string s;
			while (fi >> s)
			{
				lst.push_back(s);
			}
		}
		else
		{
			lst.push_back(strans);
		}

		int i = 0;
		while (i != lst.size())
		{ /*string sinput = lst[lst.size() - 1];
				int times = 0;
				int i = 0;
				while (true)
				{
					if (times[i] <= '9' && times[i] >= '0')
					{
						times += (times[i] - '0') *pow(10, i);
						i++;
					}
					else
					{
						break;
					}
				}

				if (times == 0)
				{
					times = 1;
				}

				string inputaction = sinput.substr(i);
				char c = inputaction[0]; */

			string sinput = lst[i];
			char c = sinput[0];

			/*if ((c == 'I') || (c == 'J') || (c == 'L') || (c == '0') || (c == 'S') || (c == 'Z') || (c == 'T'))
			{
				if (turn == 1)
				{
					player1->setcurrentblock(c);
					lst.pop_back();
					game->printGame();
				}
				else
				{
					player2->setcurrentblock(c);
					lst.pop_back();
					game->printGame();
				}
			}*/

			if (c == 'l')
			{
			 	//left
				//leveldown
				//levelup

				if (sinput.length() >= 3)	//
				{
					if (sinput[2] == 'f')
					{
						if (turn == 1)
						{
							player1->move_left();
							g->printGame();
						}
						else
						{
							player2->move_left();
							g->printGame();
						}
					}
				}

				if (sinput.length() >= 6)
				{
					if (sinput[5] == 'd')
					{
						if (turn == 1)
						{
							player1->level -= 1;
							g->printGame();
						}
						else
						{
							player2->level -= 1;
							g->printGame();
						}
					}

					if (sinput[5] == 'u')
					{
						if (turn == 1)
						{
							player1->level += 1;
							g->printGame();
						}
						else
						{
							player2->level += 1;
							g->printGame();
						}
					}
				}
			}
			else if (c == 'r')
			{
			 	//right
				//restart
				//random

				if (sinput.length() >= 2)
				{
					if (sinput[1] == 'i')
					{
						if (turn == 1)
						{
							player1->move_right();
							game->printGame();
						}
						else
						{
							player2->move_right();
							game->printGame();
						}
					}
					else if (sinput[1] == 'e')
					{
						delete game;
						game = nullptr;
						game = new Game();
						Grid *player1 = game->getPlayer1();
						Grid *player2 = game->getPlayer2();
						turn = 1;
						game->printGame();
					}
				}
			}
			else if (c == 'd')
			{
			 	//down	
				//drop
				if (sinput.length() >= 2)
				{
					if (sinput[1] == 'o')
					{
						if (turn == 1)
						{
							player1->move_down();
							game->printGame();
						}
						else
						{
							player2->move_down();
							game->printGame();
						}
					}
					else if (sinput[1] == 'r')
					{
						if (turn == 1)
						{
							player1->drop();
							turn = 2;
							game->printGame();	//
						}
						else
						{
							player2->drop();
							turn = 1;
							game->printGame();	//
						}
					}
				}
			}

			if (player1->checklose() == true)
			{
				string winmessage = "Game is over - Player 2 wins!";
				cout << winmessage << std::endl;
				delete game;
				game = nullptr;
				win = true;
				break;
			}
			else if (player2->checklose() == true)
			{
				string winmessage = "Game is over - Player 1 wins!";
				cout << winmessage << std::endl;
				delete game;
				game = nullptr;
				win = true;
				break;
			}
			i++;
		}
		if (win == true) {
		    break;
		}
	}
	if (game != nullptr) {
	    delete game;
	    game = nullptr;
	}
}
