#include "Command5.h"
#include "../CommunicationProtocol.h"

Command5::Command5(const std::string &description, DefaultIO *io, Context *context) : Command(description, io,
                                                                                              context) {}
void Command5::execute() {
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
bool Command5::checkRequirement(){
    if(this->context->getGn()){
        return true;
    }
    return false;
}   
bool Command5::checkResult(){
    if(this->context->getResult()) {
        if (!this->context->getResult()->empty()) {
            return true;
        }
    }
    return false;
}
std::string Command5::sendResults(){
    std::string result;
    for(std::pair<int,std::string> temp : *this->context->getResult()){
        result += std::to_string(temp.first);
        result += '\t';
        result += temp.second;
        result += '\n';
    }
    return result;
}                                                                                           
