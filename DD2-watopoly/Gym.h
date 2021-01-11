#ifndef ___GYM___
#define ___GYM___

#include <iostream>
#include "Property.h"
using namespace std;

class Gym : public Property {
    private:
    const int  ChargeOneGym =4;
    const int  ChargeTwoGyms = 10;
    
    public:
    Gym(string Name,int Index,shared_ptr<Player> Owner, int PurchaseCost);
    int getTuition() override;
    void printAssets() override;
    int Event(std::shared_ptr<Player> owner,std::shared_ptr<Player> player,int rollDice)override;

};

#endif
