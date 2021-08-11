#include "BlockCell.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

BlockCell::BlockCell( Cell* component, char type )
  : Decorator{component}, c{type} {}
void BlockCell::notify(BlockCell* bc) {
  if (!friends.empty()) {
    for (int i = 0; i < friends.size(); ++i) {
      if (friends[i] == bc) {
        friends[i] = nullptr;
      }
    }
  }
}
