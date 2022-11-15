#ifndef TARGIL1_DISTANCE_ALGORITHMS_H
#define TARGIL1_DISTANCE_ALGORITHMS_H

#include <iostream>
#include <vector>
#include "vector_functions.h"

double Canberra_distance(const std::vector<double> v1, const std::vector<double> v2);
double Manhattan_distance(const std::vector<double> v1, const std::vector<double> v2);

#endif //TARGIL1_DISTANCE_ALGORITHMS_H
