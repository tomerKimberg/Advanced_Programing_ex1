//
// Created by tomer on 19/01/2023.
//

#ifndef TARGIL1_COMMAND1_H
#define TARGIL1_COMMAND1_H
#include "Command.h"
#include "../Extractors/StringExtractor.h"
#include "../ValidationFuncs/user_input.h"
#define UPLOAD_TRAIN_CSV  "Please upload your local train CSV file.\n"
#define UPLOAD_TEST_CSV  "Please upload your local test CSV file.\n"

class Command1: public Command{

private:
    std::vector<std::vector<double>>* getToClassify(std::string data) {
        StringExtractor stringExtractor(data);
        std::vector<std::vector<double>>* toClassify = new std::vector<std::vector<double>>;
        while(stringExtractor.hasNext()){
            std::string  temp = stringExtractor.getData();
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
        return toClassify;

    }
    bool upload(std::string message){
        this->io->write(message);
        std::string data  = this->io->read();
        if(data == "invalid Path"){
            return false;
        }
        else if( message == UPLOAD_TRAIN_CSV){
            StringExtractor stringExtractor(data);
            this->context->setGn(stringExtractor);
            return true;

        }
        else{


            this->context->setToClassify(this->getToClassify(data));
            return true;

        }
        }

public:

    Command1(std::string description, DefaultIO* io, Context* context);

    void execute();

};


#endif //TARGIL1_COMMAND1_H
