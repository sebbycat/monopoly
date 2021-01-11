#ifndef ___MOVECONCRETECREATOR___
#define ___MOVECONCRETECREATOR___

#include "MoveCreator.h"
#include <memory>
#include <string>

class MoveConcreteCreator : public MoveCreator {
  std::string movement;
  std::shared_ptr<Move> makeCard() override;

  int random();

  public:
  MoveConcreteCreator();

  std::string getMovementString();
  int getMovementNum();
};


#endif
