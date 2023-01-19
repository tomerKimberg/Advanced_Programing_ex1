//
// Created by tomer on 19/01/2023.
//

#ifndef TARGIL1_STANDARDIO_H
#define TARGIL1_STANDARDIO_H


#include "DefaultIO.h"

class StandardIO : public DefaultIO{
public:
    std::string read() override;

    void write(std::string string) override;

    StandardIO();
};


#endif //TARGIL1_STANDARDIO_H
