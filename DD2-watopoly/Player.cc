#include "Player.h"
#include "OSAP.h"
#include <algorithm>
#include <vector>
#include "Property.h"

#include "AcademicBuilding.h"


Player::Player(std::string name, char namechar, int cups, int cash, int location, int turns_at_tims, bool in_jail):
  name{name}, namechar{namechar}, owned_cups{cups}, cash{cash},
  location{location},turns_at_tims{turns_at_tims}, in_jail{in_jail}{
  }

std::string Player::SavePlayerStatus(){
  std::string s = "";
  s += name;
  s += " ";
  s += namechar;
  s += " ";
  s += std::to_string(owned_cups);
  s += " ";
  s += std::to_string(cash);
  s += " ";
  s += std::to_string(location);
  if(location == 10){
    s += " ";
    if(in_jail == false){
      s += "0";
    } else {
      s += "1";
      s += " ";
      s += std::to_string(turns_at_tims);
    }
  }
  return s;
}

std::string Player::getName(){
  return name;
}
char Player::getNameChar(){
  return namechar;
}

int Player::getLocation(){
  return location;
}

int Player::getCash(){
  return cash;
}

void Player::printAssets(std::vector<std::shared_ptr<Square>> board){
  std::cout << "Player Name: " << name << std::endl;
  std::cout << "\t" << "Cash: $" << cash << std::endl;
  std::cout << "\t" << "Owned Properties: " << std::endl;
  for( auto n : owned_property){
    int index = n;
    auto owned = board.at(index);
    std::cout << "\t\t" << owned->getName() 
    << " level: " << owned->getImprovement() << std::endl ;
  }
  std::cout << "\t" << "Mortgaged Properties: " << std::endl;
  for (auto n : mortgaged){
    int index  = n;
    auto owned =  board.at(index);
    std::cout << "\t\t" << owned->getName() << std::endl;
  }
  std::cout << "\t" << "Owned Rim Cups: ";
  std::cout << owned_cups << std::endl;
  std::cout << "\t" << "Current Location： " << location;
  std::cout << std::endl;
}

void Player::setLocation(int loc){
  location = loc;
}

void Player::updateLocation(int loc){
  location += loc;
  int osapNum;
  osapNum = location/40;
  this->cash += osapNum * 200;
  location %= 40;
  if(osapNum != 0){
    std::cout << "Pass OSAP and collect 200 dollars each time." << std::endl;
  }
  std::cout << "Player " << name << " is now at location index " << location  << "." << std::endl;
}

void Player::setCash(int newcash){
  cash += newcash;
}

void Player::addProperty(int p) {
  this->owned_property.emplace_back(p);
}

void Player::removeProperty(int p) {
  auto position = std::find(owned_property.begin(), owned_property.end(), p);
  if(position != owned_property.end()) {
    owned_property.erase(position);
  }
}

std::vector<int> Player::getProperty(){
  return owned_property;
}


void Player::setturnsToTimsLine(int times){
  turns_at_tims = times;
}

int Player::getturnsToTimsLine(){
  return turns_at_tims;
}

void Player::addMortgaged(int index,shared_ptr <Property> p) {
  auto ad = dynamic_pointer_cast<AcademicBuilding> (p);
  if(ad) {
    if(ad->getCurrentLevel()) {
      std::cout << "You need to sell all your improvements before mortgaging this building." << std::endl;
      return;
    }
  }
  auto position = find(owned_property.begin(),owned_property.end(),index);
  if(position != owned_property.end()) {
  owned_property.erase(position);
  string n = p->Square::getName();
  mortgaged.emplace_back(index);
  setCash(0.5 * p->getPurchaseCost());
  p->setOwner(nullptr);
  std::cout << "You just mortgaged " << p->Square::getName() << "." << std::endl;
  std::cout << "You received $" << 0.5 * p->getPurchaseCost() << std::endl;
  } else {
    std::cout << "You do not own this building, so you can not mortgage it." << std::endl;
  }
}

bool Player::removeMortgaged(int index, shared_ptr <Property> p){
  int money = cash;
  if(money < 0.6 * p->getPurchaseCost()){
    std::cout << "Sorry, you do not have enough money to unmortgage this building." << std::endl;
    return false;
  } else {
    auto position = find(mortgaged.begin(),mortgaged.end(),index);
    if (position != mortgaged.end()){
      mortgaged.erase(position);
      owned_property.emplace_back(index);
      setCash(0 - 0.6 * p->getPurchaseCost());
      std::cout << "You just unmortgaged " << p->Square::getName() << "."<< std::endl;
      std::cout << "You paied $" << 0.6 * p->getPurchaseCost() << std::endl;
      return true;
    } else {
      std::cout << "You didn't mortgage this building, so you can not unmortgage it." << std::endl;
      return false;
    }
  }
}

std::vector<int> Player::getMortgaged(){
  return mortgaged;
}


int Player::getOwnedCups(){
  return owned_cups;
}

void Player::setOwnedCups(int n){
  owned_cups += n;
}

bool Player::isin_jail(){
  return in_jail;
}

void Player::setin_jail(bool j){
  in_jail = j;
}

