#ifndef ___COOPFEE___
#define ___COOPFEE___

#include "NonProperty.h"

class CoopFee : public NonProperty{
  int coopFee = 150;
  

  public:
  CoopFee(string Name,int Index);
  int Event(std::shared_ptr<Player> p);
};

#endif
