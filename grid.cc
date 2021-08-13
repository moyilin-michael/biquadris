#include <iostream>
#include <fstream>
#include <sstream>
#include "grid.h"
#include "BlockCell.h"
using namespace std;

Grid::Grid(string file) {
    infile = file;
    index = 0;
    score = 0;
    level = 0;
    for (int i = 0; i < 11 * 18; ++i) {
        grid.push_back(new BaseCell);
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
        if (c == 'I' || c == 'J' || c == 'L' || c == 'O' || c == 'S' || c == 'Z' || c == 'T') {
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
   // cout << curblock << nextblock << endl;
    /*for (int i = 0; i < sequence.size(); ++i) {
	    cout << sequence[i] << 'l' << endl;
    }*/
}

int Grid::setDefault() {
	/*cout << curblock << endl;
	grid[44] = new BlockCell(grid[44], 'I');
	grid[45] = new BlockCell(grid[45], 'I');
	grid[46] = new Decorator(grid[44]);
	grid[44]->getFriends().push_back(grid[45]);
	blockpos[0].first = 4;
	blockpos[0].second = 0;
	return 1;*/
    if (curblock == 'I') {
        if (grid[33]->returnType() == 'N' && grid[34]->returnType() == 'N' && grid[35]->returnType() == 'N' && grid[36]->returnType() == 'N') {
            grid[33] = new BlockCell(grid[33], 'I');
            grid[34] = new BlockCell(grid[34], 'I');
            grid[35] = new BlockCell(grid[35], 'I');
            grid[36] = new BlockCell(grid[36], 'I');
            grid[33]->getFriends().push_back(grid[34]);
            grid[33]->getFriends().push_back(grid[35]);
            (grid[33]->getFriends()).push_back(grid[36]);
            (grid[34]->getFriends()).push_back(grid[33]);
            (grid[34]->getFriends()).push_back(grid[35]);
            (grid[34]->getFriends()).push_back(grid[36]);
            (grid[35]->getFriends()).push_back(grid[33]);
            (grid[35]->getFriends()).push_back(grid[34]);
            (grid[35]->getFriends()).push_back(grid[36]);
            (grid[36]->getFriends()).push_back(grid[33]);
            (grid[36]->getFriends()).push_back(grid[34]);
            (grid[36]->getFriends()).push_back(grid[35]);
            blockpos.push_back(std::make_pair(3, 0));
            blockpos.push_back(std::make_pair(3, 1));
            blockpos.push_back(std::make_pair(3, 2));
            blockpos.push_back(std::make_pair(3, 3));
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'J') {
        if (grid[33]->returnType() == 'N' && grid[44]->returnType() == 'N' && grid[45]->returnType() == 'N' && grid[46]->returnType() == 'N') {
            grid[33] = new BlockCell(grid[33], 'J');
            grid[44] = new BlockCell(grid[44], 'J');
            grid[45] = new BlockCell(grid[45], 'J');
            grid[46] = new BlockCell(grid[46], 'J');
            (grid[33]->getFriends()).push_back(grid[44]);
            (grid[33]->getFriends()).push_back(grid[45]);
            (grid[33]->getFriends()).push_back(grid[46]);
            (grid[44]->getFriends()).push_back(grid[33]);
            (grid[44]->getFriends()).push_back(grid[45]);
            (grid[44]->getFriends()).push_back(grid[46]);
            (grid[45]->getFriends()).push_back(grid[33]);
            (grid[45]->getFriends()).push_back(grid[44]);
            (grid[45]->getFriends()).push_back(grid[46]);
            (grid[46]->getFriends()).push_back(grid[33]);
            (grid[46]->getFriends()).push_back(grid[44]);
            (grid[46]->getFriends()).push_back(grid[45]);
            blockpos.push_back(std::make_pair(4, 0));
            blockpos.push_back(std::make_pair(3, 0));
            blockpos.push_back(std::make_pair(4, 1));
            blockpos.push_back(std::make_pair(4, 2));
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'L') {
        if (grid[44]->returnType() == 'N' && grid[45]->returnType() == 'N' && grid[46]->returnType() == 'N' && grid[35]->returnType() == 'N') {
            grid[44] = new BlockCell(grid[44], 'L');
            grid[45] = new BlockCell(grid[45], 'L');
            grid[46] = new BlockCell(grid[46], 'L');
            grid[35] = new BlockCell(grid[35], 'L');
            (grid[44]->getFriends()).push_back(grid[45]);
            (grid[44]->getFriends()).push_back(grid[46]);
            (grid[44]->getFriends()).push_back(grid[35]);
            (grid[45]->getFriends()).push_back(grid[44]);
            (grid[45]->getFriends()).push_back(grid[46]);
            (grid[45]->getFriends()).push_back(grid[35]);
            (grid[46]->getFriends()).push_back(grid[44]);
            (grid[46]->getFriends()).push_back(grid[45]);
            (grid[46]->getFriends()).push_back(grid[35]);
            (grid[35]->getFriends()).push_back(grid[44]);
            (grid[35]->getFriends()).push_back(grid[45]);
            (grid[35]->getFriends()).push_back(grid[46]);
            blockpos.push_back(std::make_pair(4, 0));
            blockpos.push_back(std::make_pair(4, 1));
            blockpos.push_back(std::make_pair(4, 2));
            blockpos.push_back(std::make_pair(3, 2));
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'O') {
        if (grid[44]->returnType() == 'N' && grid[33]->returnType() == 'N' && grid[45]->returnType() == 'N' && grid[34]->returnType() == 'N') {
            grid[44] = new BlockCell(grid[44], 'O');
            grid[33] = new BlockCell(grid[33], 'O');
            grid[45] = new BlockCell(grid[45], 'O');
            grid[34] = new BlockCell(grid[34], 'O');
            (grid[44]->getFriends()).push_back(grid[33]);
            (grid[44]->getFriends()).push_back(grid[45]);
            (grid[44]->getFriends()).push_back(grid[34]);
            (grid[33]->getFriends()).push_back(grid[44]);
            (grid[33]->getFriends()).push_back(grid[45]);
            (grid[33]->getFriends()).push_back(grid[34]);
            (grid[45]->getFriends()).push_back(grid[44]);
            (grid[45]->getFriends()).push_back(grid[33]);
            (grid[45]->getFriends()).push_back(grid[34]);
            (grid[34]->getFriends()).push_back(grid[44]);
            (grid[34]->getFriends()).push_back(grid[33]);
            (grid[34]->getFriends()).push_back(grid[45]);
            blockpos.push_back(std::make_pair(4, 0));
            blockpos.push_back(std::make_pair(3, 0));
            blockpos.push_back(std::make_pair(4, 1));
            blockpos.push_back(std::make_pair(3, 1));
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'S') {
        if (grid[44]->returnType() == 'N' && grid[45]->returnType() == 'N' && grid[34]->returnType() == 'N' && grid[35]->returnType() == 'N') {
            grid[44] = new BlockCell(grid[44], 'S');
            grid[45] = new BlockCell(grid[45], 'S');
            grid[34] = new BlockCell(grid[34], 'S');
            grid[35] = new BlockCell(grid[35], 'S');
            (grid[44]->getFriends()).push_back(grid[45]);
            (grid[44]->getFriends()).push_back(grid[34]);
            (grid[44]->getFriends()).push_back(grid[35]);
            (grid[45]->getFriends()).push_back(grid[44]);
            (grid[45]->getFriends()).push_back(grid[34]);
            (grid[45]->getFriends()).push_back(grid[35]);
            (grid[34]->getFriends()).push_back(grid[44]);
            (grid[34]->getFriends()).push_back(grid[45]);
            (grid[34]->getFriends()).push_back(grid[35]);
            (grid[35]->getFriends()).push_back(grid[44]);
            (grid[35]->getFriends()).push_back(grid[45]);
            (grid[35]->getFriends()).push_back(grid[34]);
            blockpos.push_back(std::make_pair(4, 0));
            blockpos.push_back(std::make_pair(4, 1));
            blockpos.push_back(std::make_pair(3, 1));
            blockpos.push_back(std::make_pair(3, 2));
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'Z') {
        if (grid[33]->returnType() == 'N' && grid[45]->returnType() == 'N' && grid[34]->returnType() == 'N' && grid[46]->returnType() == 'N') {
            grid[33] = new BlockCell(grid[33], 'Z');
            grid[45] = new BlockCell(grid[45], 'Z');
            grid[34] = new BlockCell(grid[34], 'Z');
            grid[46] = new BlockCell(grid[46], 'Z');
            (grid[33]->getFriends()).push_back(grid[45]);
            (grid[33]->getFriends()).push_back(grid[34]);
            (grid[33]->getFriends()).push_back(grid[46]);
            (grid[45]->getFriends()).push_back(grid[33]);
            (grid[45]->getFriends()).push_back(grid[34]);
            (grid[45]->getFriends()).push_back(grid[46]);
            (grid[34]->getFriends()).push_back(grid[33]);
            (grid[34]->getFriends()).push_back(grid[45]);
            (grid[34]->getFriends()).push_back(grid[46]);
            (grid[46]->getFriends()).push_back(grid[33]);
            (grid[46]->getFriends()).push_back(grid[45]);
            (grid[46]->getFriends()).push_back(grid[34]);
            blockpos.push_back(std::make_pair(3, 0));
            blockpos.push_back(std::make_pair(4, 1));
            blockpos.push_back(std::make_pair(3, 1));
            blockpos.push_back(std::make_pair(4, 2));
            return 1;
        }
        else {
            return 0;
        }
    }
    else if (curblock == 'T') {
        if (grid[33]->returnType() == 'N' && grid[45]->returnType() == 'N' && grid[34]->returnType() == 'N' && grid[35]->returnType() == 'N') {
            grid[33] = new BlockCell(grid[33], 'T');
            grid[45] = new BlockCell(grid[45], 'T');
            grid[34] = new BlockCell(grid[34], 'T');
            grid[35] = new BlockCell(grid[35], 'T');
            (grid[33]->getFriends()).push_back(grid[45]);
            (grid[33]->getFriends()).push_back(grid[34]);
            (grid[33]->getFriends()).push_back(grid[35]);
            (grid[45]->getFriends()).push_back(grid[33]);
            (grid[45]->getFriends()).push_back(grid[34]);
            (grid[45]->getFriends()).push_back(grid[35]);
            (grid[34]->getFriends()).push_back(grid[33]);
            (grid[34]->getFriends()).push_back(grid[45]);
            (grid[34]->getFriends()).push_back(grid[35]);
            (grid[35]->getFriends()).push_back(grid[33]);
            (grid[35]->getFriends()).push_back(grid[45]);
            (grid[35]->getFriends()).push_back(grid[34]);
            blockpos.push_back(std::make_pair(3, 0));
            blockpos.push_back(std::make_pair(4, 1));
            blockpos.push_back(std::make_pair(3, 1));
            blockpos.push_back(std::make_pair(3, 2));
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
    if (curblock == 'I' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'J' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->returnType() == 'N' 
    && grid[blockpos[1].first * 11 + blockpos[1].second - 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'L' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second - 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'O' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->returnType() == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second - 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'S' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->returnType() == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second - 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'Z' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->returnType() == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second - 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'T' && blockpos[0].second > 0 && grid[blockpos[0].first * 11 + blockpos[0].second - 1]->returnType() == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second - 1]->returnType() == 'N') {
        return true;
    }
    else {
	/*if (blockpos[0].second <= 0) {
		cout << 1 << endl;
		cout << endl;
	}
	if (grid[blockpos[2].first * 11 + blockpos[2].second - 1]->returnType() != 'N') {
		cout << grid[blockpos[2].first * 11 + blockpos[2].second - 1]->returnType() << endl;
		cout << endl;
	}
	if (curblock != 'L') {
		cout << 3 << endl;
		cout << endl;
	}*/
        return false;
    }
}

bool Grid::ifright() {
    if (curblock == 'I' && blockpos[3].second < 10 && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'J' && blockpos[3].second < 10 && grid[blockpos[1].first * 11 + blockpos[1].second + 1]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'L' && blockpos[3].second < 10 && grid[blockpos[2].first * 11 + blockpos[2].second + 1]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'O' && blockpos[3].second < 10 && grid[blockpos[2].first * 11 + blockpos[2].second + 1]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'S' && blockpos[3].second < 10 && grid[blockpos[1].first * 11 + blockpos[1].second + 1]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'Z' && blockpos[3].second < 10 && grid[blockpos[2].first * 11 + blockpos[2].second + 1]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'T' && blockpos[3].second < 10 && grid[blockpos[1].first * 11 + blockpos[1].second + 1]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 1]->returnType() == 'N') {
        return true;
    }
    else {
        return false;
    }
}

bool Grid::ifdown() {
    if (curblock == 'I' && blockpos[0].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->returnType() == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second + 11]->returnType() == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second + 11]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 11]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'J' && blockpos[0].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->returnType() == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second + 11]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 11]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'L' && blockpos[0].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->returnType() == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second + 11]->returnType() == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second + 11]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'O' && blockpos[0].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->returnType() == 'N'
    && grid[blockpos[2].first * 11 + blockpos[2].second + 11]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'S' && blockpos[0].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->returnType() == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second + 11]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 11]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'Z' && blockpos[1].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->returnType() == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second + 11]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 11]->returnType() == 'N') {
        return true;
    }
    else if (curblock == 'T' && blockpos[1].first < 17 && grid[blockpos[0].first * 11 + blockpos[0].second + 11]->returnType() == 'N'
    && grid[blockpos[1].first * 11 + blockpos[1].second + 11]->returnType() == 'N'
    && grid[blockpos[3].first * 11 + blockpos[3].second + 11]->returnType() == 'N') {
        return true;
    }
    else {
        return false;
    }
}

