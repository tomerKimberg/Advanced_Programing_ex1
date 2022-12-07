//
// Created by tomer on 07/12/2022.
//

#include "getNeighbors.h"

getNeighbors::getNeighbors(DataExtractor *de): dataExtractor(de){}
void getNeighbors::setDataExtractor(DataExtractor *de) {
    this->dataExtractor = de;
}

getNeighbors::~getNeighbors() {
    delete this->dataExtractor;
}
//implement
std::map<std::vector<double>, std::vector<std::string>> getNeighbors::getNeighborsInMap() {}