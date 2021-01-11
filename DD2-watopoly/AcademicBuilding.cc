#include "AcademicBuilding.h"
#include <iostream>

AcademicBuilding::AcademicBuilding(std::string name, int index, shared_ptr<Player> owner, int purchaseCost, std::string monopoly,int currentLevel,int improvementCost,vector<int> tuition) :  
Property(name, index,owner, purchaseCost), Monopoly(monopoly), CurrentLevel(currentLevel), ImprovementCost(improvementCost){
  Tuition = tuition;
}

std::string AcademicBuilding::getMonopoly() {
  return Monopoly;
}
int AcademicBuilding::getCurrentLevel() {
  return CurrentLevel;
}
const int AcademicBuilding::getImprovementCost() {
  return ImprovementCost;
}
int AcademicBuilding::getTuition() {
  return Tuition[CurrentLevel];
}
void AcademicBuilding::setCurrentLevel(int c) {
  CurrentLevel = c;
}
void AcademicBuilding::printAssets() {
}

bool AcademicBuilding::payRent(std::shared_ptr<Player> owner, std::shared_ptr<Player> currPlayer, bool doubleRent){
  int rent = 0;
  if(doubleRent == true){
    rent -= 2 * this->Tuition.at(0);
  }else{
    rent -= this->Tuition.at(CurrentLevel);
  }
  if(currPlayer->getCash() < (0 - rent)){
    return false;
  }
  currPlayer->setCash(rent);
  owner->setCash(0-rent);
  std::cout << "Paying Rent to " << owner->getName() << " for " << -rent << " dollars." << endl;
  return true;
}


void AcademicBuilding::buyImprovement(std::shared_ptr<Player> currPlayer){
  if(this->CurrentLevel >= 5){
    std::cout << "Buying Improvemet Failed." << std::endl;
    std::cout << "You have reached the highest level of improvement." << std::endl;
  }else{
    currPlayer->setCash(0-this->ImprovementCost);
    CurrentLevel++;
    std::cout << "Buying Improvement completed." << std::endl;
  }
}

void AcademicBuilding::sellImprovement(std::shared_ptr<Player> currPlayer){
  if(this->CurrentLevel <= 0){
    std::cout << "Selling Improvemet Failed." << std::endl;
    std::cout << "You do not have any improvement in this property." << std::endl;
  }else{
    currPlayer->setCash(0.5*this->ImprovementCost);
    CurrentLevel--;
    std::cout << "Selling Improvement completed." << std::endl;
  }
}
