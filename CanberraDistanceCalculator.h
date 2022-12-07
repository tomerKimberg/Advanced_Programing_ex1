//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_CANBERRADISTANCECALCULATOR_H
#define TARGIL1_CANBERRADISTANCECALCULATOR_H
#include "distanceCalculator.h"
#include "distance_algorithms.h"

class CanberraDistanceCalculator: public distanceCalculator{
public:
     double calculateDistance(std::vector<double> v1, std::vector<double> v2) override;
     //~CanberraDistanceCalculator();

};


#endif //TARGIL1_CANBERRADISTANCECALCULATOR_H
