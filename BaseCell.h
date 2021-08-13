#ifndef _BASECELL_H_
#define _BASECELL_H_
#include "cell.h"
#include <vector>

class BaseCell: public Cell {
	char c;
	public:
		BaseCell();
		~BaseCell();
		char returnType() override;
		std::vector<Cell *>& getFriends() override;
};

#endif