void Grid::left() {
	//bool n = ifleft();
	//cout << n << endl;
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
	/*for (int j = 0; j <= 3; j++) {
		cout << grid[blockpos[j].first * 11 + blockpos[j].second]->returnType() << endl;
	}*/
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
    blockpos.clear();
}

void Grid::rowScore() {
    bool full = true;
    int point = 0;
    for (int i = 17; i >= 3; --i) {
        for (int j = 0; j < 11; ++j) {
            if (grid[i * 11 + j]->returnType() == 'N') {
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
        if (grid[num * 11 + i]->getFriends()[0] == nullptr && grid[num * 11 + i]->getFriends()[1] == nullptr
        && grid[num * 11 + i]->getFriends()[2] == nullptr) {
            score+=1;
        }
        for (int x = 0; x < 3; ++x) {
            if (grid[num * 11 + i]->getFriends()[x] != nullptr) {
		    if(!(grid[num * 11 + i]->getFriends()[x]->getFriends().empty())) {
			    for (int y = 0; y < 3; ++y) {
				    if (grid[num * 11 + i]->getFriends()[x]->getFriends()[y] == grid[num * 11 + i]) {
					    grid[num * 11 + i]->getFriends()[x]->getFriends()[y] = nullptr;
				    }
			    }
		    }
               // grid[num * 11 + i]->friends[x]->notify(grid[num * 11 + i]);
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
            if (grid[i * 11 + j]->returnType() == 'N') {
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
	if (index == sequence.size() - 1) {
		nextblock = sequence[0];
	}
	else {
                nextblock = sequence[index + 1];
	}
    }
    //cout << index << ' ' << curblock << ' ' << nextblock << endl;
}

void Grid::printNext1() {
    if (nextblock == 'I') {
        cout << "IIII";
    }
    else if (nextblock == 'J') {
        cout << "J   ";
    } 
    else if (nextblock == 'L') {
        cout << "  L ";
    }
    else if (nextblock == 'O') {
        cout << "OO  ";
    }
    else if (nextblock == 'S') {
        cout << " SS ";
    }
    else if (nextblock == 'Z') {
        cout << "ZZ  ";
    }
    else if (nextblock == 'T') {
        cout << "TTT ";
    }
}

void Grid::printNext2() {
    if (nextblock == 'I') {
        cout << "    ";
    }
    else if (nextblock == 'J') {
        cout << "JJJ ";
    } 
    else if (nextblock == 'L') {
        cout << "LLL ";
    }
    else if (nextblock == 'O') {
        cout << "OO  ";
    }
    else if (nextblock == 'S') {
        cout << "SS  ";
    }
    else if (nextblock == 'Z') {
        cout << " ZZ ";
    }
    else if (nextblock == 'T') {
        cout << " T  ";
    }
}
