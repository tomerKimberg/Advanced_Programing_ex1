//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_CHEBYSHEVDISTANCECALCULATOR_H
#define TARGIL1_CHEBYSHEVDISTANCECALCULATOR_H
#include "DistanceCalculator.h"
/**
 * a DistanceCalculator object using the Chebyshev metric
 */
class ChebyshevDistanceCalculator: public DistanceCalculator {
public:
    double calculateDistance(std::vector<double> v1, std::vector<double> v2) override;
    ~ChebyshevDistanceCalculator();
};


#endif //TARGIL1_CHEBYSHEVDISTANCECALCULATOR_H
