
#include "CanberraDistanceCalculator.h"
//CanberraDistanceCalculator::~CanberraDistanceCalculator(){}
/**
 * calculate distance using Canberra metric
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double distance
 */
double CanberraDistanceCalculator::calculateDistance(std::vector<double> v1, std::vector<double> v2){
    return Canberra_distance(v1, v2);
}
