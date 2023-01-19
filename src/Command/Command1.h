//
// Created by tomer on 19/01/2023.
//

#ifndef TARGIL1_COMMAND1_H
#define TARGIL1_COMMAND1_H
#include "Command.h"
#include "../Extractors/StringExtractor.h"

class Command1: public Command{

private:
    bool upload(std::string message){
        this->io->write(message);
        std::string data  = this->io->read();
        if(data == "invalid Path"){
            return false;
        }
        else{
            StringExtractor stringExtractor(data);
            this->context.setGn(stringExtractor);
            return true;

        }
    }
public:

    Command1(std::string description, DefaultIO* io, Context context);

    void execute();

};


#endif //TARGIL1_COMMAND1_H
