//
// Created by tomer on 20/01/2023.
//

#ifndef TARGIL1_COMMAND4_H
#define TARGIL1_COMMAND4_H
#include "Command.h"

class Command4 : public Command{
private:
public:
    Command4(const std::string &description, DefaultIO *io, Context *context);

    void execute() override;

private:
    bool checkRequirement(){
        if(this->context->getGn()){
            return true;
        }
        return false;
    }
    bool checkResult(){
        if(this->context->getResult()) {
            if (!this->context->getResult()->empty()) {
                return true;
            }
        }
        return false;
    }
    std::string sendResults(){
        std::string result;
        for(std::pair<int,std::string> temp : *this->context->getResult()){
            result += std::to_string(temp.first);
            result += '\t';
            result += temp.second;
            result += '\n';
        }
        return result;
    }
};


#endif //TARGIL1_COMMAND4_H
