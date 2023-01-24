//
// Created by tomer on 19/01/2023.
//

#include "Command1.h"
#include "../CommunicationProtocol.h"
#include "../Extractors/StringExtractor.h"
#define UPLOAD_TRAIN_CSV  "Please upload your local train CSV file.\n"
#define UPLOAD_TEST_CSV  "Please upload your local test CSV file.\n"

Command1::Command1(std::string description, DefaultIO* io,
                   Context* context) : Command(description, io, context) {
}
void Command1::execute() {
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
            //read to accept message received
            this->io->read();
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
//private functions
void Command1::saveDataToClassify(std::string data, std::vector<std::vector<double>>* toClassify) {
    StringExtractor stringExtractor(data,'\r');
    while(stringExtractor.hasNext()){
        std::string  temp = stringExtractor.getData();
        std::replace(temp.begin(),temp.end(), ',', ' ');
        if(checkVector(temp)){
            std::stringstream stringstream;
            stringstream.str(temp);
            double value;
            std::vector<double> values;
            while(stringstream >> value)
            {
                values.push_back(value);
                //remove the ',' from the string
                char buffer[1];
                stringstream.read(buffer, 1);
                //if next char is not a number or a point, break
                int nextChar = stringstream.peek();
                if((nextChar < 48 || nextChar > 57) && nextChar != 46) {
                    break;
                }
            }
            toClassify->push_back(values);
        }
    }
}
bool Command1::upload(std::string message){
    this->io->write(message);
    //get data from io
    std::string data = this->io->read();
    if(COMMAND1_DEBUG){
        std::cout << "file received:" << std::endl;
        std::cout << data << std::endl;
    }    

    //if the client got a wrong path, the client will send an invalid path message to the server
    if(data == INVALID_MESSAGE_PATH){
        return false;
    }
    else if(message == UPLOAD_TRAIN_CSV){
        //initialize stringExtractor to read until \n char
        StringExtractor stringExtractor(data,DELIMETER_CHAR);
        this->context->setGn(stringExtractor);
        return true;

    }
    else{
        this->context->initializeToClassify();
        saveDataToClassify(data, this->context->getToClassify());
        return true;
    }
}