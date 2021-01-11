#include "ChangeCard.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


ChangeCard::ChangeCard(){
  srand  (time(NULL));
  int random = rand() % 18 + 1;
  if(random==1){
    Change = "Change Saving by -200";
  }else if(random>=2 && random<=3){
    Change = "Change Saving by -100";
  }else if(random>=4 && random<=6){
    Change = "Change Saving by -50";
  }else if(random>=7 && random<=12){
    Change = "Change Saving by 25";
  }else if(random>=13 && random<=15){
    Change = "Change Saving by 50";
  }else if(random>=16 && random<=17){
    Change = "Change Saving by 100";
  }else{
    Change = "Change Saving by 200";
  }
}


std::string ChangeCard::getChange(){
  return Change;
}

void ChangeCard::getC(){
  std::cout << Change << std::endl;
}
