#include "Property.h"
#include <iostream>
using namespace std;

Property::Property(string Name,int index,shared_ptr<Player> Owner, int PurchaseCost): 
Square{Name,index}, Owner{Owner}, PurchaseCost{PurchaseCost} {}


void Property::setOwner(shared_ptr<Player> Owner) {
  this->Owner = Owner;
}

string Property::getName(){
  return "";
}
shared_ptr<Player> Property::getOwner(){
  return Owner;
}

int Property::getPurchaseCost(){
  return PurchaseCost;
}

void Property::purchaseProperty(shared_ptr<Player> currentPlayer){
  currentPlayer->setCash(0-PurchaseCost);
  setOwner(currentPlayer);
}


