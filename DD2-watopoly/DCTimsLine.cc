#include "DCTimsLine.h"
#include <memory>

DCTimsLine::DCTimsLine(string Name,int Index) : NonProperty{Name,Index} {}


void DCTimsLine::outJail(std::shared_ptr<Player> p){
  p->setin_jail(false);
  p->setturnsToTimsLine(0);
  cout << "Now you are not in line." << endl;
}

bool DCTimsLine::usingRollUp(std::shared_ptr<Player> p){
  return true;
}

bool DCTimsLine::thirdTimes(std::shared_ptr<Player> p){
  return p->getturnsToTimsLine() == 2;
}


void DCTimsLine::roll(std::shared_ptr<Player> p,int Dice1,int Dice2){
  if(Dice1 == Dice2) {
    outJail(p);
    p->updateLocation(Dice1 + Dice2);
  }
  else {
    p->setturnsToTimsLine(p->getturnsToTimsLine() + 1);
  }
}

int DCTimsLine::rollthird(std::shared_ptr<Player> p,int Dice1,int Dice2, bool has_cups) {
  if(Dice1 == Dice2) {
    outJail(p);
    p->updateLocation(Dice1 + Dice2);
  }
  else {
    if(!has_cups) {
      cout << "You have to pay $50." << endl;
      pay50(p);
      return (0 - tims);
    }
    else {
      cout << "Press pay to pay $50, press cup to use Rim cups." << endl;
      string cmd;
      cin >> cmd;
      if(cmd == "pay") {
        pay50(p);
      }
      if (cmd == "cup") {
        useCups(p);
      }
    }
  }
  return 0;
}

int DCTimsLine::pay50(std::shared_ptr<Player> p) {
  outJail(p);
  return (0 - tims);
}

void DCTimsLine::useCups(std::shared_ptr<Player> p) {
  p->setOwnedCups(0 - 1);
  outJail(p);
}


int DCTimsLine::Event(std::shared_ptr<Player> p){
  return 0;
}
