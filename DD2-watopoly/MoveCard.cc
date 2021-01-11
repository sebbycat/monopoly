#include "MoveCard.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

MoveCard::MoveCard() {
  srand  (time(NULL));
  int random = rand() % 24 + 1;
  if(random>=1 && random<=3){
    movement = "Move Backward 3";
  }else if(random>=4 && random<=7){
    movement = "Move Backward 2";
  }else if(random>=8 && random<=11){
    movement = "Move Backward 1";
  }else if(random>=11 && random<=14){
    movement = "Move Forward 1";
  }else if(random>=14 && random<=18){
    movement = "Move Forward 2";
  }else if(random>=18 && random<=22){
    movement = "Move Forward 3";
  }else if(random==23){
    movement = "Go To DC Tims Line";
  }else{
    movement = "Advance to Collect OSAP";
  }
}


std::string MoveCard::getMovement(){
  return movement;
}

void MoveCard::getM(){
  std::cout << movement << std::endl;
}
