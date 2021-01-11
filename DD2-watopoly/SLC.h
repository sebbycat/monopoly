#ifndef ___SLC___
#define ___SLC___

#include "NonProperty.h"
#include <string>
#include "MoveConcreteCreator.h"
#include <memory>

class SLC : public NonProperty{
  
  public:
  SLC(std::string Name,int Index);
  int Event(std::shared_ptr<Player> p);
};


#endif
