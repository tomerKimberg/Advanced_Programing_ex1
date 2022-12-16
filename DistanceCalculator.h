#ifndef TARGIL1_DISTANCECALCULATOR_H
#define TARGIL1_DISTANCECALCULATOR_H

#include <iostream>
#include <vector>
#include "distance_algorithms.h"
/*
 * abstract class used to calculate distances between vectors using a  specific metric
 */
class DistanceCalculator {
public:
    virtual ~DistanceCalculator() = 0;
    /**
     * pure virtual function, to calculate distances between vectors using a  specific metric
     * @param v1 vector<double>
     * @param v2 vector<double>
     * @return double distance
     */
    virtual double calculateDistance(std::vector<double> v1, std::vector<double> v2) = 0;


};


#endif //TARGIL1_DISTANCECALCULATOR_H
