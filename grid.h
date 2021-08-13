#ifndef _GRID_H_
#define _GRID_H_
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "BaseCell.h"
#include "BlockCell.h"
using namespace std;

struct Grid {
    string infile;
    int index;
    int score;
    int level;
    char curblock;
    char nextblock;
    std::vector<std::pair<int, int>>blockpos;
    std::vector<Cell *> grid;
    std::vector<char>sequence;
    Grid(string file);
    ~Grid();
    void initialize();
    int setDefault();
    bool ifleft();
    bool ifright();
    bool ifdown();
    bool ifclock();
    bool ifanti();
    void clock();
    void anti();
    void left();
    void right();
    void down();
    void drop();
    void rowScore();
    void rowDelete(int num);
    void rowsDelete();
    void update();
    void printNext1();
    void printNext2();
};

#endif
