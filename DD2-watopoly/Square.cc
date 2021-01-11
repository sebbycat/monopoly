#include "Square.h"
#include "Property.h"
#include "AcademicBuilding.h"
Square::Square(string Name,int Index): Name{Name},Index{Index} {}

std::string Square::SaveSquareStatus(){
  std::string s = "";
  s += Name;
  s += " ";
  if(this->getOwner()) {
  s += this->getOwner()->getName();
  }
  else {
    s += "BANK";
  }
  s += " ";
  s += to_string(this->getImprovement());
  return s;
}


int Square::getIndex(){
  return Index;
}

string Square::getName(){
  return Name;
}

void Square::setOwner(shared_ptr<Player> Owner)  {
  auto p = dynamic_cast<Property *>(this);
    if(p){
      p->setOwner(Owner);
    }
}

string Square::getMonopoly(){return "";}
shared_ptr<Player> Square::getOwner(){
  auto p = dynamic_cast<Property *>(this);
    if(p){
      return p->getOwner();
    }
    return nullptr;
}
int Square::getImprovement(){
  auto p = dynamic_cast<Property *>(this);
  auto ad = dynamic_cast<AcademicBuilding *>(p);
    if(ad){
      return ad->getCurrentLevel();
    }
  return 0;
}

int Square::getTuition(){return 0;}
void Square::setImprovement(int improvement){ 
  auto p = dynamic_cast<Property *>(this);
  auto ad = dynamic_cast<AcademicBuilding *>(p);
    if(ad){
      ad->setCurrentLevel(improvement);
    }
  
}

int Square::getPurchaseCost(){
  auto p = dynamic_cast<Property *>(this);
  if(p){
    return p->getPurchaseCost();
  }
  return 0;
}

void Square::printAssets(){ }

int Square::Event(std::shared_ptr<Player> p) {
  return 0;
}

int Square::Event(std::shared_ptr<Player> owner,std::shared_ptr<Player> player,int rollDice){
  return 0;
 }


