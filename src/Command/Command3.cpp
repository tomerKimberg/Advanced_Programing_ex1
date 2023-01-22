//
// Created by tomer on 20/01/2023.
//

#include "Command3.h"
Command3::Command3(std::string description, DefaultIO *io, Context *context) : Command(description, io, context) {}
void Command3::execute() {
    bool didClassifying = false;
    if(this->checkRequirement()){
        //check if results are already written
        if(this->context->getResult()->empty()) {
            this->context->setKnn();
             didClassifying = this->runKnn();
        }
        else{
            didClassifying = true;
        }
        if(didClassifying){
            this->io->write("classifying data complete\n");
            return;
        }
        this->io->write("one of the parameters is invalid\n");
    }
    else{
        this->io->write("please upload data\n");
    }
}
//private functions
bool Command3::checkRequirement(){
    if(this->context->getGn()){
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
