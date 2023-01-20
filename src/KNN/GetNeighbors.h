//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_GETNEIGHBORS_H
#define TARGIL1_GETNEIGHBORS_H
#include "../Extractors/headerDataExtractors.h"
#include <map>
#include <vector>

class GetNeighbors {
private:
    DataExtractor* dataExtractor;
public:
    GetNeighbors(DataExtractor* de);
    GetNeighbors& operator=(const GetNeighbors& g){
        this->dataExtractor  = g.dataExtractor->copy();
        return *this;
    }
    void setDataExtractor(DataExtractor* de);

    DataExtractor *getDataExtractor() const;

    ~GetNeighbors();
    std::map<std::vector<double>,std::vector<std::string>> getNeighborsInMap();

};


#endif //TARGIL1_GETNEIGHBORS_H
