//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_FACTORYDISTANCECALCULATOR_H
#define TARGIL1_FACTORYDISTANCECALCULATOR_H
#include <iostream>

#include "headerDistanceCalculators.h"

class factoryDistanceCalculator {
private:
    //think about attribues needed for the factoryDistanceCalculator
public:
    // pointer to distanceCalculator
    distanceCalculator* createDistanceCalculator(std::string metric);

};

#endif //TARGIL1_FACTORYDISTANCECALCULATOR_H
