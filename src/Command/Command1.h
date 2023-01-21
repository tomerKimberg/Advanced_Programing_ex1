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
#define COMMAND1_DEBUG false

class Command1: public Command{

private:
    /**
     * save to server the toClassify data
     * @param data std::string. data sent to server
     * @param toClassify vector<vector<double>>, save data to this
     */
    void getToClassify(std::string data, std::vector<std::vector<double>>* toClassify) {
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
    /**
     * upload csv file to the server
     * @param message std::string, the data sent to server
     * @return true- success uploading, else the path was invalid, false
     */
    bool upload(std::string message){
        this->io->write(message);
        //get data from io
        std::string data = this->io->read();

        //if the client got a wrong path, the client will send an invalid path message to the server
        if(data == "invalid path"){
            return false;
        }

        else if(message == UPLOAD_TRAIN_CSV){
            //only for debug!!!
            if(COMMAND1_DEBUG) {

                FileExtractor fileExtractor(data);
                data = "";
                while (fileExtractor.hasNext()) {
                    data += fileExtractor.getData();
                }
            }
            //initialize stringExtractor to read until \r char
            StringExtractor stringExtractor(data,'\r');
            this->context->setGn(stringExtractor);

            return true;

        }
        else{
            //only for debug!!!
            if(COMMAND1_DEBUG) {

                FileExtractor fileExtractor(data);
                data = "";
                while (fileExtractor.hasNext()) {
                    data += fileExtractor.getData();
                }
            }

            this->context->initializeToClassify();
            getToClassify(data, this->context->getToClassify());

            return true;

        }
    }

public:

    Command1(std::string description, DefaultIO* io, Context* context);

    void execute();

};


#endif //TARGIL1_COMMAND1_H
