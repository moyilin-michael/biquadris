#ifndef _BLOCKCELL_H_
#define _BLOCKCELL_H_
#include "decorator.h"
#include <string>
#include <vector>
class Cell;

class BlockCell: public Decorator {
  char c;
  std::vector<BlockCell *>friends;
 public:
  BlockCell(Cell *component, char type);
  void notify(BlockCell* bc);
};

#endif
