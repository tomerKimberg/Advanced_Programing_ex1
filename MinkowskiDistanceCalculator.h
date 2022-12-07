//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_MINKOWSKIDISTANCECALCULATOR_H
#define TARGIL1_MINKOWSKIDISTANCECALCULATOR_H
#include "distanceCalculator.h"
/**
 * a distanceCalculator object using the Minkowski metric
 */
class MinkowskiDistanceCalculator: public distanceCalculator {
private:
    int power;
public:
    MinkowskiDistanceCalculator(int p);
    double calculateDistance(std::vector<double> v1, std::vector<double> v2) override;
    //~CanberraDistanceCalculator();

};


#endif //TARGIL1_MINKOWSKIDISTANCECALCULATOR_H
