#ifndef _CELL_H_
#define _CELL_H_
#include <vector>

class Cell {
	public:
		virtual char returnType() = 0;
		virtual std::vector<Cell *>& getFriends() = 0;
		virtual ~Cell();
};

#endif
