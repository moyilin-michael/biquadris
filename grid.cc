#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid(string file) {
    infile = file;
    index = 1;
    score = 0;
    level = 0;
    for (int i = 0; i < 11 * 18; ++i) {
        grid.push_back(New Cell);
    }
}

Grid::~Grid() {
    for (int i = 0; i < 11 * 18; ++i) {
        delete grid[i];
    } 
    grid.clear();
    blockpos.clear();
    sequence.clear();
}

void Grid::initialize() {
    sequence.clear();
    ifstream inf{infile};
    char c;
    while(inf >> c) {
        if (c != ' ') {
            sequence.push_back(c);
        }
    }
    curblock = sequence[0];
    if (sequence.size() == 1) {
        nextblock = sequence[0];
    }
    else {
        nextblock = sequence[1];
    }
}

int Grid::setDefault() {
    if (curblock == 'I') {
        if (grid[33]->c = 'N' && grid[34]->c = 'N' && grid[35]->c = 'N' && grid[36]->c = 'N') {
            grid[33] = new BlockCell(grid[33], 'I');
            grid[34] = new BlockCell(grid[34], 'I');
            grid[35] = new BlockCell(grid[35], 'I');
            grid[36] = new BlockCell(grid[36], 'I');
            (grid[33]->friends).push_back(grid[34]);
            (grid[33]->friends).push_back(grid[35]);
            (grid[33]->friends).push_back(grid[36]);
            (grid[34]->friends).push_back(grid[33]);
            (grid[34]->friends).push_back(grid[35]);
            (grid[34]->friends).push_back(grid[36]);
            (grid[35]->friends).push_back(grid[33]);
            (grid[35]->friends).push_back(grid[34]);
            (grid[35]->friends).push_back(grid[36]);
            (grid[36]->friends).push_back(grid[33]);
            (grid[36]->friends).push_back(grid[34]);
            (grid[36]->friends).push_back(grid[35]);
            blockpos[0] = std::pair<int, int>(3, 0);
            blockpos[1] = std::pair<int, int>(3, 1);
            blockpos[2] = std::pair<int, int>(3, 2);
            blockpos[3] = std::pair<int, int>(3, 3);
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'J') {
        if (grid[33]->c = 'N' && grid[44]->c = 'N' && grid[45]->c = 'N' && grid[46]->c = 'N') {
            grid[33] = new BlockCell(grid[33], 'J');
            grid[44] = new BlockCell(grid[44], 'J');
            grid[45] = new BlockCell(grid[45], 'J');
            grid[46] = new BlockCell(grid[46], 'J');
            (grid[33]->friends).push_back(grid[44]);
            (grid[33]->friends).push_back(grid[45]);
            (grid[33]->friends).push_back(grid[46]);
            (grid[44]->friends).push_back(grid[33]);
            (grid[44]->friends).push_back(grid[45]);
            (grid[44]->friends).push_back(grid[46]);
            (grid[45]->friends).push_back(grid[33]);
            (grid[45]->friends).push_back(grid[44]);
            (grid[45]->friends).push_back(grid[46]);
            (grid[46]->friends).push_back(grid[33]);
            (grid[46]->friends).push_back(grid[44]);
            (grid[46]->friends).push_back(grid[45]);
            blockpos[0] = std::pair<int, int>(4, 0);
            blockpos[1] = std::pair<int, int>(3, 0);
            blockpos[2] = std::pair<int, int>(4, 1);
            blockpos[3] = std::pair<int, int>(4, 2);
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'L') {
        if (grid[44]->c = 'N' && grid[45]->c = 'N' && grid[46]->c = 'N' && grid[35]->c = 'N') {
            grid[44] = new BlockCell(grid[44], 'L');
            grid[45] = new BlockCell(grid[45], 'L');
            grid[46] = new BlockCell(grid[46], 'L');
            grid[35] = new BlockCell(grid[35], 'L');
            (grid[44]->friends).push_back(grid[45]);
            (grid[44]->friends).push_back(grid[46]);
            (grid[44]->friends).push_back(grid[35]);
            (grid[45]->friends).push_back(grid[44]);
            (grid[45]->friends).push_back(grid[46]);
            (grid[45]->friends).push_back(grid[35]);
            (grid[46]->friends).push_back(grid[44]);
            (grid[46]->friends).push_back(grid[45]);
            (grid[46]->friends).push_back(grid[35]);
            (grid[35]->friends).push_back(grid[44]);
            (grid[35]->friends).push_back(grid[45]);
            (grid[35]->friends).push_back(grid[46]);
            blockpos[0] = std::pair<int, int>(4, 0);
            blockpos[1] = std::pair<int, int>(4, 1);
            blockpos[2] = std::pair<int, int>(4, 2);
            blockpos[3] = std::pair<int, int>(3, 2);
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'O') {
        if (grid[44]->c = 'N' && grid[33]->c = 'N' && grid[45]->c = 'N' && grid[34]->c = 'N') {
            grid[44] = new BlockCell(grid[44], 'O');
            grid[33] = new BlockCell(grid[33], 'O');
            grid[45] = new BlockCell(grid[45], 'O');
            grid[34] = new BlockCell(grid[34], 'O');
            (grid[44]->friends).push_back(grid[33]);
            (grid[44]->friends).push_back(grid[45]);
            (grid[44]->friends).push_back(grid[34]);
            (grid[33]->friends).push_back(grid[44]);
            (grid[33]->friends).push_back(grid[45]);
            (grid[33]->friends).push_back(grid[34]);
            (grid[45]->friends).push_back(grid[44]);
            (grid[45]->friends).push_back(grid[33]);
            (grid[45]->friends).push_back(grid[34]);
            (grid[34]->friends).push_back(grid[44]);
            (grid[34]->friends).push_back(grid[33]);
            (grid[34]->friends).push_back(grid[45]);
            blockpos[0] = std::pair<int, int>(4, 0);
            blockpos[1] = std::pair<int, int>(3, 0);
            blockpos[2] = std::pair<int, int>(4, 1);
            blockpos[3] = std::pair<int, int>(3, 1);
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'S') {
        if (grid[44]->c = 'N' && grid[45]->c = 'N' && grid[34]->c = 'N' && grid[35]->c = 'N') {
            grid[44] = new BlockCell(grid[44], 'S');
            grid[45] = new BlockCell(grid[45], 'S');
            grid[34] = new BlockCell(grid[34], 'S');
            grid[35] = new BlockCell(grid[35], 'S');
            (grid[44]->friends).push_back(grid[45]);
            (grid[44]->friends).push_back(grid[34]);
            (grid[44]->friends).push_back(grid[35]);
            (grid[45]->friends).push_back(grid[44]);
            (grid[45]->friends).push_back(grid[34]);
            (grid[45]->friends).push_back(grid[35]);
            (grid[34]->friends).push_back(grid[44]);
            (grid[34]->friends).push_back(grid[45]);
            (grid[34]->friends).push_back(grid[35]);
            (grid[35]->friends).push_back(grid[44]);
            (grid[35]->friends).push_back(grid[45]);
            (grid[35]->friends).push_back(grid[34]);
            blockpos[0] = std::pair<int, int>(4, 0);
            blockpos[1] = std::pair<int, int>(4, 1);
            blockpos[2] = std::pair<int, int>(3, 1);
            blockpos[3] = std::pair<int, int>(3, 2);
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'Z') {
        if (grid[33]->c = 'N' && grid[45]->c = 'N' && grid[34]->c = 'N' && grid[46]->c = 'N') {
            grid[33] = new BlockCell(grid[33], 'Z');
            grid[45] = new BlockCell(grid[45], 'Z');
            grid[34] = new BlockCell(grid[34], 'Z');
            grid[46] = new BlockCell(grid[46], 'Z');
            (grid[33]->friends).push_back(grid[45]);
            (grid[33]->friends).push_back(grid[34]);
            (grid[33]->friends).push_back(grid[46]);
            (grid[45]->friends).push_back(grid[33]);
            (grid[45]->friends).push_back(grid[34]);
            (grid[45]->friends).push_back(grid[46]);
            (grid[34]->friends).push_back(grid[33]);
            (grid[34]->friends).push_back(grid[45]);
            (grid[34]->friends).push_back(grid[46]);
            (grid[46]->friends).push_back(grid[33]);
            (grid[46]->friends).push_back(grid[45]);
            (grid[46]->friends).push_back(grid[34]);
            blockpos[0] = std::pair<int, int>(3, 0);
            blockpos[1] = std::pair<int, int>(4, 1);
            blockpos[2] = std::pair<int, int>(3, 1);
            blockpos[3] = std::pair<int, int>(4, 2);
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'J') {
        if (grid[33]->c = 'N' && grid[45]->c = 'N' && grid[34]->c = 'N' && grid[35]->c = 'N') {
            grid[33] = new BlockCell(grid[33], 'L');
            grid[45] = new BlockCell(grid[45], 'L');
            grid[34] = new BlockCell(grid[34], 'L');
            grid[35] = new BlockCell(grid[35], 'L');
            (grid[33]->friends).push_back(grid[45]);
            (grid[33]->friends).push_back(grid[34]);
            (grid[33]->friends).push_back(grid[35]);
            (grid[45]->friends).push_back(grid[33]);
            (grid[45]->friends).push_back(grid[34]);
            (grid[45]->friends).push_back(grid[35]);
            (grid[34]->friends).push_back(grid[33]);
            (grid[34]->friends).push_back(grid[45]);
            (grid[34]->friends).push_back(grid[35]);
            (grid[35]->friends).push_back(grid[33]);
            (grid[35]->friends).push_back(grid[45]);
            (grid[35]->friends).push_back(grid[34]);
            blockpos[0] = std::pair<int, int>(3, 0);
            blockpos[1] = std::pair<int, int>(4, 1);
            blockpos[2] = std::pair<int, int>(3, 1);
            blockpos[3] = std::pair<int, int>(3, 2);
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

bool Grid::ifleft() {
    if (curblock == 'I' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'J' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->c == 'N' 
    && grid[blockpos[1].first * 11 + blockpos[1].second - 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'L' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->c == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second - 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'O' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->c == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second - 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'S' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->c == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second - 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'Z' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->c == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second - 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'T' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->c == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second - 1]->c == 'N') {
        return true;
    }
    else {
        return false;
    }
}

bool Grid::ifright() {
    if (curblock == 'I' && blockpos[3].second < 10 && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'J' && blockpos[3].second < 10 && grid[blockpos[1].first * 11 + blockpos[1].second + 1]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'L' && blockpos[3].second < 10 && grid[blockpos[2].first * 11 + blockpos[2].second + 1]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'O' && blockpos[3].second < 10 && grid[blockpos[2].first * 11 + blockpos[2].second + 1]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'S' && blockpos[3].second < 10 && grid[blockpos[1].first * 11 + blockpos[1].second + 1]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'Z' && blockpos[3].second < 10 && grid[blockpos[2].first * 11 + blockpos[2].second + 1]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->c == 'N') {
        return true;
    }
    else if (curblock == 'T' && blockpos[3].second < 10 && grid[blockpos[1].first * 11 + blockpos[1].second + 1]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->c == 'N') {
        return true;
    }
    else {
        return false;
    }
}

bool Grid::ifdown() {
    if (curblock == 'I' && blockpos[0].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->c == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second + 11]->c == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second + 11]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 11]->c == 'N') {
        return true;
    }
    else if (curblock == 'J' && blockpos[0].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->c == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second + 11]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 11]->c == 'N') {
        return true;
    }
    else if (curblock == 'L' && blockpos[0].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->c == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second + 11]->c == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second + 11]->c == 'N') {
        return true;
    }
    else if (curblock == 'O' && blockpos[0].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->c == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second + 11]->c == 'N') {
        return true;
    }
    else if (curblock == 'S' && blockpos[0].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->c == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second + 11]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 11]->c == 'N') {
        return true;
    }
    else if (curblock == 'Z' && blockpos[1].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->c == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second + 11]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 11]->c == 'N') {
        return true;
    }
    else if (curblock == 'T' && blockpos[1].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->c == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second + 11]->c == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 11]->c == 'N') {
        return true;
    }
    else {
        return false;
    }
}

