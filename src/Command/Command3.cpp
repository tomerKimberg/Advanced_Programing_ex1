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
