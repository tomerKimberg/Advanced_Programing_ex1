//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_MINKOWSKIDISTANCECALCULATOR_H
#define TARGIL1_MINKOWSKIDISTANCECALCULATOR_H
#include "distanceCalculator.h"

#define DEFAULT_MINKOWSKI_POWER 2
/**
 * a distanceCalculator object using the Minkowski metric
 */
class MinkowskiDistanceCalculator: public distanceCalculator {
private:
    int power;
public:
    MinkowskiDistanceCalculator(int p = DEFAULT_MINKOWSKI_POWER);
    double calculateDistance(std::vector<double> v1, std::vector<double> v2) override;
    ~MinkowskiDistanceCalculator();

};


#endif //TARGIL1_MINKOWSKIDISTANCECALCULATOR_H