void Grid::left() {
    if (ifleft() == true) {
        for (int i = 0; i < 4; ++i) {
            delete grid[blockpos[i].first * 11 + blockpos[i].second - 1];
            grid[blockpos[i].first * 11 + blockpos[i].second - 1] = grid[blockpos[i].first * 11 + blockpos[i].second];
            grid[blockpos[i].first * 11 + blockpos[i].second] = new BaseCell;
            blockpos[i].second -= 1;
        }
    }
}

void Grid::right() {
    if (ifright() == true) {
        for (int i = 3; i >= 0; --i) {
            delete grid[blockpos[i].first * 11 + blockpos[i].second + 1];
            grid[blockpos[i].first * 11 + blockpos[i].second + 1] = grid[blockpos[i].first * 11 + blockpos[i].second];
            grid[blockpos[i].first * 11 + blockpos[i].second] = new BaseCell;
            blockpos[i].second += 1;
        }
    }
}

void Grid::down() {
    if (ifdown() == true) {
        for (int i = 0; i < 4; ++i) {
            delete grid[blockpos[i].first * 11 + blockpos[i].second + 11];
            grid[blockpos[i].first * 11 + blockpos[i].second + 11] = grid[blockpos[i].first * 11 + blockpos[i].second];
            grid[blockpos[i].first * 11 + blockpos[i].second] = new BaseCell;
            blockpos[i].first += 1;
        }
    }
}

