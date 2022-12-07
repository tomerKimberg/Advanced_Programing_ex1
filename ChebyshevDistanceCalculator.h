//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_CHEBYSHEVDISTANCECALCULATOR_H
#define TARGIL1_CHEBYSHEVDISTANCECALCULATOR_H
#include "distanceCalculator.h"
/**
 * a distanceCalculator object using the Chebyshev metric
 */
class ChebyshevDistanceCalculator: public distanceCalculator {
public:
    double calculateDistance(std::vector<double> v1, std::vector<double> v2) override;
    //~CanberraDistanceCalculator();
};


#endif //TARGIL1_CHEBYSHEVDISTANCECALCULATOR_H
