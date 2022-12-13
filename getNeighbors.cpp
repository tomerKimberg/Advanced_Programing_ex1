//
// Created by tomer on 07/12/2022.
//
#include <vector>
#include <sstream>
#include "getNeighbors.h"

getNeighbors::getNeighbors(DataExtractor *de){
    this->dataExtractor = nullptr;
    this->setDataExtractor(de);
}
void getNeighbors::setDataExtractor(DataExtractor *de) {
    //keep in case we will change implementation-
    //using this method, the pointer is dependent on the life scope of &de.
    //this->dataExtractor = &de;
    delete this->dataExtractor;
    this->dataExtractor = de->copy();
}

getNeighbors::~getNeighbors() {
    //if setDataExtractor() changes, change this as well
    delete this->dataExtractor;
}
//implement
std::map<std::vector<double>, std::vector<std::string>> getMapFromVectorString(std::string vectorString) {
    std::stringstream stringstream;
    stringstream.str(vectorString);
    double value;
    std::vector<double> values;
    while(stringstream >> value)
    {
        values.push_back(value);
        //remove the ',' from the string
        char buffer[1];
        stringstream.read(buffer, 1);
        //if next char is not a number or a point, break
        int nextChar = stringstream.peek();
        if((nextChar < 48 || nextChar > 57) && nextChar != 46) {
            break;
        }
    }
    std::string calssification;
    std::vector<std::string> classifications;
    while(stringstream >> calssification)
    {
        classifications.push_back(calssification);
        //remove the ',' from the string
        char comma[1];
        stringstream.read(comma, 1);
    }
    std::map<std::vector<double>, std::vector<std::string>> tempMap;
    tempMap.insert({values, classifications});
    return tempMap;
}

std::map<std::vector<double>, std::vector<std::string>> getNeighbors::getNeighborsInMap() {
    //implementation for debug
    std::map<std::vector<double>, std::vector<std::string>> neighbors;
    while(this->dataExtractor->hasNext()) {
        std::string vectorString = dataExtractor->getData();
        std::map<std::vector<double>, std::vector<std::string>> tempMap = getMapFromVectorString(vectorString);
        for (auto const& x : tempMap)
        {
            neighbors.insert({x.first, x.second});
        }
        
    }
    return neighbors;
}

