#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <utility>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "grid.h"
#include "game.h"
using namespace std;

int main(int argc, char *argv[])
{
	int turn = 1;
	int hi = 0;
	int time = 1;
	Game* game = new Game();
	string scriptfile1 = "";
	string scriptfile2 = "";
	Grid *player1 = game->getPlayer1();
	Grid *player2 = game->getPlayer2();

	if (argc >= 2)
	{
		for (int start = 1; start < argc; start++)
		{
			if (strcmp(argv[start], "-scriptfile1") == 0)
			{
				scriptfile1 = argv[start + 1];
				player1->infile = scriptfile1;
				start++;
			}

			if (strcmp(argv[start], "-scriptfile2") == 0)
			{
				scriptfile2 = argv[start + 1];
				player2->infile = scriptfile2;
				start++;
			}

		}
	}
	
	player1->initialize();
	player2->initialize();
        player1->setDefault(); 
	player2->setDefault();
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
		{ 
			string sinput = lst[i];
			int numcount = 0;
			for (int j = 0; j < sinput.length(); ++j) {
				if (sinput[j] >= 48 && sinput[j] <= 57) {
					numcount++;
				}
				else {
					break;
				}
			}
			
			if (numcount > 0) {
				time = stoi(sinput.substr(0, numcount - 1));
				sinput = sinput.substr(numcount, sinput.length() - 1);
			}
			char c = sinput[0];
			
			if(time == 0) {
				continue;
			}

			if (c == 'l')
			{
			 	//left
				//leveldown
				//levelup

				if (sinput.length() >= 3)	//
				{
					if (sinput[2] == 'f')
					{
						for (int a = 0; a < time; ++a) {
							if (turn == 1)
						        {
							     player1->left();
						        }
						        else
						        {
							     player2->left();
						        }
						}
						game->printGame();
					}
				}

				if (sinput.length() >= 6)
				{
					if (sinput[5] == 'd')
					{
						for (int b = 0; b < time; ++b) {
							if (turn == 1)
						        {
							     player1->level -= 1;
						        }
						        else
						        {
							     player2->level -= 1;
						        }
						}
						game->printGame();
					}

					if (sinput[5] == 'u')
					{
						for (int c = 0; c < time; ++c) {
							if (turn == 1)
						        {
							     player1->level += 1;
						        }
						        else
						        {
							     player2->level += 1;
						        }
						}
						game->printGame();
					}
				}
			}
			else if (c == 'r')
			{
			 	//right
				//restart

				if (sinput.length() >= 2)
				{
					if (sinput[1] == 'i')
					{
						for (int d = 0; d < time; ++d) {
							if (turn == 1)
						        {
							     player1->right();
						        }
						        else
						        {
							     player2->right();
						        }
						}
						game->printGame();
					}
					else if (sinput[1] == 'e')
					{
						delete game;
						game = nullptr;
						game = new Game();
						player1 = game->getPlayer1();
						player2 = game->getPlayer2();
						turn = 1;
						player1->initialize();
	                                        player2->initialize();
	                                        player1->setDefault();
	                                        player2->setDefault();
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
						for (int e = 0; e < time; ++e) {
							if (turn == 1)
						        {
							     player1->down();
						        }
						        else
						        {
							     player2->down();
						        }
						}
						game->printGame();
					}
					else if (sinput[1] == 'r')
					{
						if (turn == 1)
						{
							for (int f = 0; f < time; ++f) {
								player1->drop();
							        player1->rowScore();
							        player1->rowsDelete();
							        hi = max(hi, max(player1->getScore(), player2->getScore()));
							        player1->update();
							        int n = player1->setDefault();
							        if (n == 0) {
								     string winmessage = "Game is over - Player 2 wins!";
				                                     cout << winmessage << std::endl;
				                                     delete game;
				                                     game = nullptr;
								     return 1;
							        }
							}
							turn = 2;
							game->printGame();	//
						}
						else
						{
							for (int g = 0; g < time; ++g) {
								player2->drop();
							        player2->rowScore();
							        player2->rowsDelete();
							        hi = max(hi, max(player1->getScore(), player2->getScore()));
							        player2->update();
							        int m = player2->setDefault();
							        if (m == 0) {
								     string winmessage = "Game is over - Player 1 wins!";
				                                     cout << winmessage << std::endl;
				                                     delete game;
				                                     game = nullptr;
								     return 1;
							        }
							}
							turn = 1;
							game->printGame();	//
						}
					}
				}
			}
			time = 1;
			i++;
		}
		lst.clear();
	 }
	delete game;
}
