//
// Created by tomer on 17/01/2023.
//

#ifndef TARGIL1_DEFAULTIO_H
#define TARGIL1_DEFAULTIO_H

#include <string>

class DefaultIO {
public:
    virtual std::string read() = 0;
    virtual void write(std::string) = 0;
    virtual int closeIO() = 0;
};


#endif //TARGIL1_DEFAULTIO_H
