//
// Created by tomer on 17/01/2023.
//

#ifndef TARGIL1_DEFAULTIO_H
#define TARGIL1_DEFAULTIO_H

#include <string>
#include "../Extractors/DataExtractor.h"

class DefaultIO {
private:
    DataExtractor* extractor;
public:
    DefaultIO();
    DataExtractor* getDataExtractor();
    virtual std::string read() = 0;
    virtual void write(std::string) = 0;
};


#endif //TARGIL1_DEFAULTIO_H
