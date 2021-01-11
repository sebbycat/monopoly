#ifndef ___GOOSENESTING___
#define ___GOOSENESTING___

#include "NonProperty.h"

class GooseNesting : public NonProperty{
  public:
  GooseNesting(string Name,int Index);
  int Event(std::shared_ptr<Player> p);
};


#endif

