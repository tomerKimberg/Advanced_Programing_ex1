//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_FILEEXTRACTOR_H
#define TARGIL1_FILEEXTRACTOR_H
#include "DataExtractor.h"
#include <iostream>
#include <fstream>

class FileExtractor: public DataExtractor{
private:
    std::string path;
    std::ifstream fileStream;
public:
    FileExtractor(std::string path);
    ~FileExtractor() override;
    DataExtractor* copy();
    std::string getPath();
    void setPath(std::string newPath);
    std::string getData() override;
    bool hasNext() override;
    bool fail() override;
};


#endif //TARGIL1_FILEEXTRACTOR_H
