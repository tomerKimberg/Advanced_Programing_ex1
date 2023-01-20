//
// Created by tomer on 19/01/2023.
//

#ifndef TARGIL1_COMMAND2_H
#define TARGIL1_COMMAND2_H
#include <string>
#include "Command.h"

class Command2 : public Command{
private:
    int kBackup;
    std::string metricBackUp;
public:
    Command2(std::string description, DefaultIO *io, Context *context);
    void execute();

};


#endif //TARGIL1_COMMAND2_H
