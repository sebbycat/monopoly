#include "ChangeConcreteCreator.h"
#include "Change.h"
#include "ChangeCard.h"
#include <memory>

ChangeConcreteCreator::ChangeConcreteCreator(){ }



std::shared_ptr<Change> ChangeConcreteCreator::makeCard(){
  std::shared_ptr<ChangeCard> c = std::make_shared <ChangeCard>();
  Change1 = c->getChange();
  return c;
}


std::string ChangeConcreteCreator::getChangeString(){
  return this->Change1;
}

int ChangeConcreteCreator::getChangeNum(){
  if(Change1 == "Change Saving by -200"){
    return -200;
  }else if(Change1 == "Change Saving by -100"){
    return -100;
  }else if(Change1 == "Change Saving by -50"){
    return -50;
  }else if(Change1 == "Change Saving by 25"){
    return 25;
  }else if(Change1 == "Change Saving by 50"){
    return 50;
  }else if(Change1 == "Change Saving by 100"){
    return 100;
  }else{
    return 200;
  }
}
