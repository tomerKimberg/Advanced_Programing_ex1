//
// Created by tomer on 19/01/2023.
//

#ifndef TARGIL1_STANDARTIO_H
#define TARGIL1_STANDARTIO_H


#include "DefaultIO.h"

class StandartIO : public DefaultIO{
public:
    std::string read() override;

    void write(std::string string) override;

    StandartIO();
};


#endif //TARGIL1_STANDARTIO_H
