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
    void getToClassify(std::string data, std::vector<std::vector<double>>* toClassify);    /**
     * upload csv file to the server
     * @param message std::string, the data sent to server
     * @return true- success uploading, else the path was invalid, false
     */
    bool upload(std::string message);

public:

    Command1(std::string description, DefaultIO* io, Context* context);

    void execute();

};


#endif //TARGIL1_COMMAND1_H
