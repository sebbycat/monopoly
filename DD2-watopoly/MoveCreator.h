#ifndef ___MOVECREATOR___
#define ___MOVECREATOR___

#include "Move.h"
#include <memory>

class MoveCreator{
  virtual std::shared_ptr<Move> makeCard() = 0;
  public:
  void getCard();
};


#endif
