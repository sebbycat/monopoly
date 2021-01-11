#ifndef ___NONPROPERTY___
#define ___NONPROPERTY___

#include "Square.h"
#include "Player.h"
#include <memory>
using namespace std;

class NonProperty : public Square{
  
  public:
  NonProperty(string Name,int Index);
};

#endif
