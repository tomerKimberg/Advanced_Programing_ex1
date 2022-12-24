//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_CANBERRADISTANCECALCULATOR_H
#define TARGIL1_CANBERRADISTANCECALCULATOR_H
#include "DistanceCalculator.h"
#include "distance_algorithms.h"
/**
 * a DistanceCalculator object using the Canberra metric
 */
class CanberraDistanceCalculator: public DistanceCalculator{
public:
     double calculateDistance(std::vector<double> v1, std::vector<double> v2) override;
     ~CanberraDistanceCalculator();

};


#endif //TARGIL1_CANBERRADISTANCECALCULATOR_H
