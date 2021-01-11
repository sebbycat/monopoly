#ifndef ___SQUARE___
#define ___SQUARE___
#include <iostream>
#include "Observer.h"
#include "Player.h"
#include <memory>
using namespace std;

class Player;

class Square/*: public Observer*/{
    private:
    string Name;
    int Index;
    
    public:
    Square(string Name,int Index);
    std::string SaveSquareStatus();
    int getIndex();
    string getName();
    virtual string getMonopoly();
    virtual shared_ptr<Player> getOwner();
    virtual int getImprovement();
    virtual int getTuition();
    virtual void setImprovement(int);
    virtual int getPurchaseCost();
    virtual void printAssets();
    void setOwner(shared_ptr<Player> Owner);
    virtual int Event(std::shared_ptr<Player> p);
    virtual int Event(std::shared_ptr<Player> owner,std::shared_ptr<Player> player,int rollDice);
};

#endif
