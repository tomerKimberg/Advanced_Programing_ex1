//
// Created by tomer on 19/01/2023.
//

#include <sstream>
#include "Command2.h"
#define DEBUG true
#include "../ValidationFuncs/vector_validation.h"
Command2::Command2(std::string description, DefaultIO *io, Context *context) : Command(description, io, context) {
    this->kBackup = *(this->context->getK());
    this->metricBackUp = this->context->getMetric();
}

void Command2::execute() {
    std::string message = "The current KNN parameters are: K = " + std::to_string(this->kBackup) +
            ", distance metric = " + this->metricBackUp + "\n";
    this->io->write(message);
    //expect to get number and metric
    std::stringstream ss(this->io->read());
    bool valid  = true;

    int kTemp;
    std::string metricTemp;
    std::string kString;
    ss >> kString;
    ss >> metricTemp;

    int len = kString.size();
    if(len == 0){
        return;
    }
    for(int i = 0 ; i < len; i++){
        if(!std::isdigit(kString[i])) {
            this->io->write("invalid value for K\n");
            valid = false;
            break;
        }
    }
    if(valid){
        kTemp  = stoi(kString);
    }


    if(!checkMetric(metricTemp)){
        this->io->write("invalid value for metric\n");
        valid = false;
    }
    if(valid){
        this->context->setK(kTemp);
        this->context->setMetric(metricTemp);
        //the new parameters are different from the current ones
        if(this->kBackup != kTemp || this->metricBackUp != metricTemp){
            this->context->initializeResult();
        }
        this->kBackup = kTemp;
        this->metricBackUp = metricTemp;


    }
}