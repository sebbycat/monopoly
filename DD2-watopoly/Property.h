#ifndef ___PROPERTY___
#define ___PROPERTY___
#include <iostream>
#include "Square.h"
#include "Player.h"
#include <memory>

using namespace std;

class Property : public Square {
    private:
    shared_ptr<Player> Owner;
    int PurchaseCost;
    public:
    Property(string Name,int index,shared_ptr<Player> Owner, int PurchaseCost);
    string getName();
    shared_ptr<Player> getOwner();
    void setOwner(shared_ptr<Player> Owner);
    int getPurchaseCost() override;
    void purchaseProperty(shared_ptr<Player> currentPlayer);
    
};

#endif