void Grid::drop() {
    while (ifdown() == true) {
        down();
    }
}

void Grid::rowScore() {
    bool full = true;
    int point = 0;
    for (int i = 17; i >= 3; --i) {
        for (int j = 0; j < 11; ++j) {
            if (grid[i * 11 + j]->c == 'N') {
                full = false;
                break;
            }
        }
        if (full == true) {
            point++;
        }
        full = true;
    }
    score += (point * point);
}

void Grid::rowDelete(int num) {
    for (int i = 0; i < 11; ++i) {
        if (Grid[num * 11 + i]->friends[0] == nullptr && Grid[num * 11 + i]->friends[1] == nullptr
        && Grid[num * 11 + i]->friends[2] == nullptr) {
            score+=1;
        }
        for (int x = 0; x < 3; ++x) {
            if (Grid[num * 11 + i]->friends[x] != nullptr) {
                Grid[num * 11 + i]->friends[x]->notify(Grid[num * 11 + i]);
            }
        }
        for (int j = num - 1; j >= 3; --j) {
            delete grid[j * 11 + i + 11];
            grid[j * 11 + i + 11] = grid[j * 11 + i];
            grid[j * 11 + i] = new BaseCell;
        }
    }
}

void Grid::rowsDelete() {
    bool full = true;
    for (int i = 17; i >= 3; --i) {
        for (int j = 0; j < 11; ++j) {
            if (grid[i * 11 + j]->c == 'N') {
                full = false;
                break;
            }
        }
        if (full == true) {
          rowDelete(i);
          rowsDelete();
          return;
        }
        full = true;
    }
}

