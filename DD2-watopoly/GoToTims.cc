#include "GoToTims.h"
#include <iostream>

GoToTims::GoToTims(string Name,int Index) : NonProperty{Name,Index} {}

int GoToTims::Event(std::shared_ptr<Player> p){
  p->setin_jail(true);
  int originalCash = p->getCash();
  p->setLocation(10);
  std::cout << "Since you land on GoToTims, you are now sent to DC Tims Line." << std::endl;
  int currCash = p->getCash();
  if(originalCash!=currCash){
    return -200;
  }
  return 0;
}
