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
    /**
     * check requirement to run knn algorithm
     * @return bool
     */
    bool checkRequirement();
    /**
     * check if results already exists
     * @return
     */
    bool checkResult();
    /**
     * create string of result to send
     * @return std::string
     */
    std::string sendResults();
}; 

#endif //TARGIL1_COMMAND4_H
