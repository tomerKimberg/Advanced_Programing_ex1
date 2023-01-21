//
// Created by tomer on 20/01/2023.
//

#ifndef TARGIL1_COMMAND3_H
#define TARGIL1_COMMAND3_H
#include "Command.h"

class Command3 : public Command{
private:
    /**
     * check needed requirement to run knn algorithm
     * @return bool
     */
    bool checkRequirement(){
        if(this->context->getGn()){
            return true;
        }
        return false;
    }
    /**
     * run the knn algorithm for all vectors to classify
     * @return true if there where no vectors without classification
     */
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
    /**
     * classify a vector
     * @param num int the number of the current vector
     * @param v1 vector<double>
     * @return true if a classification was given
     */
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
