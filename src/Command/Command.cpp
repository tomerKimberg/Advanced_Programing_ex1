//
// Created by tomer on 17/01/2023.
//

#include "Command.h"

Command::Command(std::string description, DefaultIO* io, Context* context){
    this->description = description;
    this->io = io;
    this->context = context;
}
std::string Command::getDescription(){
    return this->description;
}