
#include "EuclideanDistanceCalculator.h"
/**
 * calculate distance using Euclidean metric
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double distance
 */
double EuclideanDistanceCalculator::calculateDistance(std::vector<double> v1, std::vector<double> v2) {
    return Euclidean_distance(v1, v2);
}