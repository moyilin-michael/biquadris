#include "BlockCell.h"
#include "cell.h"

BlockCell::BlockCell(Cell *component, char c) 
	: Decorator{component},
	  c{c} {
	  }

char BlockCell::returnType() {
	return c;
}

std::vector<Cell *>& BlockCell::getFriends() {
	std::vector<Cell *>& r = friends;
	return r;
}
