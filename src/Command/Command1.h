//
// Created by tomer on 19/01/2023.
//

#ifndef TARGIL1_COMMAND1_H
#define TARGIL1_COMMAND1_H
#include "Command.h"

class Command1: public Command{
    Command1(std::string description, DefaultIO* io, Context context);

    void execute();
};


#endif //TARGIL1_COMMAND1_H
