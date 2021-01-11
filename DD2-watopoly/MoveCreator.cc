#include "MoveCreator.h"
#include <iostream>
#include <string>


void MoveCreator::getCard(){
  std::shared_ptr<Move> card = this->makeCard();
  std::cout << "Since you land on SLC, you are required to :  " << std::endl;
  std::cout << "\t\t";
  card->getM();
}
