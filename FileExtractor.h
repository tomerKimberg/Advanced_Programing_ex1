//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_FILEEXTRACTOR_H
#define TARGIL1_FILEEXTRACTOR_H
#include "DataExtractor.h"
#include <iostream>

class FileExtractor: public DataExtractor{
private:
    std::string path;
public:
    FileExtractor(std::string path);
    ~FileExtractor() override;
    std::string getPath();
    void setPath(std::string newPath);
    std::string getData() override;
    bool hasNext() override;
};


#endif //TARGIL1_FILEEXTRACTOR_H
