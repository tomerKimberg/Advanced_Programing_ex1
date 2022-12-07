
#include "ChebyshevDistanceCalculator.h"
/**
 * calculate distance using Chebyshev metic
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double distance
 */
double ChebyshevDistanceCalculator::calculateDistance(std::vector<double> v1, std::vector<double> v2) {
    return Chebyshev_distance(v1, v2);
}