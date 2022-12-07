//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_DATAEXTRACTOR_H
#define TARGIL1_DATAEXTRACTOR_H
#include <iostream>

class DataExtractor {
public:
    virtual ~DataExtractor() = 0;
    virtual std::string getData() = 0;
    virtual bool hasNext() = 0;
};


#endif //TARGIL1_DATAEXTRACTOR_H
