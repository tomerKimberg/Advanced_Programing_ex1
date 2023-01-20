//
// Created by tomer on 20/01/2023.
//

#ifndef TARGIL1_COMMAND3_H
#define TARGIL1_COMMAND3_H
#include "Command.h"

class Command3 : public Command{
private:
    bool checkRequirement(){
        if(this->context->getGn()){
            return true;
        }
        return false;
    }
    bool runKnn(){
        int num = 1;
        this->context->initializeResult();
        for(std::vector<double> temp : *this->context->getToClassify()){
          if(this->classify(num,temp)) {
              num += 1;
          }
          else{
              this->context->initializeResult();
              return false;
          }
        }
        return true;
    }
    bool classify(int num, std::vector<double> v1){
        std::string classified = this->context->getKnn()->getClassification(v1);
        if(classified != "invalid input"){
            this->context->updateResult(num, classified);
            return true;
        }
        return false;

    }

public:
    Command3(std::string description, DefaultIO *io, Context *context);
    void execute() override;
};


#endif //TARGIL1_COMMAND3_H
