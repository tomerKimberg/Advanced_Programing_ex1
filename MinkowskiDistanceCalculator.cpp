//
// Created by tomer on 07/12/2022.
//

#include "MinkowskiDistanceCalculator.h"
//constructor
MinkowskiDistanceCalculator::MinkowskiDistanceCalculator(int p): distanceCalculator(), power(p) {}
/**
 * calculate distance using Minkowski metric
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double distance
 */
double MinkowskiDistanceCalculator::calculateDistance(std::vector<double> v1, std::vector<double> v2) {
    return Minkowski_distance(v1, v2, this->power);
}

