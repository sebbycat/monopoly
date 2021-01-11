#include "ChangeCreator.h"
#include <iostream>
#include <string>

void ChangeCreator::getCard(){
  std::shared_ptr<Change> card = this->makeCard();
  std::cout << "Since you land on Needles Hall, your gain/lose this amount of cash:  " << std::endl;
  std::cout << "\t\t";
  card->getC(); 

}


