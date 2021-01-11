#ifndef ___CHANGECREATOR___
#define ___CHANGECREATOR___
#include "Change.h"
#include <memory>

class ChangeCreator {
  virtual std::shared_ptr<Change> makeCard() = 0;
  public:
  void getCard();
};


#endif


