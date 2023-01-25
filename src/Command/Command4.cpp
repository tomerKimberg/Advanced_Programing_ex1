//
// Created by tomer on 20/01/2023.
//

#include "Command4.h"
#include "../CommunicationProtocol.h"

Command4::Command4(const std::string &description, DefaultIO *io, Context *context) : Command(description, io,
                                                                                              context) {}

void Command4::execute() {
    if(this->checkRequirement()){
        if(this->checkResult()){
            this->io->write(this->sendResults());
        }
        else{
            this->io->write(ERROR_MESSAGE_REQUIRED_CLASSIFICATION);
            return;
        }
    }
    else{
        this->io->write(ERROR_MESSAGE_REQUIRED_DATA);
        return;
    }
    //read received message from server
    this->io->read();
}
//private functions
bool Command4::checkRequirement(){
    if(this->context->getGn()){
        return true;
    }
    return false;
}
bool Command4::checkResult(){
    if(this->context->getResult()) {
        if (!this->context->getResult()->empty()) {
            return true;
        }
    }
    return false;
}
std::string Command4::sendResults(){
    std::string result;
    for(std::pair<int,std::string> temp : *this->context->getResult()){
        result += std::to_string(temp.first);
        result += '\t';
        result += temp.second;
        result += '\n';
    }
    return result;
}