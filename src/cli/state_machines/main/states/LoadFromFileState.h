//
// Created by denis on 18.09.20.
//

#ifndef TODOLIST_LOADFROMFILESTATE_H
#define TODOLIST_LOADFROMFILESTATE_H

#include "State.h"
#include "serialization/IstreamServiceDeserializer.h"

class LoadFromFileState : public State {

public:
    void                            print(ConsoleContextInterface &context) override;
    std::shared_ptr<State>          execute(ConsoleContextInterface &context, StateFactoryInterface &) override;
    void                            help(ConsoleContextInterface &) override;

};


#endif //TODOLIST_LOADFROMFILESTATE_H
