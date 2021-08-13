#include "BaseCell.h"
#include <vector>

BaseCell::BaseCell() 
	: c{'N'} {
	  }

BaseCell::~BaseCell() {}

char BaseCell::returnType() {
	return 'N';
}

std::vector<Cell *>& BaseCell::getFriends() {
	std::vector<Cell *> n;
	return n;
}
