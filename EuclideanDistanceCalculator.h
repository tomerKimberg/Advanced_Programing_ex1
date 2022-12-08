//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_EUCLIDEANDISTANCECALCULATOR_H
#define TARGIL1_EUCLIDEANDISTANCECALCULATOR_H
#include "distanceCalculator.h"
/**
 * a distanceCalculator object using the Euclidean metric
 */
class EuclideanDistanceCalculator: public distanceCalculator{
public:
    double calculateDistance(std::vector<double> v1, std::vector<double> v2) override;
    ~EuclideanDistanceCalculator();

};


#endif //TARGIL1_EUCLIDEANDISTANCECALCULATOR_H
