//
// Created by tomer on 20/01/2023.
//

#include "Command4.h"

Command4::Command4(const std::string &description, DefaultIO *io, Context *context) : Command(description, io,
                                                                                              context) {}

void Command4::execute() {
    if(this->checkRequirement()){
        if(this->checkResult()){
            this->io->write(this->sendResults());
        }
        else{
            this->io->write("please classify the data\n");
            return;
        }
    }
    else{
        this->io->write("please upload data\n");
        return;
    }

}
