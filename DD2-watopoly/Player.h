#ifndef ___PLAYER___
#define ___PLAYER___
#include <string>
#include <vector>
#include <iostream>
#include<fstream>
#include "Observer.h"
#include <memory>
#include "Square.h"


using namespace std;
class Square;
class Property;
class Player/*: public Observer*/{
  std::string name;
  char namechar;
  int owned_cups;
  int cash;
  int location;
  int turns_at_tims;
  bool in_jail;
  std::vector<int> owned_property;
  std::vector<int> mortgaged;

  public:
  Player(std::string name, char namechar, int cups, int cash, int location, int turns_at_tims, bool in_jail);
  std::string SavePlayerStatus();
  std::string getName();
  char getNameChar();
  int getLocation();
  int getCash();
  std::vector<int> getProperty();
  void printAssets(std::vector<std::shared_ptr<Square>> board);
  void setLocation(int loc);
  void updateLocation(int loc);
  void setCash(int cash);
  void removeProperty(int);
  void addProperty(int);
  bool isin_jail();
  void setin_jail(bool);
  void setturnsToTimsLine(int times);
  int getturnsToTimsLine();
  void addMortgaged(int index,shared_ptr <Property> p);
  bool removeMortgaged(int, shared_ptr <Property> p);
  std::vector<int> getMortgaged();
  int getOwnedCups();
  void setOwnedCups(int n);
};

#endif


