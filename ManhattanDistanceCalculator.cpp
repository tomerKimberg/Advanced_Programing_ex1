//
// Created by tomer on 07/12/2022.
//

#include "ManhattanDistanceCalculator.h"
/**
 * calculate distance using Manhattan metric
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double distance
 */
double ManhattanDistanceCalculator::calculateDistance(std::vector<double> v1, std::vector<double> v2){
    return Manhattan_distance(v1, v2);
}