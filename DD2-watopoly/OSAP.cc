#include "OSAP.h"
#include <memory>


OSAP::OSAP(string Name,int Index) : NonProperty{Name,Index} {}




void OSAP::Event( Player &p){
    p.setCash(osapFee);
}
