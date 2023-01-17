//
// Created by tomer on 17/01/2023.
//

#ifndef TARGIL1_COMMAND_H
#define TARGIL1_COMMAND_H

#include "DefualtIO.h"
#include "Context.h"

class Command {
private:
    DefualtIO io;
    std::string description;
    Context context;
public:
    void execute();
};




#endif //TARGIL1_COMMAND_H
