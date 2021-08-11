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
    void left();
    void right();
    void down();
    void drop();
    void compScore();
    void printNext1();
    void printNext2();
};

#endif
