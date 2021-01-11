#ifndef ___NEEDLESHALL___
#define ___NEEDLESHALL___

#include "NonProperty.h"
using namespace std;

class NeedlesHall : public NonProperty{
  public:
  NeedlesHall(string Name,int Index);
  int Event(std::shared_ptr<Player> p);
};

#endif
