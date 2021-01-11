#include "Residence.h"
#include <algorithm>

Residence::Residence(string Name,int Index,shared_ptr<Player> Owner, int PurchaseCost) : Property(Name, Index,Owner, PurchaseCost) {}

int Residence::getTuition(){
  return Tuition;
}

void Residence::printAssets(){

}



int Residence::Event(std::shared_ptr<Player> owner,std::shared_ptr<Player> player, int rollDice){
  int residentNum = 0;
  for(auto n : owner->getProperty()){
    auto it = find(residenceIndex.begin(),residenceIndex.end(),n);
    if(it != residenceIndex.end()){
      residentNum++;
    }
  }
  if(residentNum == 1){
    owner->setCash(25);
    return -25;
  }else if(residentNum == 2){
    owner->setCash(50);
    return -50;
  }else if(residentNum == 3){
    owner->setCash(100);
    return -100;
  }else if(residentNum == 4){
    owner->setCash(200);
    return -200;
  }
  return 0;
}
