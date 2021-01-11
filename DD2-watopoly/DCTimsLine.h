#ifndef ___DCTIMSLINE___
#define ___DCTIMSLINE___

#include "NonProperty.h"

class DCTimsLine : public NonProperty{
  int tims = 50;

  void outJail(std::shared_ptr<Player> p);
  bool usingRollUp(std::shared_ptr<Player> p);
  bool thirdTimes(std::shared_ptr<Player> p);

  public:
  DCTimsLine(string Name,int Index);
  void roll(std::shared_ptr<Player> p,int Dice1,int Dice2);
  int rollthird(std::shared_ptr<Player> p,int Dice1,int Dice2, bool has_cups);
  int pay50(std::shared_ptr<Player> p);
  void useCups(std::shared_ptr<Player> p);
  int Event(std::shared_ptr<Player> p);
};

#endif
