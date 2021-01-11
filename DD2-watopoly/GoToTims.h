#ifndef ___GOTOTIMS___
#define ___GOTOTIMS___

#include "NonProperty.h"
using namespace std;
class GoToTims : public NonProperty{
  
  public:
  GoToTims(string Name,int Index);
  int Event(std::shared_ptr<Player> p);
  
};

#endif
