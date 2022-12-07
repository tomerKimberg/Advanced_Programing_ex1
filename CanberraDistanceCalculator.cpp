//
// Created by tomer on 07/12/2022.
//

#include "CanberraDistanceCalculator.h"
//CanberraDistanceCalculator::~CanberraDistanceCalculator(){}

double CanberraDistanceCalculator::calculateDistance(std::vector<double> v1, std::vector<double> v2){
    return Canberra_distance(v1, v2);
}
