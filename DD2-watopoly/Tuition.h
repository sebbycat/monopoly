#ifndef ___TUITION___
#define ___TUITION___
#include <iostream>
#include "NonProperty.h"
using namespace std;
class Tuition :public NonProperty{
  int tuition = 300;
  double percentage = 0.1;
  
  public:
  Tuition(string Name,int Index);
  int Event(std::shared_ptr<Player> p,int totalWorth);
};

#endif
