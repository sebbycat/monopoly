#include "MoveConcreteCreator.h"
#include "Move.h"
#include "MoveCard.h"
#include <memory>

MoveConcreteCreator::MoveConcreteCreator(){ }



std::shared_ptr<Move> MoveConcreteCreator::makeCard(){
  std::shared_ptr<MoveCard> c = std::make_shared <MoveCard>();
  movement = c->getMovement();
  return c;
}


std::string MoveConcreteCreator::getMovementString(){
  return this->movement;
}

int MoveConcreteCreator::getMovementNum(){
  if(movement == "Move Backward 3"){
    return -3;
  }else if(movement == "Move Backward 2"){
    return -2;
  }else if(movement == "Move Backward 1"){
    return -1;
  }else if(movement == "Move Forward 1"){
    return 1;
  }else if(movement == "Move Forward 2"){
    return 2;
  }else if(movement == "Move Forward 3"){
    return 3;
  }else if(movement == "Go To DC Tims Line"){
    return 10;
  }else{
    return 0;
  }
}
