
#ifndef TARGIL1_MANHATTANDISTANCECALCULATOR_H
#define TARGIL1_MANHATTANDISTANCECALCULATOR_H
#include "distanceCalculator.h"

class ManhattanDistanceCalculator: public distanceCalculator {
public:
    double calculateDistance(std::vector<double> v1, std::vector<double> v2) override;
    //~CanberraDistanceCalculator();

};



#endif //TARGIL1_MANHATTANDISTANCECALCULATOR_H
