#ifndef TARGIL1_DISTANCECALCULATOR_H
#define TARGIL1_DISTANCECALCULATOR_H

#include <iostream>
#include <vector>
#include "distanceCalculator.h"
#include "distance_algorithms.h"
/*
#include "MinkowskiDistanceCalculator.h"
#include "CanberraDistanceCalculator.h"
#include "ManhattanDistanceCalculator.h"
#include "EuclideanDistanceCalculator.h"
*/
class distanceCalculator {
public:
    virtual double calculateDistance(std::vector<double> v1, std::vector<double> v2) = 0;
    //virtual ~distanceCalculator();
};


#endif //TARGIL1_DISTANCECALCULATOR_H
