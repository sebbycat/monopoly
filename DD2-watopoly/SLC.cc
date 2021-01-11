#include "SLC.h"

SLC::SLC (std::string Name,int Index) : NonProperty{Name,Index} {}

int SLC::Event(std::shared_ptr<Player> p){
  auto c = std::make_shared <MoveConcreteCreator>();
  c->getCard();
  int movement = c->getMovementNum();
  if(movement == 0){
    p->setLocation(movement);
    p->setCash(200);
  }else if(movement == 10){
    int curr = p->getLocation();
    p->setin_jail(true);
    if (curr > 10){
      p->setCash(200);
    }
    p->setLocation(10);
  }else{
    p->updateLocation(movement);
  }
  return 0;
}
