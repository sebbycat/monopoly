#include "CoopFee.h"
#include <memory>

CoopFee::CoopFee(string Name,int Index) : NonProperty{Name,Index} {}




int CoopFee::Event(std::shared_ptr<Player> p){
  return (0 - coopFee);
}
