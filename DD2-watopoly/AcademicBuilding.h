#ifndef ___ACADEMICBUILDING___
#define ___ACADEMICBUILDING___
#include <iostream>
#include <vector>
#include "Property.h"
#include "Player.h"
using namespace std;

class AcademicBuilding : public Property {
    private:
    string Monopoly;
    int CurrentLevel;
    int ImprovementCost;
    vector<int> Tuition;
    public:
    AcademicBuilding(std::string name,int index, shared_ptr<Player> owner, int purchaseCost, std::string monopoly,int currentLevel,int improvementCost,vector<int> tuition);
    string getMonopoly() override;
    int getCurrentLevel() ;
    const int getImprovementCost() ;
    int getTuition() override;
    void setCurrentLevel(int);
    void printAssets() override;
    bool payRent(std::shared_ptr<Player> owner, std::shared_ptr<Player> currPlayer, bool doubleRent);
    void buyImprovement(std::shared_ptr<Player> currPlayer);
    void sellImprovement(std::shared_ptr<Player> currPlayer);
  
};

#endif
