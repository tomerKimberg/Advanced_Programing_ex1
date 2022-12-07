//
// Created by tomer on 07/12/2022.
//

#include "getNeighbors.h"

getNeighbors::getNeighbors(DataExtractor &de){
    this->setDataExtractor(de);
}
void getNeighbors::setDataExtractor(DataExtractor &de) {
    this->dataExtractor = &de;

}

getNeighbors::~getNeighbors() {}
//implement
std::map<std::vector<double>, std::vector<std::string>> getNeighbors::getNeighborsInMap() {

    //implementation for debug
    std::map<std::vector<double>, std::vector<std::string>> neighbors;
    std::string s = this->dataExtractor->getData();
    std::vector<double> vector = {1,2,3};
    std::vector<std::string> vector1 = {s};
    neighbors.insert({vector,vector1});
    return neighbors;
}