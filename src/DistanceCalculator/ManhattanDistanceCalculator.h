
#ifndef TARGIL1_MANHATTANDISTANCECALCULATOR_H
#define TARGIL1_MANHATTANDISTANCECALCULATOR_H
#include "DistanceCalculator.h"
/**
 * a DistanceCalculator object using the Manhattan metric
 */
class ManhattanDistanceCalculator: public DistanceCalculator {
public:
    double calculateDistance(std::vector<double> v1, std::vector<double> v2) override;
    ~ManhattanDistanceCalculator() override;

};



#endif //TARGIL1_MANHATTANDISTANCECALCULATOR_H
