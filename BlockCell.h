#ifndef _BLOCKCELL_H_
#define _BLOCKCELL_H_
#include "decorator.h"
#include <string>
#include <vector>
class Cell;

struct BlockCell: public Decorator {
	char c;
	std::vector<Cell *> friends;
	BlockCell(Cell *component, char c);
	char returnType() override;
	std::vector<Cell *>& getFriends() override;
	//~Rfour();
};

#endif
