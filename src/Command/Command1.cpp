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
    //create backup
    DataExtractor* backUp = nullptr;
    if(this->context->getGn()) {
        backUp = (this->context->getGn()->getDataExtractor()->copy());
    }
    if(this->upload(UPLOAD_TRAIN_CSV)){
        if(this->upload((UPLOAD_TEST_CSV))){
            //upload was successful, initialize knn and results
            this->context->initializeResult();
            this->context->initializeKNN();
            this->io->write("upload complete\n");
        }
        //path was not valid, restore gn;
        else{
            this->io->write("invalid\n");
            this->context->setGn(*backUp);

        }
    }
    if(backUp){
        delete backUp;
    }




}
/*
../datasets/wine/wine_Classified.csv
../datasets/wine/wine_Unclassified.csv
../datasets/beans/beans_Classified.csv

   */