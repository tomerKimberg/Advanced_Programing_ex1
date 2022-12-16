//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_FACTORYDISTANCECALCULATOR_H
#define TARGIL1_FACTORYDISTANCECALCULATOR_H
#include <iostream>

#include "headerDistanceCalculators.h"

#define CANBERRA_METRIC_SYMBOL "CAN"
#define CHEBYSHEV_METRIC_SYMBOL "CHB"
#define EUCLIDEAN_METRIC_SYMBOL "AUC"
#define MANHATTAN_METRIC_SYMBOL "MAN"
#define MINKOWSKI_METRIC_SYMBOL "MIN"

class factoryDistanceCalculator {
private:
    //think about attribues needed for the factoryDistanceCalculator
public:
    // pointer to distanceCalculator
    DistanceCalculator* createDistanceCalculator(std::string metric);

};

#endif //TARGIL1_FACTORYDISTANCECALCULATOR_H
