#ifndef ___MOVECARD___
#define ___MOVECARD___
#include "Move.h"
#include <string>

class MoveCard : public Move {
    friend class MoveConcreteCreator;
    std::string movement;
    

    public:
    MoveCard();
    virtual std::string getMovement() override;
    virtual void getM() override;
    
};

#endif
