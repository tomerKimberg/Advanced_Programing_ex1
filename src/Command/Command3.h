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
    bool checkRequirement();
    /**
     * run the knn algorithm for all vectors to classify
     * @return true if there where no vectors without classification
     */
    bool runKnn();
    /**
     * classify a vector
     * @param num int the number of the current vector
     * @param v1 vector<double>
     * @return true if a classification was given
     */
    bool classify(int num, std::vector<double> v1);

public:
    Command3(std::string description, DefaultIO *io, Context *context);
    void execute() override;
};


#endif //TARGIL1_COMMAND3_H
