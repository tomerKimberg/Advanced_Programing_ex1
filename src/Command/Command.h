//
// Created by tomer on 17/01/2023.
//

#ifndef TARGIL1_COMMAND_H
#define TARGIL1_COMMAND_H

#include "DefaultIO.h"
#include "Context.h"

class Command {
protected:
    DefaultIO* io;
    std::string description;
    Context context;

public:
    Command(std::string description, DefaultIO* io, Context context);
    virtual void execute() = 0;
};




#endif //TARGIL1_COMMAND_H
