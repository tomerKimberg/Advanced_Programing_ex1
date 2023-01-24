#ifndef TARGIL1_COMMAND5_H
#define TARGIL1_COMMAND5_H
#include "Command.h"

class Command5 : public Command{
private:
public:
    Command5(const std::string &description, DefaultIO *io, Context *context);

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
