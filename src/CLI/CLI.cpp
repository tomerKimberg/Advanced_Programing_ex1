//
// Created by tomer on 20/01/2023.
//
#include "CLI.h"
#include "../Command/Command1.h"
#include "../Command/Command3.h"
#include "../Command/Command2.h"
#include "../Command/Command4.h"

CLI::CLI(DefaultIO* io) {
    this->defaultIo = io;
    this->commands.push_back(new Command1("1. upload an unclassified csv data file\n", io ,&this->context ));
    this->commands.push_back(new Command2("2. algorithm settings\n", io ,&this->context ));
    this->commands.push_back(new Command3("3. classify data\n", io ,&this->context ));
    this->commands.push_back(new Command4("4. display results\n", io ,&this->context ));
    this->createMenu();


}
CLI::~CLI() {
    for(Command* c : this->commands){
        delete c;
    }
}

void CLI::start() {
    bool run = true;
    while(run) {
        this->defaultIo->write(this->menu);
        std::string instruction = this->defaultIo->read();
        if (this->validateInstuction(instruction)) {
            run = this->goToCommand(std::stoi(instruction));
        }else {
            this->defaultIo->write("invalid option, try again\n");
        }
    }
    this->defaultIo->closeIO();
}

void CLI::createMenu(){
    this->menu += "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for(Command* c : this->commands){
        this->menu += c->getDescription();
    }
    this->menu += "8. exit\n";
}
bool CLI::validateInstuction(std::string instruction){
    if(std::isdigit(instruction[0]) && instruction.size() == 1){
        int temp = std::stoi(instruction);
        if(1<=temp && temp <=5 || temp == 8){
            return true;
        }
    }
    return false;
}
bool CLI::goToCommand(int commandNum){
    if(commandNum == 8){
        return false;
    }
    else{
        this->commands.at(commandNum-1)->execute();
    }
    return true;
}