void Grid::update() {
    if (index == sequence.size() - 1) {
        index = 0;
    }
    else {
        index++;
    }
    if (sequence.size() == 1) {
        curblock = sequence[0];
        nextblock = sequence[0];
    }
    else {
        curblock = sequence[index];
        nextblock = sequence[index + 1];
    }
}

void Grid::printNext1() {
    if (nextblock == 'I') {
        cout << "IIII";
    }
    else if (nextblock == 'J') {
        cout << "J";
    } 
    else if (nextblock == 'L') {
        cout << "  L";
    }
    else if (nextblock == 'O') {
        cout << "OO";
    }
    else if (nextblock == 'S') {
        cout << " SS";
    }
    else if (nextblock == 'Z') {
        cout << "ZZ";
    }
    else if (nextblock == 'T') {
        cout << "TTT";
    }
}

void Grid::printNext2() {
    if (nextblock == 'I') {
        cout << "";
    }
    else if (nextblock == 'J') {
        cout << "JJJ";
    } 
    else if (nextblock == 'L') {
        cout << "LLL";
    }
    else if (nextblock == 'O') {
        cout << "OO";
    }
    else if (nextblock == 'S') {
        cout << "SS";
    }
    else if (nextblock == 'Z') {
        cout << " ZZ";
    }
    else if (nextblock == 'T') {
        cout << " T ";
    }
}
