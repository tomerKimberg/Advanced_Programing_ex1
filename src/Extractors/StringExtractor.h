//
// Created by tomer on 19/01/2023.
//

#ifndef TARGIL1_STRINGEXTRACTOR_H
#define TARGIL1_STRINGEXTRACTOR_H

#include <sstream>
#include "DataExtractor.h"

class StringExtractor : public DataExtractor{
private:
    long index0;
    long size;
    std::string backup;
    std::stringstream data;
    char delim;
    bool next;

public:
    StringExtractor(std::string data, char delim);

    ~StringExtractor() override;

    DataExtractor *copy() override;

    std::string getData() override;

    bool fail() override;

    bool hasNext() override;
};


#endif //TARGIL1_STRINGEXTRACTOR_H
