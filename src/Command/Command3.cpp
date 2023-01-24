//
// Created by tomer on 20/01/2023.
//

#include "Command3.h"
#include "../CommunicationProtocol.h"

#define DEBUG_COMMAND_3 0

Command3::Command3(std::string description, DefaultIO *io, Context *context) : Command(description, io, context) {}
void Command3::execute() {
    bool didClassifying = false;
    if(this->checkRequirement()){
        if(DEBUG_COMMAND_3){
            std::cout << "requirements are met" << std::endl;
        }
        //check if results are already written
        if(this->context->getResult()->empty()) {
            if(DEBUG_COMMAND_3){
                std::cout << "results is empty" << std::endl;
            }
            this->context->setKnn();
             didClassifying = this->runKnn();
        }
        else{
            didClassifying = true;
        }
        if(didClassifying){
            this->io->write(OK_MESSAGE_CLASSIFICATION_SUCCESS);
            //read received message from client before return
            this->io->read();
            return;
        }
        this->io->write(ERROR_MESSAGE_CLASSIFICATION_FAILED);
    }
    else{
        this->io->write(ERROR_MESSAGE_REQUIRED_DATA);
    }
    //read received message from client
    this->io->read();
}
//private functions
bool Command3::checkRequirement(){
    if(this->context->getGn() && !this->context->getToClassify()->empty()){
        return true;
    }
    return false;
}
bool Command3::runKnn(){
    int num = 1;
    this->context->initializeResult();
    for(std::vector<double> temp : *this->context->getToClassify()){
        if(this->classify(num,temp)) {
            num += 1;
        }
        else{
            this->context->initializeResult();
            return false;
        }
    }
    return true;
}
bool Command3::classify(int num, std::vector<double> v1){
    std::string classified = this->context->getKnn()->getClassification(v1);
    if(classified != "invalid input"){
        this->context->updateResult(num, classified);
        return true;
    }
    return false;
}
