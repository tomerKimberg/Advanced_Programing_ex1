//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_GETNEIGHBORS_H
#define TARGIL1_GETNEIGHBORS_H
#include "headerDataExtractors.h"
#include <map>
#include <vector>

class getNeighbors {
private:
    DataExtractor* dataExtractor;
public:
    getNeighbors(DataExtractor* de);
    void setDataExtractor(DataExtractor* de);
    ~getNeighbors();
    std::map<std::vector<double>,std::vector<std::string>> getNeighborsInMap();

};


#endif //TARGIL1_GETNEIGHBORS_H
