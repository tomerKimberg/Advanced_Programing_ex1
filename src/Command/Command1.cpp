//
// Created by tomer on 19/01/2023.
//

#include "Command1.h"
#include "../Extractors/StringExtractor.h"
#define UPLOAD_TRAIN_CSV  "Please upload your local train CSV file.\n"
#define UPLOAD_TEST_CSV  "Please upload your local test CSV file.\n"

Command1::Command1(std::string description, DefaultIO* io,
                   Context* context) : Command(description, io, context) {
}
void Command1::execute() {
    //TODO save all parameters to restore if upload wasn't complete
    //initialize all parameters.
    this->context->initializeKNN();
    this->context->initializeGetNeighbors();
    this->context->initializeResult();
    this->context->initializeToClassify();

    if(this->upload(UPLOAD_TRAIN_CSV)){
        if(this->upload(UPLOAD_TEST_CSV)){
            this->io->write("upload complete\n");
        }
        else{
            this->context->initializeGetNeighbors();
        }
    };


}

