#ifndef ___CHANGECONCRETECREATOR___
#define ___CHANGECONCRETECREATOR___

#include "ChangeCreator.h"
#include <memory>


class ChangeConcreteCreator : public ChangeCreator{
  std::string Change1;
  std::shared_ptr<Change> makeCard() override;

  int random();

  public:
  ChangeConcreteCreator();
  std::string getChangeString();
  int getChangeNum();
};

#endif 

