#include "GooseNesting.h"

GooseNesting::GooseNesting(string Name,int Index) : NonProperty{Name,Index} {}

int GooseNesting::Event(std::shared_ptr<Player> p){
  std::cout << "Being attacked by a flock of nesting geese!!!!!!!!" << std::endl;
  return 0;
}
