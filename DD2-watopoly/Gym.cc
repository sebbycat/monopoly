
#include "Gym.h"
#include <algorithm>

Gym::Gym(string Name,int Index,shared_ptr<Player> Owner, int PurchaseCost) : 
Property(Name, Index,Owner, PurchaseCost) {}


int Gym::getTuition(){
  return 0;
}

void Gym::printAssets(){

}

int Gym::Event(std::shared_ptr<Player> owner,std::shared_ptr<Player> player, int rollDice){
  int totalGym = 0;
  int money = rollDice;
  auto p = owner->getProperty();
  auto find1 = find(p.begin(),p.end(),12);
  auto find2 = find(p.begin(),p.end(),28);
  if(find1 != p.end()) {
    ++totalGym;
  }
  if(find2 != p.end()) {
    ++totalGym;
  }
  if(totalGym == 1) {
    money *= this->ChargeOneGym;
  }
  if(totalGym == 2) {
    money *= this->ChargeTwoGyms;
  }
  owner->setCash(money);
  return (0 - money);
}
