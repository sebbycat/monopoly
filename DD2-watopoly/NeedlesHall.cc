#include "NeedlesHall.h"
#include "ChangeConcreteCreator.h"

NeedlesHall::NeedlesHall(string Name,int Index) : NonProperty{Name,Index} {}

int NeedlesHall::Event(std::shared_ptr<Player> p){
  auto c = std::make_shared <ChangeConcreteCreator>();
  c->getCard();
  int Change = c->getChangeNum();
  if(Change < 0 && p->getCash() + Change < 0){
    return Change;
  }else{
    p->setCash(Change);
  }
  return 0;
}
