#ifndef ___CHANGECARD___
#define ___CHANGECARD___

#include "Change.h"
#include <memory>
#include <string>

class ChangeCard : public Change {
    friend class ChangeConcreteCreator;
    std::string Change;
    

    public:
    ChangeCard();
    virtual std::string getChange() override;
    virtual void getC() override;
    
};


#endif
