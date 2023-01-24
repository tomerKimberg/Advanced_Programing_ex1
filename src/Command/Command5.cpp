#include "Command5.h"
//debug
#define DEBUG_COMMAND_5 0

Command5::Command5(const std::string &description, DefaultIO *io, Context *context) : Command(description, io,
                                                                                              context) {}
void Command5::execute(){
    if(!this->checkRequirement()){
        this->io->write(ERROR_MESSAGE_REQUIRED_DATA);
        //probably read is needed
        return;
    }
    if(!this->checkResult()){
        this->io->write(ERROR_MESSAGE_REQUIRED_CLASSIFICATION);
        //probably read is needed
        return;
    }
    this->io->write(COMMUNICATION_MESSAGE_SERVER_READY_FOR_PATH);
    //results can be sent
    std::string message = this->io->read();
    if(INVALID_MESSAGE_PATH == message){
        //we can just return because next message will be the menu from the server
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
