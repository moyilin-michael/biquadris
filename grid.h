#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "cell.h"

struct Grid {
    string infile;
    int index;
    int score;
    int level;
    char curblock;
    char nextblock;
    std::vector<std::pair<int, int>>blockpos;
    std::vector<Cell*>grid;
    std::vector<char>sequence;
    Grid(string file);
    ~Grid();
    void initialize();
    int setDefault();
    bool ifleft();
    bool ifright();
    bool ifdown();
    void left();
    void right();
    void down();
    void drop();
    void rowScore();
    void rowsDelete();
    void update();
    void printNext1();
    void printNext2();
};

#endif
