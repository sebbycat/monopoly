#ifndef ___OSAP___
#define ___OSAP___

#include "NonProperty.h"
using namespace std;

class OSAP : public NonProperty{
  int osapFee = 200;

  public:
  OSAP(string Name,int Index);
  void Event(Player &p);
};

#endif
