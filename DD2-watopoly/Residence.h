#ifndef ___RESIDENCE___
#define ___RESIDENCE___

#include <iostream>
#include "Property.h"
#include "Player.h"
#include <vector>
using namespace std;

class Residence : public Property {
    private:
    const int Tuition = 25;
    vector<int> residenceIndex{5,15,25,35};
    
    public:
    Residence(string Name,int Index,shared_ptr<Player> Owner, int PurchaseCost);
    int getTuition() override;
    void printAssets() override;
    int Event(std::shared_ptr<Player> owner,std::shared_ptr<Player> player, int rollDice)override;
};

#endif
