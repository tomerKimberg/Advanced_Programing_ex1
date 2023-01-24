//
// Created by tomer on 19/01/2023.
//

#include <sstream>
#include "Command2.h"
#include "../CommunicationProtocol.h"
#include "../ValidationFuncs/vector_validation.h"

#define COMMAND_2_DEBUG 0

Command2::Command2(std::string description, DefaultIO *io, Context *context) : Command(description, io, context) {
    this->kBackup = *(this->context->getK());
    this->metricBackUp = this->context->getMetric();
}

void Command2::execute() {
    std::string currentKAndMetric = "The current KNN parameters are: K = " + std::to_string(this->kBackup) +
            ", distance metric = " + this->metricBackUp + "\n";
    this->io->write(currentKAndMetric);
    //expect to get number and metric
    std::string response = this->io->read();
    if(COMMAND_2_DEBUG){
        std::cout << "response from client is: " << response << std::endl;
    }
    if(COMMUNICATION_MESSAGE_RECEIVED == response){
        return;
    }
    std::stringstream ss(response);
    bool valid  = true;

    int kTemp;
    std::string metricTemp;
    std::string kString;
    std::string errors = "";
    ss >> kString;
    ss >> metricTemp;

    if(COMMAND_2_DEBUG){
        std::cout << "kString is: " << kString << " metricTemp is: " << metricTemp << std::endl;
    }
    int len = kString.size();
    for(int i = 0 ; i < len; i++){
        if(!std::isdigit(kString[i])) {
            errors += INVALID_MESSAGE_VALUE_K;
            valid = false;
            break;
        }
    }
    if(valid){
        kTemp  = stoi(kString);
    }


    if(!checkMetric(metricTemp)){
        errors += INVALID_MESSAGE_VALUE_METRIC;
        valid = false;
    }
    if(valid){
        //send ok message to client because the client is expecting an error message
        this->io->write(COMMUNICATION_MESSAGE_RECEIVED);
        this->context->setK(kTemp);
        this->context->setMetric(metricTemp);
        //the new parameters are different from the current ones
        if(this->kBackup != kTemp || this->metricBackUp != metricTemp){
            this->context->initializeResult();
        }
        this->kBackup = kTemp;
        this->metricBackUp = metricTemp;
    }else{
        this->io->write(errors);
    }
    //read ok message before printing menu
        this->io->read();
}