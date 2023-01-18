//
// Created by tomer on 17/01/2023.
//

#ifndef TARGIL1_COMMAND_H
#define TARGIL1_COMMAND_H

#include "DefaultIO.h"
#include "Context.h"

class Command {
private:
    DefaultIO io;
    std::string description;
    Context context;
public:
    virtual void execute() = 0;
};




#endif //TARGIL1_COMMAND_H
